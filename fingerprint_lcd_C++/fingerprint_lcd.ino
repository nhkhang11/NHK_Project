#include <Adafruit_Fingerprint.h>
#include <SoftwareSerial.h>
#include <LiquidCrystal_I2C.h>
#include <Keypad.h>

// LCD initialization
LiquidCrystal_I2C lcd(0x27, 16, 2);

// Software Serial for fingerprint sensor
SoftwareSerial fingerPrint(2, 3);

// Define constants for pins
#define Door_Open 12
#define Door_Close 13
#define RELAY_PIN 6

// Keypad configuration
const byte ROWS = 4; // Four rows
const byte COLS = 4; // Four columns
char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

byte rowPins[ROWS] = {11, 10, 9, 8}; // Connect to the row pinouts of the keypad
byte colPins[COLS] = {7, 6, 5, 4};   // Connect to the column pinouts of the keypad

Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

uint8_t id;
Adafruit_Fingerprint finger = Adafruit_Fingerprint(&fingerPrint);

const String adminPassword = "1234";
String enteredPassword = "";

void setup()
{
  // Initialize pins
  pinMode(RELAY_PIN, OUTPUT);
  digitalWrite(RELAY_PIN, LOW); // Initially, relay is off
  pinMode(Door_Open, OUTPUT);
  pinMode(Door_Close, OUTPUT);

  // Initialize LCD
  lcd.init();
  lcd.backlight();
  lcd.print("Fingerprint");
  lcd.setCursor(0, 1);
  lcd.print("Security System");
  delay(2000);
  lcd.clear();

  Serial.begin(9600);
  finger.begin(57600);

  lcd.clear();
  lcd.print("Finding Module");
  lcd.setCursor(0, 1);
  delay(1000);

  if (finger.verifyPassword())
  {
    Serial.println("Found fingerprint sensor!");
    lcd.clear();
    lcd.print("Found Module ");
    delay(1000);
  }
  else
  {
    Serial.println("Did not find fingerprint sensor :(");
    lcd.clear();
    lcd.print("module not Found");
    lcd.setCursor(0, 1);
    lcd.print("Check Connections");
    while (1);
  }
}

void loop()
{
  lcd.setCursor(0, 0);
  lcd.print("Press A/B/C/D");
  lcd.setCursor(0, 1);
  lcd.print("for Actions");

  digitalWrite(Door_Close, HIGH);

  char key = keypad.getKey();
  if (key)
  {
    switch (key)
    {
      case 'A':
        verifyAdminPassword(enrollFingerprint);
        break;
      case 'B':
        verifyAdminPassword(deleteFingerprint);
        break;
      case 'C':
        changeLocation();
        break;
      case 'D':
        unlockDoor();
        break;
      default:
        break;
    }
  }

  delay(1000);
}

void verifyAdminPassword(void (*action)())
{
  lcd.clear();
  lcd.print("Enter Admin");
  lcd.setCursor(0, 1);
  lcd.print("Password:");

  enteredPassword = "";

  while (enteredPassword.length() < 4)
  {
    char key = keypad.getKey();
    if (key)
    {
      enteredPassword += key;
      lcd.setCursor(12, 1);
      lcd.print(enteredPassword);
    }
  }

  if (enteredPassword == adminPassword)
  {
    action();
  }
  else
  {
    lcd.clear();
    lcd.print("Wrong Password");
    delay(2000);
  }
}

void enrollFingerprint()
{
  int count = 0;
  lcd.clear();
  lcd.print("Enroll Finger    ");
  lcd.setCursor(0, 1);
  lcd.print("Location:");
  while (1)
  {
    lcd.setCursor(9, 1);
    lcd.print(count);
    char key = keypad.getKey();
    if (key == 'C')
    {
      count++;
      if (count > 25)
        count = 0;
      delay(500);
    }
    else if (key == 'D')
    {
      count--;
      if (count < 0)
        count = 25;
      delay(500);
    }
    else if (key == 'A')
    {
      id = count;
      getFingerprintEnroll();
      return;
    }
    else if (key == 'B')
    {
      return;
    }
  }
}

