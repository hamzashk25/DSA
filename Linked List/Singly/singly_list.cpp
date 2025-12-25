#include <iostream>
#include <iomanip>
#include <string>
#include <cstring>
#include <fstream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node()
    {
        next = nullptr;
    }
    Node(int val)
    {
        data = val;
    }
};

void insertAtHead(Node *&head, int d)
{
    Node *temp = new Node(d);
    temp->next = head;
    head = temp;
}
void insertAtTail(Node *&tail, int d)
{
    Node *temp = new Node(d);
    tail->next = temp;
    tail = temp;
}

void insertAtPosition(Node *&head, Node *&tail, int position, int d)
{

    if (position == 1)
    {
        insertAtHead(head, d);
        return;
    }

    Node *temp = head;
    int count = 1;

    while (count < position - 1)
    {
        temp = temp->next;
        count++;
    }

    if (temp->next == NULL)
    {
        insertAtTail(tail, d);
        return;
    }

    Node *nodeToInsert = new Node(d);
    nodeToInsert->next = temp->next;
    temp->next = nodeToInsert;
}

void DeleteAtHead(Node *&head)
{
    if (head == nullptr) // its condition help when all nodes are deleted
    {
        cout << "List is empty, cannot delete" << endl;
        return;
    }
    Node *temp = head;
    head = head->next;
    temp->next = nullptr;
    delete temp;
}

void DeleteAtTail(Node *&head, Node *&tail)
{
    if (head == nullptr) // its condition help when all nodes are deleted
    {
        cout << "List is empty, cannot delete" << endl;
        return;
    }

    if (head->next == nullptr) // its condition help when only one node is present
    {
        delete head;
        head = nullptr;
        tail = nullptr;
        return;
    }

    Node *rptr = head;
    while (rptr->next != tail)
    {
        rptr = rptr->next;
    }
    rptr->next = nullptr;
    delete tail;
    tail = rptr;
}

void DeleteAtTail(Node *&head)
{
    if (head == nullptr) // If list is empty then we used it
    {
        cout << "List is Empty ";
        return;
    }

    if (head->next == NULL) // this is usefull when have one node in a list
    {
        delete head;
        head = nullptr;
        return;
    }
    Node *curr = head;
    Node *prev = NULL;

    while (curr->next != nullptr)
    {
        prev = curr;
        curr = curr->next;
    }
    prev->next = nullptr;
    delete curr;
}
void DeleteAtPosition(int position, Node *&head)
{
    if (head == nullptr)
    {
        cout << "List is empty, cannot delete" << endl;
        return;
    }

    // Deleting a first Node like a head
    if (position == 1)
    {
        DeleteAtHead(head);
        return;
    }
    else
    {
        Node *curr = head;
        Node *prev = NULL;

        int count = 1;
        while (count < position)
        {
            prev = curr;
            curr = curr->next;
            count++;
        }
        prev->next = curr->next;
        curr->next = NULL;
        delete curr;
    }
}

int Searching(Node *&head, int d)
{
    if (head == nullptr)
        return -1;

    int position = 1;
    Node *temp = head;
    while (temp != nullptr)
    {
        if (temp->data == d)
        {
            DeleteAtPosition(position, head);
            return position;
        }
        temp = temp->next;
        position++;
    }
    return -1;
}

void print(Node *head)
{
    Node *temp = head;

    while (temp != NULL)
    {
        cout << temp->data << " ";
        // cout << temp->next << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    // Node newnode;
    Node *node1 = new Node(10);
    Node *head = node1;
    Node *tail = node1;

    print(head);

    insertAtTail(tail, 12);
    print(head);

    insertAtTail(tail, 20);
    print(head);

    // Searching(head, 10);
    cout << "position is " << Searching(head, 40) << endl;
    print(head);
    // insertAtHead(head, 140);
    // print(head);

    // insertAtHead(head, 160);
    // print(head);

    // insertAtHead(head, 120);
    // print(head);

    // insertAtTail(tail, 230);
    // print(head);

    cout << "Head " << head->data << endl;
    cout << "Tail " << tail->data << endl;

    // DeleteAtHead(head);
    // print(head);

    // DeleteAtHead(head);
    // print(head);

    // DeleteAtTail(head, tail);
    // print(head);

    // DeleteAtPosition(1, head);
    // print(head);

    // cout << "Head " << head->data << endl;
    // cout << "Tail " << tail->data << endl;

    // DeleteAtTail(head);
    // print(head);

    // cout << "Head " << head->data << endl;
    // cout << "Tail " << tail->data << endl;
    return 0;
}