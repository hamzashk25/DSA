#include <iostream>
#include <iomanip>
#include <string>
#include <cstring>
#include <fstream>
using namespace std;

int main()
{
    int n = 30;

    cout<<"Prime number is ";
    for (int i = 3; i < n; i++)
    {
        bool isprime = true;
        for (int j = 2; j < i; j++)
        {
            if (i % j == 0)
            {
                // cout << "not prime ";
                isprime = false;
                break;
            }
        }

        if (isprime)
        {
            cout << i<<" " ;
        }
    }

    return 0;
}
