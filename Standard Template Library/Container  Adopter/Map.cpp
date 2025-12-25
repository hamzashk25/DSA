#include <iostream>
#include <iomanip>
#include <string>
#include <cstring>
#include <fstream>
#include <map>
using namespace std;

// A map is a Data structure that stores elements in key-value pairs.
// It allows fast retrieval of values based on their keys.
// It automatically sorts the elements based on keys and does not allow duplicate keys.
// Complexity: O(log n) for insertion, deletion, and search operations (insert(), erase(), find(),count(), etc.)
// Complexity of size(),begin() and empty() is O(1)

int main()
{

    map<int, string> m;

    m[1] = "One";
    m[4] = "Two";
    m[9] = "Three";
    m[12] = "Four";

    m.insert({5, "Five"});

    cout << "Size of map: " << m.size() << endl; // Get size of map

    // cout << "Element at key 2: " << m[2] << endl; // Access element at key 2
    for (auto i : m)
    {
        cout << i.first << " " << i.second << endl; // Display elements in the map
    }

    cout<<"Finding key 4: "<<m.find(4)->second<<endl; // Find element at key 4
    m.erase(4); // Erase element at key 4

    for(auto i:m)
    {
        cout<<i.first<<" "<<i.second<<endl; // Display elements in the map
    }

    return 0;
}