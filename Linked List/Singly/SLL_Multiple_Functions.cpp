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

class linkedlist
{
public:
    Node *head;

    linkedlist()
    {
        head = nullptr;
    }
    void insertathead(int d)
    {
        if (head == nullptr)
        {
            Node *newnode = new Node(d);
            head = newnode;
            head->next = nullptr;
            return;
        }

        Node *newnode = new Node(d);
        newnode->next = head;
        head = newnode;
    }
    void insertatlast(int d)
    {
        if (head == nullptr)
        {
            Node *newnode = new Node(d);
            head = newnode;
            head->next = nullptr;
            return;
        }

        Node *temp = head;
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }
        Node *newnode = new Node(d);
        newnode->next = nullptr;
        temp->next = newnode;
    }

    void insertatposition(int position, int d)
    {
        if (position == 1)
        {
            insertathead(d);
            return;
        }
        int count = 0;

        Node *temp = head;
        while (count < position - 1)
        {
            temp = temp->next;
            count++;
        }

        if (temp->next == nullptr)
        {
            insertatlast(d);
        }

        Node *newnode = new Node(d);
        temp->next = newnode;
        newnode->next = temp->next;
    }

    void deleteathead()
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

    void deleteatlast()
    {
        if (head == nullptr) // its condition help when all nodes are deleted
        {
            cout << "List is empty, cannot delete" << endl;
            return;
        }

        if (head->next == nullptr)
        {
            delete head;
            head = nullptr;
            return;
        }
        Node *temp = head;
        Node *prev = nullptr;
        while (temp->next != nullptr)
        {
            prev = temp;
            temp = temp->next;
        }
        prev->next = nullptr;
        delete temp;
    }
    void print()
    {
        Node *temp = head;
        while (temp != nullptr)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
        delete temp;
    }

    void sortinglist()
    {
        if (head == nullptr)
            return;

        // Node *curr = head;

        // while (curr != nullptr)
        // {
        //     Node *prev = head;
        //     while (prev->next != nullptr)
        //     {
        //         if (prev->data > prev->next->data)
        //         {
        //             swap(prev->data, prev->next->data);
        //         }
        //         prev = prev->next;
        //     }
        //     curr = curr->next;
        // }

        for (Node *i = head; i != nullptr; i = i->next)
        {
            for (Node *j = head; j->next != nullptr; j = j->next)
            {
                if (j->data > j->next->data)
                    swap(j->data, j->next->data);
            }
        }
    }

    Node *midcalculate(Node *start, Node *end)
    {
        if (start == NULL)
            return NULL;

        Node *slow = start;
        Node *fast = start->next;

        while (fast != end)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    int binarySearch(int x)
    {
        Node *start = head;
        Node *end = NULL;

        do
        {
            Node *mid = midcalculate(start, end);

            if (mid == NULL)
                return -1;

            if (mid->data == x)
                return 1; // found

            else if (mid->data < x)
                start = mid->next; // search right half
            else
                end = mid; // search left half

        } while (end == NULL || end != start);

        return -1; // not found
    }

    void reverseList()
    {
        Node *prev = nullptr;
        Node *curr = head;
        Node *next = nullptr;

        while (curr != nullptr)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        head = prev;
    }
    bool hasCycle()
    {
        Node *slow = head;
        Node *fast = head;
        while (fast != nullptr && fast->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)
                return true;
        }
        return false;
    }
    void removeNthFromEnd(int n)
    {
        Node *dummy = new Node(0);
        dummy->next = head;
        Node *fast = dummy;
        Node *slow = dummy;

        for (int i = 0; i < n; i++)
        {
            if (fast->next != nullptr)
                fast = fast->next;
            else
                return; // n larger than list length
        }

        while (fast->next != nullptr)
        {
            fast = fast->next;
            slow = slow->next;
        }

        Node *temp = slow->next;
        slow->next = slow->next->next;
        delete temp;
        head = dummy->next;
        delete dummy;
    }

    void oddEvenList()
    {
        if (head == nullptr)
            return;

        Node *odd = head;
        Node *even = head->next;
        Node *evenHead = even;

        while (even != nullptr && even->next != nullptr)
        {
            odd->next = even->next;
            odd = odd->next;
            even->next = odd->next;
            even = even->next;
        }
        odd->next = evenHead;
    }

    void reverseBetween(int left, int right)
    {
        if (left == right || head == nullptr)
            return;

        Node *dummy = new Node(0);
        dummy->next = head;
        Node *prev = dummy;

        for (int i = 1; i < left; i++)
            prev = prev->next;

        Node *curr = prev->next;
        Node *next = nullptr;

        for (int i = 0; i < right - left; i++)
        {
            next = curr->next;
            curr->next = next->next;
            next->next = prev->next;
            prev->next = next;
        }

        head = dummy->next;
        delete dummy;
    }

    bool isPalindrome()
    {
        if (head == nullptr || head->next == nullptr)
            return true;

        // find middle
        Node *slow = head;
        Node *fast = head;
        while (fast->next != nullptr && fast->next->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        // reverse second half
        Node *prev = nullptr;
        Node *curr = slow->next;
        while (curr != nullptr)
        {
            Node *next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        // compare both halves
        Node *p1 = head;
        Node *p2 = prev;
        bool palindrome = true;
        while (p2 != nullptr)
        {
            if (p1->data != p2->data)
            {
                palindrome = false;
                break;
            }
            p1 = p1->next;
            p2 = p2->next;
        }

        return palindrome;
    }

    Node *middleNode()
    {
        Node *slow = head;
        Node *fast = head;
        while (fast != nullptr && fast->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    void removeElements(int val)
    {
        while (head != nullptr && head->data == val)
        {
            Node *temp = head;
            head = head->next;
            delete temp;
        }

        Node *curr = head;
        while (curr != nullptr && curr->next != nullptr)
        {
            if (curr->next->data == val)
            {
                Node *temp = curr->next;
                curr->next = curr->next->next;
                delete temp;
            }
            else
                curr = curr->next;
        }
    }
};

;
int main()
{

    linkedlist al1;
    al1.insertatlast(10);
    al1.print();

    al1.insertathead(40);
    al1.print();

    al1.insertatlast(5);
    al1.print();

    al1.insertatlast(20);
    al1.print();

    al1.deleteathead();
    al1.print();

    al1.deleteatlast();
    al1.print();

    // cout << "Sorting list is " << endl;
    // al1.sortinglist();
    // al1.print();

    // al1.reverseList();
    // al1.print();
    return 0;
}