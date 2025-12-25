#include <iostream>
#include <iomanip>
#include <string>
#include <cstring>
#include <fstream>
#include<stack>
using namespace std;

// This code demonstrates the use of the stack container in C++ STL.
// It includes operations like push, pop, and checking the size and emptiness of the stack.
// It is a LIFO (Last In First Out) data structure.

int main()
{
    stack<int> s;

    // stack<int> n(s); // copy constructor
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);

    cout<<"Top element of stack: " << s.top() << endl; // Access top element
    s.pop(); // Remove top element
    cout << "Size of stack: " << s.size() << endl; // Get size of stack
    cout << "Empty or not " << s.empty() << endl; // Check if
    cout<<"Top element of stack: " << s.top() << endl; // Access top element
    
    return 0;
}