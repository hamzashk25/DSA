#include <iostream>
#include <iomanip>
#include <string>
#include <cstring>
#include <fstream>
using namespace std;

int main()
{
//    *
//   ***
//  *****
// *******
    int n;
    cout << "Enter a Number ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        for (int k = 0; k < n - i - 1; k++)
        {
            cout << " ";
        }

        for (int j = 0; j < i + 1; j++)
        {
            cout << "*";
        }

        for (int j = 0; j < i ; j++)
        {
            cout << "*";
        }

        cout << endl;
    }

    return 0;
}
