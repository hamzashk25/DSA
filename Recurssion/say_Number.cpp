#include <iostream>
#include <iomanip>
#include <string>
#include <cstring>
#include <fstream>
using namespace std;

void sayNumber(string arr[], int n)
{
    if (n == 0)
        return;
    int digits = n % 10;
    n = n / 10;

    sayNumber(arr, n);
    cout << arr[digits] << " ";
}
int main()
{

    string arr[10] = {"Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};

    int n;
    cout << "Enter a number: ";
    cin >> n;
    cout << "The number in words is: ";
    sayNumber(arr, n);

    return 0;
}