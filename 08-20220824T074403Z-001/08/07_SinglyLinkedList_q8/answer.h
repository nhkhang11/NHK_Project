#include <iostream>
#include <sstream>
using namespace std;

class LinkedList
{
public:
    class Node;

private:
    Node *head;
    Node *tail;
    int size;

public:
    class Node
    {
    private:
        int value;
        Node *next;
        friend class LinkedList;

    public:
        Node()
        {
            this->next = NULL;
        }
        Node(Node *node)
        {
            this->value = node->value;
            this->next = node->next;
        }
        Node(int value, Node *next = NULL)
        {
            this->value = value;
            this->next = next;
        }
    };
    LinkedList() : head(NULL), tail(NULL), size(0){};
    ~LinkedList()
    {
        this->clear();
    }
    void clear()
    {
        Node *curNode = this->head;
        Node *next = NULL;
        while (curNode != NULL)
        {
            next = curNode->next;
            delete curNode;
            curNode = next;
        }
    }
    void add(int value)
    {
        Node *p = new Node(value);
        if (this->size == 0)
        {
            this->head = this->tail = p;
        }
        else
        {
            this->tail->next = p;
            this->tail = p;
        }
        this->size++;
    }
    string toString()
    {
        stringstream ss;
        ss << "[";
        Node *ptr = head;
        while (ptr != tail)
        {
            ss << ptr->value << ",";
            ptr = ptr->next;
        }

        if (this->size > 0)
            ss << ptr->value << "]";
        else
            ss << "]";
        return ss.str();
    }
    void partition(int k);
};

/// BEGIN  <STUDENT ANSWER>
void LinkedList::partition(int k)
{
    // TODO
    Node *temp = this->head;
    LinkedList *llist1 = new LinkedList();
    LinkedList *llist2 = new LinkedList();
    LinkedList *llist3 = new LinkedList();

    while (temp != NULL)
    {
        if (temp->value < k)
        {
            llist1->add(temp->value);
        }
        else if (temp->value == k)
        {
            llist2->add(temp->value);
        }
        else
        {
            llist3->add(temp->value);
        }
        temp = temp->next;
    }
    LinkedList *llist0 = new LinkedList();
    temp = llist1->head;
    while (temp != NULL)
    {
        llist0->add(temp->value);
        temp = temp->next;
    }
    temp = llist2->head;
    while (temp != NULL)
    {
        llist0->add(temp->value);
        temp = temp->next;
    }
    temp = llist3->head;
    while (temp != NULL)
    {
        llist0->add(temp->value);
        temp = temp->next;
    }

    temp = head;
    Node *current = llist0->head;
    while (temp != NULL)
    {
        temp->value = current->value;
        temp = temp->next;
        current = current->next;
    }
    temp = NULL;
    current = NULL;
}
/// END  <STUDENT ANSWER>
