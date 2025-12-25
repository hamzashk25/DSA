#include <iostream>
#include <math.h>
#include <iomanip>
#include <string>
#include <cstring>
#include <fstream>
using namespace std;

int main()
{

    int n;
    cout << "Enter a Numner: ";
    cin >> n;

    bool found = false;
    for (int i = 0; i <= 30; i++)
    {
        if (n == pow(2, i))
        {
            cout << "Number is power of 2 at index is " << i << endl;
            found = true;
            break;
        }

        if (n == 0 || n > pow(2, 30))
        {
            cout << "Number is 0 or greater than 2^30 " << endl;
            found=true;
            break;
        }
    }

    if (!found)
    {
        cout << "Number is not power of two: ";
    }
    return 0;   
}