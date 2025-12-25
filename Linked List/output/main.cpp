#include <iostream>

// Define the Node structure for the linked list
struct Node {
    int item;   // Data part
    Node* next; // Pointer to the next node
    
    // Constructor to easily create a new node
    Node(int data) : item(data), next(nullptr) {}
};

// ===============================================
// This is the function from "Code 1"
// ===============================================
void printList2(Node* p) {
    // Base case: if the node is null, do nothing and return.
    if (p != nullptr) {
        
        // 1. Print the value on the way "in" (pre-order)
        std::cout << p->item << std::endl;
        
        // 2. Recursive call for the rest of the list
        printList2(p->next);
        
        // 3. Print the value on the way "out" (post-order)
        // This code runs *after* the recursive call has returned.
        std::cout << p->item << std::endl;
    }
}
// ===============================================


// Helper class to build the list as shown in main()
class LinkedList {
public:
    Node* head;
    LinkedList() : head(nullptr) {}

    // Function to add a node at the end
    void insertAtEnd(int data) {
        Node* newNode = new Node(data);
        if (head == nullptr) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
};

// The main function from the image, adapted for C++
int main() {
    // Create the linked list
    LinkedList p;
    p.insertAtEnd(4);
    p.insertAtEnd(2);
    p.insertAtEnd(7);
    
    // List is now: 4 -> 2 -> 7 -> NULL
    
    std::cout << "Output for Code 1:" << std::endl;
    
    // Call the function from the paper
    printList2(p.head); 
    
    return 0;
}