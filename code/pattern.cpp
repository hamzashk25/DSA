#include <iostream>
#include <iomanip>
#include <string>
#include <cstring>
#include <fstream>
using namespace std;
// ***3
// **2
// *1
// int main()
// {
//     int n;
//     cout << "Enter a number ";
//     cin >> n;
//     for (int i = n; i > 0; i--)
//     {
//         for (int j = 0; j < i; j++)
//         {
//             cout << "*";
//         }
//         cout << i << endl;
//     }
//     return 0;
// }

// ***-****-*****
void star(int n)
{
    // while (n != 0)
    if (n == 0)
        return;

    int mod = n % 10;
    n = n / 10;
    star(n);
    static bool first = true;
    if (!first)
    {
        cout << "-";
    }
    for (int i = 0; i < mod; i++)
    {
        cout << "*";
    }

    first = false;
    // n = n / 10;
}
int main()
{
    int n = 345;

    star(n);
}