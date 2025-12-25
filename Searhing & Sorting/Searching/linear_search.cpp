#include <iostream>
#include <iomanip>
#include <string>
#include <cstring>
#include <fstream>
using namespace std;

// Linear Search Algorithm
// Time Complexity: O(n)
// Space Complexity: O(1)
// It is used to find the element in the array
// It is not efficient for large data sets
// It is used when the array is not sorted
// It is used when the array is small

int main()
{

    int arr[] = {5, 2, 8, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    int key = 8;
    bool found = false;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == key)
        {
            found = true;
            cout << "Element found at index: " << i << endl;
            break;
        }
    }

    if (!found)
    {
        cout << "Element not found" << endl;
    }

    return 0;
}