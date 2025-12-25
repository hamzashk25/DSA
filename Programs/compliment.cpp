#include <iostream>
#include <math.h>
#include <iomanip>
#include <string>
#include <cstring>
#include <fstream>
using namespace std;

int main()
{

    int n = 5;
    // cout << "Enter a numbeer: ";
    // cin >> n;

    int ans = 0;
    int i = 0;
    while (n != 0)
    {
        int bit = n & 1;

        ans = (bit * pow(10, i)) + ans;

        n = n >> 1;
        i++;
    }

    cout << ans << endl;

    int compliment;

    compliment = (~ans) & 111;

    cout << compliment;
    return 0;
}