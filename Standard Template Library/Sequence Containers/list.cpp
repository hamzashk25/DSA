#include <iostream>
#include <iomanip>
#include <string>
#include <cstring>
#include <fstream>
#include <list>
using namespace std;

int main()
{
    list<int> l;

    list<int> n(l); // copy constructor

    list<int> l2(5, 100); // fill constructor
    l.push_back(10);
    l.push_back(20);
    l.push_back(30);
    l.push_front(5);
    l.push_front(1);

    cout << "Size of list: " << l.size() << endl;
    cout << "Capacity of list: " << l.max_size() << endl;
    cout << "Is list empty: " << l.empty() << endl;
    for (int i : l)
    {
        cout << i << " ";
    }

    return 0;
}