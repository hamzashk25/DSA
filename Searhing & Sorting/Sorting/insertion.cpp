#include <iostream>
#include <iomanip>
#include <string>
#include <cstring>
#include <fstream>
using namespace std;

// Insertion Sort Algorithm
// Time Complexity: O(n^2)
// Space Complexity: O(1)
// It is used to sort the array
// It is efficient for small data sets
// It is used when the array is partially sorted
int main()
{
    int arr[] = {5, 2, 8, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    for(int i=1;i<n;i++)
    {
        int key = arr[i];
        int j = i-1;
        while(j>=0 && arr[j]>key)
        {
            arr[j+1] = arr[j];
            j--;
        } 
        arr[j+1] = key;
    }

    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" "; // Display elements in the array
    }

    cout<<endl;

    return 0;
}