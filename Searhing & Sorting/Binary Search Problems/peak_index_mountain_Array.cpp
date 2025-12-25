#include <iostream>
#include <iomanip>
#include <string>
#include <cstring>
#include <fstream>
using namespace std;

int peak_index_Mountain_Array(int arr[], int n)
{
    int start = 0;
    int end = n - 1;

    int mid = (start + end) / 2;
    int ans = -1;
    while (start < end)
    {
        if (arr[mid] < arr[mid + 1])
        {
            start = mid + 1;
            ans = start;
        }
        else
        {
            end = mid;
            // ans=mid;
        }
        mid = (start + end) / 2;
    }

    return ans;
}

int main()
{

    int arr[10] = {0,1,2,3,4, 5, 6, 5, 3, 1};

    int peak_element = peak_index_Mountain_Array(arr, 10);
    cout << "Peak Element = " << peak_element << " at index = ";
    return 0;
}