void deleteFingerprint()
{
  int count = 0;
  lcd.clear();
  lcd.print("Delete Finger    ");
  lcd.setCursor(0, 1);
  lcd.print("Location:");

  while (1)
  {
    lcd.setCursor(9, 1);
    lcd.print(count);
    char key = keypad.getKey();
    if (key == 'C')
    {
      count++;
      if (count > 25)
        count = 0;
      delay(500);
    }
    else if (key == 'D')
    {
      count--;
      if (count < 0)
        count = 25;
      delay(500);
    }
    else if (key == 'A')
    {
      id = count;
      deleteFingerprint(id);
      return;
    }
    else if (key == 'B')
    {
      return;
    }
  }
}

void changeLocation()
{
  lcd.clear();
  lcd.print("Change Location");
  delay(2000);
}

void unlockDoor()
{
  for (int i = 0; i < 5; i++)
  {
    lcd.clear();
    lcd.print("Place Finger");
    delay(2000);
    int result = getFingerprintIDez();
    if (result >= 0)
    {
      digitalWrite(Door_Open, HIGH);
      digitalWrite(Door_Close, LOW);

      lcd.clear();
      lcd.print("Allowed");
      lcd.setCursor(0, 1);
      lcd.print("Gate Opened");

      digitalWrite(RELAY_PIN, HIGH);
      delay(5000);
      digitalWrite(RELAY_PIN, LOW);
      digitalWrite(Door_Close, HIGH);
      digitalWrite(Door_Open, LOW);

      lcd.setCursor(0, 1);
      lcd.print("Gate Closed");

      return;
    }
  }
}

