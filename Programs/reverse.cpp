#include <iostream>
#include <iomanip>
#include <string>
#include <cstring>
#include <fstream>
using namespace std;

// Function to reverse a number
// Two cases 
// 1. Positive Number or negative Number
// 2. Integer overflow/underflow
int main()
{

    int n;
    cout << "Enter a numbeer: ";
    cin >> n;

    int ans=0;
    while (n != 0)
    {
        int digit = n % 10;
        if (ans > INT_MAX/10 || ans < INT_MIN/10)
        {
            cout << "Error: Integer overflow/underflow occurred." << endl;
            return 0; // Exit the program with an error code
        }

        ans=(ans*10)+digit;
        // cout << ans<<" ";
        n = n / 10;
    }

    cout<<INT_MAX<<endl;
    cout<<INT_MIN<<endl;
    cout<<endl;
    cout<<"Reversed Number: "<<ans<<endl;
    return 0;
}

