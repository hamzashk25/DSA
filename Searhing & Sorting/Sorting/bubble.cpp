#include <iostream>
#include <iomanip>
#include <string>
#include <cstring>
#include <fstream>
using namespace std;

// Bubble Sort Algorithm
// Time Complexity: O(n^2)
// Space Complexity: O(1)
// It is used to sort the array
// It is not efficient for large data sets

int main()
{
    
    int arr[] = {5, 2, 8, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(arr[j]>arr[j+1])
            {
                swap(arr[j],arr[j+1]);
            }
        }
    }

    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" "; // Display elements in the array
    }

    cout<<endl;
    return 0;
}