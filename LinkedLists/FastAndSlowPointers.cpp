#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode* prev;
    ListNode(int x) : val(x), next(nullptr), prev(nullptr) {}
};

int getMiddle(ListNode *head) {
    ListNode* slow = head;
    ListNode* fast = head;
    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow->val;
}

bool hasCycle(ListNode *head) {
    ListNode* slow = head;
    ListNode* fast = head;
    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            return true;
        }
    }
    return false;
}

ListNode* findKthFromEnd(ListNode *head, int k) {
    ListNode* slow = head;
    ListNode* fast = head;
    for (int i = 0; i < k; i++) {
        fast = fast->next;
    }
    while (fast != nullptr) {
        slow = slow->next;
        fast = fast->next;
    }
    return slow;
}

int main() {
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    cout << "The middle value of the linked list is: " << getMiddle(head) << endl;
    cout << "The linked list has a cycle: " << (hasCycle(head) ? "Yes" : "No") << endl;
    
    ListNode* kthNode = findKthFromEnd(head, 2);
    cout << "The kth node from the end is: " << kthNode->val << endl;
    
    head->next->next->next->next->next = head->next->next;
    cout << "The linked list has a cycle: " << (hasCycle(head) ? "Yes" : "No") << endl;
}
