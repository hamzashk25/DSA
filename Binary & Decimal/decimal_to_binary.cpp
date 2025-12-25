#include <iostream>
#include<math.h>
#include <iomanip>
#include <string>
#include <cstring>
#include <fstream>
using namespace std;

int main()
{

    int n;
    cout << "Enter a Number "; 
    cin >> n;

    // int bit = n & 1;
    // cout << "Bit of n is " << bit << endl;     .
    // cout << "n is " << n << endl;

    // n = n >> 1;
    // bit = n & 1;
    // cout << "Bit of n is " << bit << endl;
    // cout << "n is " << n << endl;

    // n = n >> 1;
    // bit = n & 1;
    // cout << "Bit of n is " << bit << endl;
    // cout << "n is " << n << endl;

    // n = n >> 1;
    // bit = n & 1;
    // cout << "Bit of n is " << bit << endl;
    // cout << "n is " << n << endl;

    int ans = 0;
    int i = 0;
    while (n != 0) // only for +ve number 
    {
        int bit = n & 1;
        // cout << bit;
        ans = (bit * pow(10, i)) + ans;

        n = n >> 1;
        i++;
    }
    cout << ans;

    return 0;
} 