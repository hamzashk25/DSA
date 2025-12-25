#include <iostream>
#include <iomanip>
#include <string>
#include <cstring>
#include <fstream>
using namespace std;

void printNumbers(int n)
{
    if (n <= 0)
        return;

    printNumbers(n - 1);
    cout << n << " ";
}

int main()
{

    int number;
    cout << "Enter a positive integer: ";
    cin >> number;

    printNumbers(number);
    return 0;
}