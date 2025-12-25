#include <iostream>
#include <iomanip>
#include <string>
#include <cstring>
#include <fstream>
using namespace std;

void towerOfHanoi(int n, char from, char to, char aux)
{
    if (n == 0)
        return; // base case: no disk to move
        
    towerOfHanoi(n - 1, from, aux, to);

    cout << "Move disk " << n << " from " << from << " to " << to << endl;

    towerOfHanoi(n - 1, aux, to, from);
} 
int main()
{
    int n;
    cout << "Enter number of disks: "; 
    cin >> n;
    cout << "Sequence of moves:\n"; 
    towerOfHanoi(n, 'A', 'C', 'B');
    cout << "Total moves = " << ((1 << n) - 1) << endl; // 2^n -1
    return 0;
} 