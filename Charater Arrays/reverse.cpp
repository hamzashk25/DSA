#include <iostream>
#include <iomanip>
#include <string>
#include <cstring>
#include <fstream>
#include<math.h>
using namespace std;

void reverse(char name[], int n)
{

    int s = 0;
    int e = n - 1;
    while (s < e)
    {
        swap(name[s++], name[e--]);
    }
}
int main()
{

    char name[20];

    cout << "Enter a name: ";
    cin >> name;

    int lenght = strlen(name);
    reverse(name, lenght);

    cout << "Reverse String is ";
    cout << name;
    return 0;
}