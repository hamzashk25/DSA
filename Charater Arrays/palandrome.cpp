#include <iostream>
#include <iomanip>
#include <string>
#include <cstring>
#include <fstream>
using namespace std;

int main()
{

    string str;
    cout << "Enter a string: ";
    cin >> str;

    // char arr[5];
    int start = 0;
    int end = str.length()-1;
    while (start <= end)
    {
        if (str[start] == str[end])
        {
            start++;
            end--;
        }
        else
        {
            cout << "Not a Palindrome";
            break;
        }
    }

    return 0;
}

// int main()
// {

//     int num;
//     cout << "Enter a integer ";
//     cin >> num;

//     int originalnum = num;
//     int rev = 0;
//     int ans = 0;
//     while (num != 0)
//     {
//         int digit = num % 10;
//         ans = ans * 10 + digit;
//         num = num / 10;
//     }

//     rev = ans;

//     if (originalnum == rev)
//     {
//         cout << "Palindrome";
//     }
//     else
//     {
//         cout << "Not a Palindrome";
//     }
// }