#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *prev;
    Node *next;

    Node(int d)
    {
        data = d;
        prev = nullptr;
        next = nullptr;
    }
};

class DoublyLinkedList
{
private:
    Node *head;

public:
    DoublyLinkedList()
    {
        head = nullptr;
    }

    void insertAtHead(int d)
    {
        Node *temp = new Node(d);
        temp->next = head;
        if (head != nullptr)
        {
            head->prev = temp;
        }
        head = temp;
    }

    void insertAtTail(int d)
    {
        Node *temp = new Node(d);
        if (head == nullptr)
        {
            head = temp;
            return;
        }

        Node *curr = head;
        while (curr->next != nullptr)
        {
            curr = curr->next;
        }

        curr->next = temp;
        temp->prev = curr;
    }

    void insertAtAnyPosition(int position, int d)
    {
        if (position == 1)
        {
            insertAtHead(d);
            return;
        }

        Node *curr = head;
        int count = 1;
        while (curr != nullptr && count < position - 1)
        {
            curr = curr->next;
            count++;
        }

        Node *newNode = new Node(d);
        if (curr == nullptr)
        {
            // Insert at tail if position is beyond list
            insertAtTail(d);
            return;
        }

        newNode->next = curr->next;
        newNode->prev = curr;
        if (curr->next != nullptr)
        {
            curr->next->prev = newNode;
        }
        curr->next = newNode;
    }

    void insertAtMiddle(int d)
    {
        Node *slow = head;
        Node *fast = head;
        while(fast->next!=nullptr && fast->next->next!=nullptr)
        {
            fast=fast->next->next;
            slow=slow->next;
        }

        Node *newNode = new Node(d);
        newNode->next = slow->next;
        newNode->prev = slow;
        if (slow->next != nullptr)
        {
            slow->next->prev = newNode;
        }
        slow->next = newNode;


    }
    void print()
    {
        Node *curr = head;
        while (curr != nullptr)
        {
            cout << curr->data << " ";
            curr = curr->next;
        }
        cout << endl;
    }
};

int main()
{
    DoublyLinkedList dll;

    dll.insertAtHead(10);
    dll.print();

    dll.insertAtHead(20);
    dll.print();

    dll.insertAtTail(30);
    dll.print();

    dll.insertAtAnyPosition(3, 40);
    dll.print();

    dll.insertAtAnyPosition(1, 50);
    dll.print();
    
    dll.insertAtAnyPosition(1, 50);
    dll.print();

    dll.insertAtAnyPosition(10, 60); // position beyond list, inserts at tail
    dll.print();

    dll.insertAtMiddle(25);
    dll.print();
    return 0;
}
