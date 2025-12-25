#include <iostream>
#include <iomanip>
#include <string>
#include <cstring>
#include <fstream>
using namespace std;

int main()
{
    // Floyd's Triangle  
    // 1
    // 23
    // 456
    // 78910
    int n;
    cout << "Enter a Number ";
    cin >> n;

    int count = 1;
    int i;
    for (i = 0; i < n; i++)
    {
        for (int j = 0; j < i + 1; j++)
        {
            cout << count;
            count = count + 1;
        }

        cout << endl;
    }
    return 0;
}