#include <iostream>
#include <iomanip>
#include <string>
#include <cstring>
#include <fstream>
using namespace std;

int main()
{
    int n, pow, ans = 1;
    cout << "Enter a number ";
    cin >> n;

    cout << "Enter a power ";
    cin >> pow;
    for (int i = 0; i < pow; i++)
    {
        ans = n * ans;
    }

    cout << ans;
    return 0;
}