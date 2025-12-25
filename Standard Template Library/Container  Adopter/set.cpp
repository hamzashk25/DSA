#include <iostream>
#include <iomanip>
#include <string>
#include <cstring>
#include <fstream>
#include <set>
using namespace std;

// A set is a collection of unique elements.
// It automatically sorts the elements and does not allow duplicates.

int main()
{
    // Complexitty: O(log n) for insertion, deletion, and search operations (insert(), erase(), find(),count(), etc.)
    // Complexity of size(),begin() and empty() is O(1)
    set<int> s;

    s.insert(5);
    s.insert(5);
    s.insert(0);
    s.insert(4);
    s.insert(6);
    s.insert(2);
    s.insert(5);
    s.insert(3);
    s.insert(1);
    s.insert(2);

    
    cout << "Elements in set: ";
    for (int i : s)
    {
        cout << i << " "; // Display elements in the set
    }

    cout<<"\nSize of set: " << s.size() << endl; // Get size of set

    // s.erase(s.begin()); // Erase first element
    cout << "After erasing first element: ";
    for (int i : s)
    {
        cout << i << " "; // Display elements after erasing
    }

    cout<<"\nCount of 5 in set: " << s.count(5) << endl; // Count occurrences of 5 (0 or 1)

    set<int>::iterator it = s.find(6); // Find element 3

    if (it != s.end())
    {
        cout << "Element found: " << *it << endl; // Display found element
    }
    else
    {
        cout << "Element not found" << endl;
    }
    return 0;   
}