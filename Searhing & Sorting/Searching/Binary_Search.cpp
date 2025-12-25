#include <iostream>
#include <iomanip>
#include <string>
#include <cstring>
#include <fstream>
using namespace std;

// Binary Search Algorithm
// Time Complexity: O(log n)
// Space Complexity: O(1)
// It is used to find the element in the array
// It is efficient for large data sets
// It is used when the array is sorted
// Array must be sorted before using binary search 

int main()
{
    int arr[] = {1, 2, 5, 8, 10, 12, 15}; // Array must be sorted for binary search
    int n = sizeof(arr) / sizeof(arr[0]);

    int key = 10;
    bool found = false;
    int low = 0, high = n - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] == key)
        {
            found = true; 
            cout << "Element found at index: " << mid << endl;
            break;
        }
        else if (arr[mid] < key) 
        {
            low = mid + 1;
        } 
        else 
        {
            high = mid - 1;
        }
    }

    if (!found)
    {
        cout << "Element not found" << endl;
    }

    // Binary search on answers 
    int left = 1, right = 100;
    int ans = -1;
    int target = 57; // Let's say we are searching for 57
    while (left <= right)
    {
        int mid = left + (right - left) / 2; // To avoid overflow 
        if (mid == target)
        {
            ans = mid; 
            break; 
        }
        else if (mid < target) 
        { 
            left = mid + 1; 
        } 
        else
        { 
            right = mid - 1;
        } 
    }
    cout << "Answer found: " << ans << endl;


    return 0;
}