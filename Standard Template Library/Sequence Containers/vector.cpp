#include <iostream>
#include <iomanip>
#include <string>
#include <cstring>
#include <fstream>
#include <vector>
using namespace std;

// Vector is a sequence container that encapsulates dynamic size array.
// It is same as array but array size is fixed but vector size is dynamic.

int main()
{

    vector<string> vec;

    cout << "Vector capacity: " << vec.capacity() << endl;

    vec.push_back("Hello");
    cout << "Vector capacity: " << vec.capacity() << endl;

    vec.push_back("C++");
    cout << "Vector capacity: " << vec.capacity() << endl;

    vec.push_back("World");
    cout << "Vector capacity: " << vec.capacity() << endl;

    vec.push_back("World");
    cout << "Vector capacity: " << vec.capacity() << endl;

    vec.push_back("World");
    cout << "Vector capacity: " << vec.capacity() << endl;
    for (int i = 0; i < vec.size(); i++)
    {
        cout << vec[i] << endl;
    }

    cout << "Vector size: " << vec.size() << endl;

    cout<<"Element at index 2: " << vec.at(2) << endl;
    
    return 0;
}