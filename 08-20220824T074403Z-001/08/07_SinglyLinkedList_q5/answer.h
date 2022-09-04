#include <iostream>
#include <string>
#include <cstring>
#include <climits>
#include <utility>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <functional>
#include <algorithm>
using namespace std;

class LLNode {
public:
    int val;
    LLNode* next;
    LLNode();
    LLNode(int val, LLNode* next);
    template <typename InputIterator>
    static LLNode* createWithIterators(InputIterator first, InputIterator last);
    static void printList(LLNode* head);
    static int convertNodeData(LLNode* head);
    void clear();
};

LLNode::LLNode() : val(0), next(nullptr) {}

LLNode::LLNode(int val, LLNode* next = nullptr) : val(val), next(next) {}

template <typename InputIterator>
LLNode* LLNode::createWithIterators(InputIterator first, InputIterator last) {
    LLNode* trav = nullptr;
    LLNode* head = nullptr;
    while (first != last) {
        if (trav == nullptr) {
            head = new LLNode(*first);
            trav = head;
        }
        else {
            trav->next = new LLNode(*first);
            trav = trav->next;
        }
        first = first + 1;
    }
    return head;
}

void LLNode::printList(LLNode* head) {
    cout << "[";
    LLNode* trav = head;
    while (trav != nullptr) {
        cout << trav->val;
        trav = trav->next;
        if (trav != nullptr) cout << ", ";
    }
    cout << "]";
}

void LLNode::clear() {
    LLNode* pre = this;
    LLNode* trav = this;
    while (trav != nullptr) {
        trav = trav->next;
        delete pre;
        pre = trav;
    }
}


/// BEGIN  <STUDENT ANSWER>
int LLNode::convertNodeData(LLNode *head)
{
    LLNode *trav = head;
    int result = 0;
    int multi = 1;
    while (trav != nullptr)
    {
        result = result + (trav->val * multi);
        multi = multi * 10;
        trav = trav->next;
    }
    return result;
}
LLNode* addLinkedList(LLNode* l0, LLNode* l1) {
    // STUDENT ANSWER
     int result;
    int temp;
    int count = 0;
    int pos = 0;
    result = LLNode::convertNodeData(l0) + LLNode::convertNodeData(l1);
    temp = result;
    while (temp > 0)
    {
        temp = temp / 10;
        count++;
    }
    int arr[count];
    while (result > 0)
    {
        int lastnum;
        lastnum = result % 10;
        result = result / 10;
        arr[pos] = lastnum;
        pos++;
    }
    LLNode *l2 = LLNode::createWithIterators(arr, arr + sizeof(arr) / sizeof(int));
    return l2;
}
/// END  <STUDENT ANSWER>