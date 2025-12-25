#include <iostream>
#include <iomanip>
#include <string>
#include <cstring>
#include <fstream>
using namespace std;

// Selection Sort Algorithm
// Time Complexity: O(n^2)
// Space Complexity: O(1)
// It is used to sort the array
// It is not efficient for large data sets
// It is used when the array is small
// In this sorting we used a concept of minIndex that compare of awhole array and then put in first
int main()
{

    int arr[] = {5, 2, 8, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    for (int i = 0; i < n - 1; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);
    }
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " "; // Display elements in the array
    }
    cout << endl;

    return 0;
}