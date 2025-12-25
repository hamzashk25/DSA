#include <iostream>
#include <iomanip>
#include <string>
#include <cstring>
#include <fstream>
using namespace std;

int main()
{

    int num;
    cout << "Enter a Number: ";
    cin >> num;

    for (int i = 0; i < num; i++)
    {
        int count = 1;
        for (int j = 1; j <= num - i; j++)
        {
            cout << j;
            count++;
        }

        for (int space = 0; space < (2 * i - 1); space++)
        {
            cout << "*";
        }
        int start = (i == 0 ? num - 1 : num - i);
        for (int j = start; j >= 1; j--)
        {
            cout << j;
        }

        cout << endl;
    }
    return 0;
}

// #include <iostream>
// using namespace std;

// int main()
// {
//     int num;
//     cout << "Enter a Number: ";
//     cin >> num;

//     for (int i = 0; i < num; i++)
//     {
//         // left side numbers
//         for (int j = 1; j <= num - i; j++)
//         {
//             cout << j;
//         }

//         // stars in the middle
//         for (int k = 0; k < (2 * i - 1); k++)
//         {
//             cout << "*";
//         }

//         // right side numbers
//         for (int j = num - i; j >= 1; j--)
//         {
//             cout << j;
//         }

//         cout << endl;
//     }

//     return 0;
// }
