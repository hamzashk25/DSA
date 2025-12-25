#include <iostream>
#include <iomanip>
#include <string>
#include <cstring>
#include <fstream>
using namespace std;

int Partition(int arr[], int st, int end)
{
    int idx = st - 1; // iterator
    int pivot = arr[end];

    for (int j = st; j < end; j++)
    {
        if (arr[j] <= pivot)
        {
            idx++;
            swap(arr[j], arr[idx]);
        }
    }
    idx++;
    swap(arr[idx], arr[end]);

    return idx;
}

void QuickSort(int arr[], int st, int end)
{
    if (st < end) 
    {
        int q = Partition(arr, st, end); 
        QuickSort(arr, st, q - 1); 
        QuickSort(arr, q + 1, end); 
    }
} 
int main()
{

    int arr[6] = {2, 1, 3, 4, 5, 6}; 
    int n = 6; 

    QuickSort(arr, 0, n - 1); 

    for (int i = 0; i < n; i++) 
    {
        cout << arr[i]<<" "; 
    }
    return 0; 
} 