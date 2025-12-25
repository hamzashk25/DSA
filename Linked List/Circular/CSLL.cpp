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

    Node(int d)
    {
        data = d;
        next = nullptr;
    }
};

class CircularSinglyLinkedList
{
private:
    Node *head;

public:
    CircularSinglyLinkedList()
    {
        head = nullptr;
    }

    void insertathead(int d)
    {
        Node *newnode = new Node(d);
        if (head == nullptr)
        {
            head = newnode;
            newnode->next = head;
            return;
        }
        Node *temp = head;
        while (temp->next != head)
        {
            temp = temp->next;
        }
        newnode->next = head;
        temp->next = newnode;
        head = newnode;
    }

    void insertattail(int d)
    {
        Node *newnode = new Node(d);
        if (head == nullptr)
        {
            head = newnode;
            newnode->next = head;
            return;
        }
        Node *temp = head;
        while (temp->next != head)
        {
            temp = temp->next;
        }
        temp->next = newnode;
        newnode->next = head;
    }

    void display()
    {
        if (head == nullptr)
        {
            cout << "List is empty" << endl;
            return;
        }
        Node *temp = head;  
        do
        {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
        cout << endl;
    }

    void deletionathead()
    {
        if (head == nullptr)
        {
            cout << "List is empty" << endl;
            return;
        }
        if (head->next == head)
        {
            delete head;
            head = nullptr;
            return;
        }
        Node *temp = head;
        while (temp->next != head)
        {
            temp = temp->next;
        }
        Node *deleteheadnode = head;
        temp->next = head->next;
        head = head->next;
        delete deleteheadnode;
    }

    void deletionattail()
    {
        if (head == nullptr)
        {
            cout << "List is empty" << endl;
            return;
        }
        if (head->next == head)
        {
            delete head;
            head = nullptr;
            return;
        }
        Node *temp = head;
        Node *prev = nullptr;
        while (temp->next != head)
        {
            prev = temp;
            temp = temp->next;
        }
        prev->next = head;
        delete temp;
    }
};
int main()
{
    CircularSinglyLinkedList csll;
    csll.insertathead(10);
    csll.display();

    csll.insertattail(20);
    csll.display();

    csll.insertattail(30);
    csll.display();

    csll.deletionathead();
    csll.display();
    return 0;
}