#include<iostream>
using namespace std;

class LinkedList
{
    public:
    int val;
    LinkedList* next;

    // Constructor to initialize node with value
    LinkedList(int val)
    {
        this->val = val;
        next = NULL;
    }

    // Destructor to delete all nodes recursively
    ~LinkedList()
    {
        if(next != NULL) 
            delete next;
    }
};

// Insert at the beginning of the list
void insertAtBeginning(LinkedList* &head, int val)
{
    LinkedList* newNode = new LinkedList(val);
    newNode->next = head;
    head = newNode;
}

// Insert at the end of the list
void insertAtEnd(LinkedList* &head, int val)
{
    LinkedList* newNode = new LinkedList(val);
    if(head == NULL) {
        head = newNode;
        return;
    }
    LinkedList* temp = head;
    while(temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Delete node by value
void deleteByValue(LinkedList* &head, int val)
{
    if(head == NULL) return;

    // If head needs to be deleted
    if(head->val == val) {
        LinkedList* temp = head;
        head = head->next;
        temp->next = NULL; // Disconnect the node
        delete temp;
        return;
    }

    // Deleting non-head node
    LinkedList* current = head;
    while(current->next != NULL && current->next->val != val) {
        current = current->next;
    }

    if(current->next == NULL) return; // Value not found

    LinkedList* temp = current->next;
    current->next = temp->next;
    temp->next = NULL;
    delete temp;
}

// Reverse the linked list (iteratively)
void reverseList(LinkedList* &head)
{
    LinkedList* prev = NULL;
    LinkedList* current = head;
    LinkedList* forward = NULL;

    while(current != NULL) {
        forward = current->next;
        current->next = prev;
        prev = current;
        current = forward;
    }
    head = prev;
}

// Function to print the linked list
void printList(LinkedList* node)
{
    while(node)
    {
        cout << node->val << " -> ";
        node = node->next;
    }
    cout << "null" << endl;
}

int main()
{
    LinkedList* head = NULL;

    // Inserting elements
    insertAtEnd(head, 10);
    insertAtEnd(head, 20);
    insertAtEnd(head, 30);

    // Print the list
    cout << "Linked list: ";
    printList(head);

    // Insert at the beginning
    insertAtBeginning(head, 5);
    cout << "After inserting at beginning: ";
    printList(head);

    // Delete a node by value
    deleteByValue(head, 20);
    cout << "After deleting 20: ";
    printList(head);

    // Reverse the linked list
    reverseList(head);
    cout << "After reversing: ";
    printList(head);

    // Memory is automatically cleaned up using destructor
    delete head;

    return 0;
}
