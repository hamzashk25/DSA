#include <iostream>
#include <iomanip>
#include <string>
#include <cstring>
#include <fstream>
#include<array>
using namespace std;

// Array is a container that encapsulates fixed size array.
// Array size is fixed at compile time and cannot be changed at runtime.

template <typename T, size_t N>
void printArray(const array<T, N>& arr) {
    cout << "Array elements: ";
    for (const auto& element : arr) {
        cout << element << " ";
    }
    cout << endl;
}


int main()
{
    
    int arr1[5] = {1, 2, 3, 4, 5};
    cout << "Array size: " << sizeof(arr1) / sizeof(arr1[0]) << endl;

    array<int, 5> arr = {1, 2, 3, 4, 5};
    cout << "Array size: " << arr.size() << endl;
    cout << "Array elements: ";

    for (const auto& element : arr) {
        cout << element << " ";
    }
    cout << endl;
    cout << "Element at index 2: " << arr.at(2) << endl;
    cout << "First element: " << arr.front() << endl;
    cout << "Last element: " << arr.back() << endl;
    cout << "Array data pointer: " << arr.data() << endl;
    cout << "Array is empty: " << (arr.empty() ? "Yes" : "No") << endl;
    return 0;
}