uint8_t getFingerprintEnroll()
{
  int p = -1;
  lcd.clear();
  lcd.print("finger ID:");
  lcd.print(id);
  lcd.setCursor(0, 1);
  lcd.print("Place Finger");
  delay(2000);

  while (p != FINGERPRINT_OK)
  {
    p = finger.getImage();
    switch (p)
    {
      case FINGERPRINT_OK:
        Serial.println("Image taken");
        lcd.clear();
        lcd.print("Image taken");
        break;
      case FINGERPRINT_NOFINGER:
        Serial.println("No Finger");
        lcd.clear();
        lcd.print("No Finger");
        break;
      case FINGERPRINT_PACKETRECIEVEERR:
        Serial.println("Communication error");
        lcd.clear();
        lcd.print("Comm Error");
        break;
      case FINGERPRINT_IMAGEFAIL:
        Serial.println("Imaging error");
        lcd.clear();
        lcd.print("Imaging Error");
        break;
      default:
        Serial.println("Unknown error");
        lcd.clear();
        lcd.print("Unknown Error");
        break;
    }
  }

  p = finger.image2Tz(1);
  switch (p)
  {
    case FINGERPRINT_OK:
      Serial.println("Image converted");
      lcd.clear();
      lcd.print("Image converted");
      break;
    case FINGERPRINT_IMAGEMESS:
      Serial.println("Image too messy");
      lcd.clear();
      lcd.print("Image too messy");
      return p;
    case FINGERPRINT_PACKETRECIEVEERR:
      Serial.println("Communication error");
      lcd.clear();
      lcd.print("Comm Error");
      return p;
    case FINGERPRINT_FEATUREFAIL:
      Serial.println("Could not find fingerprint features");
      lcd.clear();
      lcd.print("Feature Not Found");
      return p;
    case FINGERPRINT_INVALIDIMAGE:
      Serial.println("Could not find fingerprint features");
      lcd.clear();
      lcd.print("Feature Not Found");
      return p;
    default:
      Serial.println("Unknown error");
      lcd.clear();
      lcd.print("Unknown Error");
      return p;
  }

  Serial.println("Remove finger");
  lcd.clear();
  lcd.print("Remove Finger");
  delay(2000);
  p = 0;

  while (p != FINGERPRINT_NOFINGER)
  {
    p = finger.getImage();
  }

  Serial.print("ID "); Serial.println(id);
  p = -1;
  Serial.println("Place same finger again");
  lcd.clear();
  lcd.print("Place Finger");
  lcd.setCursor(0, 1);
  lcd.print("   Again");

  while (p != FINGERPRINT_OK)
  {
    p = finger.getImage();
    switch (p)
    {
      case FINGERPRINT_OK:
        Serial.println("Image taken");
        break;
      case FINGERPRINT_NOFINGER:
        Serial.print(".");
        break;
      case FINGERPRINT_PACKETRECIEVEERR:
        Serial.println("Communication error");
        break;
      case FINGERPRINT_IMAGEFAIL:
        Serial.println("Imaging error");
        break;
      default:
        Serial.println("Unknown error");
        return;
    }
  }

  p = finger.image2Tz(2);

  switch (p)
  {
    case FINGERPRINT_OK:
      Serial.println("Image converted");
      break;
    case FINGERPRINT_IMAGEMESS:
      Serial.println("Image too messy");
      return p;
    case FINGERPRINT_PACKETRECIEVEERR:
      Serial.println("Communication error");
      return p;
    case FINGERPRINT_FEATUREFAIL:
      Serial.println("Could not find fingerprint features");
      return p;
    case FINGERPRINT_INVALIDIMAGE:
      Serial.println("Could not find fingerprint features");
      return p;
    default:
      Serial.println("Unknown error");
      return p;
  }

  Serial.print("Creating model for #");  Serial.println(id);

  p = finger.createModel();
  if (p == FINGERPRINT_OK)
  {
    Serial.println("Prints matched!");
  }
  else if (p == FINGERPRINT_PACKETRECIEVEERR)
  {
    Serial.println("Communication error");
    return p;
  }
  else if (p == FINGERPRINT_ENROLLMISMATCH)
  {
    Serial.println("Fingerprints did not match");
    return p;
  }
  else
  {
    Serial.println("Unknown error");
    return p;
  }

  Serial.print("ID "); Serial.println(id);
  p = finger.storeModel(id);
  if (p == FINGERPRINT_OK)
  {
    Serial.println("Stored!");
    lcd.clear();
    lcd.print("Stored!");
    delay(2000);
  }
  else if (p == FINGERPRINT_PACKETRECIEVEERR)
  {
    Serial.println("Communication error");
    return p;
  }
  else if (p == FINGERPRINT_BADLOCATION)
  {
    Serial.println("Could not store in that location");
    return p;
  }
  else if (p == FINGERPRINT_FLASHERR)
  {
    Serial.println("Error writing to flash");
    return p;
  }
  else
  {
    Serial.println("Unknown error");
    return p;
  }
}

int getFingerprintIDez()
{
  uint8_t p = finger.getImage();
  if (p != FINGERPRINT_OK)
    return -1;
  p = finger.image2Tz();
  if (p != FINGERPRINT_OK)
    return -1;

  p = finger.fingerFastSearch();
  if (p != FINGERPRINT_OK)
  {
    lcd.clear();
    lcd.print("Finger Not Found");
    lcd.setCursor(0, 1);
    lcd.print("Try Later");
    delay(2000);
    return -1;
  }
  // found a match!
  Serial.print("Found ID #");
  Serial.print(finger.fingerID);
  return finger.fingerID;
}

uint8_t deleteFingerprint(uint8_t id)
{
  uint8_t p = -1;
  lcd.clear();
  lcd.print("Please wait");
  p = finger.deleteModel(id);

  if (p == FINGERPRINT_OK)
  {
    Serial.println("Deleted!");
    lcd.clear();
    lcd.print("Finger Deleted");
    lcd.setCursor(0, 1);
    lcd.print("Successfully");
    delay(1000);
  }
  else
  {
    Serial.print("Something Wrong");
    lcd.clear();
    lcd.print("Something Wrong");
    lcd.setCursor(0, 1);
    lcd.print("Try Again Later");
    delay(2000);
    return p;
  }
}
