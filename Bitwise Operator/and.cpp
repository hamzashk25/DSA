#include <iostream>
#include <iomanip>
#include <string>
#include <cstring>
#include <fstream>
using namespace std;

int main()
{
    int a = 2;
    int b = 3;
    cout <<"a & b is "<< (a & b) << endl;

    a = 2;
    b = 4;
    cout << "a or b is "<<(a | b) << endl;
    cout <<"not a "<< (~a) << endl;
    cout << "XOR of a and b "<<(a ^ b) << endl;
    return 0;
}