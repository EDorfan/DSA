#include <iostream>
using namespace std;

struct LinkedListNodeSingly {
    int val;
    LinkedListNodeSingly *next;
    LinkedListNodeSingly(int val): val (val), next(nullptr) {}
};

int getSum (LinkedListNodeSingly *head) {
    int ans = 0;
    while (head != nullptr) {
        ans += head->val;
        head = head->next;
    }
    return ans;
}

void addNode(LinkedListNodeSingly *prevNode, LinkedListNodeSingly *nodeToAdd) {
    nodeToAdd->next = prevNode->next;
    prevNode->next = nodeToAdd;
}

void deleteNode(LinkedListNodeSingly *prevNode) {
    prevNode->next = prevNode->next->next;
}

struct LinkedListNodeDoubly {
    int val;
    LinkedListNodeDoubly *next;
    LinkedListNodeDoubly *prev;
    LinkedListNodeDoubly(int val): val (val), next(nullptr), prev(nullptr) {}
};

void addNodeDLL(LinkedListNodeDoubly *currentNode, LinkedListNodeDoubly *nodeToAdd) {
    // Handle insertion at the beginning of the list
    if (currentNode->prev == nullptr) {
        nodeToAdd->next = currentNode;
        currentNode->prev = nodeToAdd;
        nodeToAdd->prev = nullptr;
        return;
    }

    // temporarily store the previous node
    LinkedListNodeDoubly *tempPrev = currentNode->prev;
    // update the next pointer of the node to add
    nodeToAdd->next = currentNode;
    // update the next pointer of the previous node
    tempPrev->next = nodeToAdd;
    // update the prev pointer of the node to add
    nodeToAdd->prev = tempPrev;
    // update the prev pointer of the current node
    currentNode->prev = nodeToAdd;
}

void deleteNodeDLL(LinkedListNodeDoubly *currentNode) {
    LinkedListNodeDoubly *nodePrev = currentNode->prev;
    LinkedListNodeDoubly *nodeNext = currentNode->next;
    nodePrev->next = nodeNext;
    nodeNext->prev = nodePrev;
}

// Using Sentinel Nodes

void addToEnd(LinkedListNodeDoubly* nodeToAdd, LinkedListNodeDoubly* tail) {
    nodeToAdd->next = tail;
    nodeToAdd->prev = tail->prev;
    tail->prev->next = nodeToAdd;
    tail->prev = nodeToAdd;
}

void removeFromEnd(LinkedListNodeDoubly* head, LinkedListNodeDoubly* tail) {
    if (head->next == tail) {
        return;
    }

    LinkedListNodeDoubly* nodeToRemove = tail->prev;
    nodeToRemove->prev->next = tail;
    tail->prev = nodeToRemove->prev;
}

void addToStart(LinkedListNodeDoubly* nodeToAdd, LinkedListNodeDoubly* head) {
    nodeToAdd->prev = head;
    nodeToAdd->next = head->next;
    head->next->prev = nodeToAdd;
    head->next = nodeToAdd;
}

void removeFromStart(LinkedListNodeDoubly* head, LinkedListNodeDoubly* tail) {
    if (head->next == tail) {
        return;
    }

    LinkedListNodeDoubly* nodeToRemove = head->next;
    nodeToRemove->next->prev = head;
    head->next = nodeToRemove->next;
}

int getSumDoubly (LinkedListNodeDoubly *head) {
    int ans = 0;
    while (head != nullptr) {
        ans += head->val;
        head = head->next;
    }
    return ans;
}

int main() {
    // Examples using a singly linked list
    LinkedListNodeSingly* one = new LinkedListNodeSingly(1);
    LinkedListNodeSingly* two = new LinkedListNodeSingly(2);
    LinkedListNodeSingly* three = new LinkedListNodeSingly(3);
    one->next = two;
    two->next = three;
    LinkedListNodeSingly* head = one;

    LinkedListNodeSingly* four = new LinkedListNodeSingly(4);
    addNode(one, four);

    // Example of summing elements in a singly linked list
    cout << "Singly linked list Example: " << endl;
    cout << "The sum of all the elements in the singly linked list is: " << getSum(head) << endl;
    cout << "The first element in the singly linked list is: " << head->val << endl;
    cout << "The second element in the singly linked list is: " << head->next->val << endl;
    cout << "The third element in the singly linked list is: " << head->next->next->val << endl;
    cout << "The fourth element in the singly linked list is: " << head->next->next->next->val << endl << endl;

    // Examples using a doubly linked list
    LinkedListNodeDoubly* oneDLL = new LinkedListNodeDoubly(1);
    LinkedListNodeDoubly* twoDLL = new LinkedListNodeDoubly(2);
    LinkedListNodeDoubly* threeDLL = new LinkedListNodeDoubly(3);
    oneDLL->next = twoDLL;
    twoDLL->next = threeDLL;
    twoDLL->prev = oneDLL;

    LinkedListNodeDoubly* fourDLL = new LinkedListNodeDoubly(4);
    addNodeDLL(oneDLL, fourDLL);

    cout << "Doubly linked list Example: " << endl;
    cout << "The sum of all the elements in the doubly linked list is: " << getSum(head) << endl;
    cout << "The first element in the doubly linked list is: " << head->val << endl;
    cout << "The second element in the doubly linked list is: " << head->next->val << endl;
    cout << "The third element in the doubly linked list is: " << head->next->next->val << endl;
    cout << "The fourth element in the doubly linked list is: " << head->next->next->next->val << endl << endl;
    

    // Using Sentinel Nodes
    LinkedListNodeDoubly* headSentinel = new LinkedListNodeDoubly(-1);
    LinkedListNodeDoubly* tailSentinel = new LinkedListNodeDoubly(-1);
    headSentinel->next = tailSentinel;
    tailSentinel->prev = headSentinel;    

    addToEnd(oneDLL, tailSentinel);
    addToEnd(twoDLL, tailSentinel);
    addToEnd(threeDLL, tailSentinel);
    addToEnd(fourDLL, tailSentinel);

    LinkedListNodeDoubly* fiveDLL = new LinkedListNodeDoubly(5);
    LinkedListNodeDoubly* sixDLL = new LinkedListNodeDoubly(6);
    addToStart(fiveDLL, headSentinel);
    addToStart(sixDLL, headSentinel);


    cout << "Sentinel linked list Example: " << endl;
    cout << "The sum of all the elements in the sentinel linked list is: " << getSumDoubly(headSentinel->next) << endl;
    cout << "The first element in the sentinel linked list is: " << headSentinel->next->val << endl;
    cout << "The second element in the sentinel linked list is: " << headSentinel->next->next->val << endl;
    cout << "The third element in the sentinel linked list is: " << headSentinel->next->next->next->val << endl;
    cout << "The fourth element in the sentinel linked list is: " << headSentinel->next->next->next->next->val << endl;
    cout << "The fifth element in the sentinel linked list is: " << headSentinel->next->next->next->next->next->val << endl;
    cout << "The sixth element in the sentinel linked list is: " << headSentinel->next->next->next->next->next->next->val << endl;
    
    removeFromStart(headSentinel, tailSentinel);
    removeFromEnd(headSentinel, tailSentinel);

    cout << "The sum of all the elements in the sentinel linked list after removing the first and last elements is: " << getSumDoubly(headSentinel->next) << endl;
    
}   