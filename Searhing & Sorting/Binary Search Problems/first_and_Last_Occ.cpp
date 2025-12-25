#include <iostream>
#include <iomanip>
#include <string>
#include <cstring>
#include <fstream>
using namespace std;

int firstOcc(int arr[], int n, int key)
{
    int left = 0;
    int right = n - 1;
    int mid = (left + right) / 2;
    int ans = -1;
    while (left <= right)
    {
        if (arr[mid] == key)
        {
            ans = mid;
            right = mid - 1;
        }
        else if (arr[mid] > key) // right me jao
        {
            right = mid - 1;
        }
        else if (arr[mid] < key) // left me jao
        {
            left = mid + 1;
        }
        mid = (left + right) / 2;
    }

    return ans;
}

int lastOcc(int arr[], int n, int key)
{
    int left = 0;
    int right = n - 1;
    int mid = (left + right) / 2;
    int ans = -1;
    while (left <= right)
    {
        if (arr[mid] == key)
        {
            ans = mid;
            left = mid + 1;
        }
        else if (arr[mid] > key) // right me jao
        {
            right = mid - 1;
        }
        else if (arr[mid] < key) // left me jao
        {
            left = mid + 1;
        }
        mid = (left + right) / 2;
    }

    return ans;
}
int main()
{
    int arr[7] = {1, 2, 3, 3, 3, 4, 5};

    int first_Occurance=firstOcc(arr, 7, 3);
    cout << "First Occurance at index = " << first_Occurance << endl;

    int last_Occurance=lastOcc(arr, 7, 3);
    cout << "Last Occurance at index = " << last_Occurance << endl;

    int total_Occurance= (last_Occurance-first_Occurance)+1;
    cout<<"Total Number of Occurance is "<<total_Occurance;
    return 0;
}