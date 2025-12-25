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

class SLL
{
    Node *head;

public:
    SLL()
    {
        head = nullptr;
    }

    void insertatanyposition(int position, int d)
    {
        if (position == 1)
        {
            insertAtHead(d);
            return;
        }

        Node *newnode = new Node(d);
        Node *temp = head;
        int count = 1;
        while (count < position - 1)
        {
            temp = temp->next;
            count++;
        }

        if (temp == nullptr)
        {
            cout << "Position out of bounds!" << endl;
            return;
        }
        newnode->next = temp->next;
        temp->next = newnode;
    }
    void insertAtHead(int d)
    {
        Node *newnode = new Node(d);
        if (head == nullptr)
        {
            head = newnode;
            head->next = nullptr;
            return;
        }

        newnode->next = head;
        head = newnode;
    }

    void insertAtTail(int d)
    {
        Node *newnode = new Node(d);

        Node *temp = head;
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }
        temp->next = newnode;
        newnode->next = nullptr;
    }

    void deletedublicate()
    {
        Node *temp = head;

        while (temp->next != nullptr)
        {
            Node *runner= temp;
            while (runner->next != nullptr )
            {
                if (temp->data == runner->next->data)
                {
                    Node *todelete = runner->next;
                    runner->next = runner->next->next;
                    delete todelete;
                }
                else
                {
                    runner = runner->next;
                }
            }
            temp = temp->next;
        }
    }
    void print()
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
};

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

int main()
{

    SLL list;
    list.insertAtHead(10);
    list.print();

    list.insertAtTail(10);
    list.print();

    list.insertatanyposition(2, 15);
    list.print();

    list.insertatanyposition(1, 5);
    list.print();

    list.insertAtTail(25);
    list.print();

    list.insertAtTail(10);
    list.print();

    list.deletedublicate();
    list.print();
    return 0;
}