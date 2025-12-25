#include <iostream>
#include <iomanip>
#include <string>
#include <cstring>
#include <fstream>
using namespace std;

bool isPossible(int arr[], int n, int m, int mid)
{
    int studentCount = 1;
    int pgsum = 0;

    for (int i = 0; i < n; i++)
    {
        if (pgsum + arr[i] <= mid)
        {
            pgsum += arr[i];
        }
        else
        {
            studentCount++;
            if (studentCount > m || arr[i] > mid)
            {
                return false;
            }
            pgsum = arr[i];
        }
    }

    return true;
}
int main()
{
    const int n = 4;
    int arr[n] = {10, 20, 30, 40};

    int start = 0;

    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }

    int end = sum; // we assign sum with mid bcz array that 
    int ans = -1;
    int mid = (start + end) / 2;
    while (start < end)
    {
        if (isPossible(arr, n, 2, mid))
        { 
            ans = mid; 
            end = mid - 1; 
        } 
        else
        {
            start = mid + 1; 
        }

        mid = (start + end) / 2;
    }

    cout << "Answer is " << ans;
    return 0;
} 