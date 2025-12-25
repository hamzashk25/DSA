#include <iostream>
#include <iomanip>
#include <string>
#include <cstring>
#include <fstream>
#include<queue>
using namespace std;

int main()
{
    
    queue<int> q;

    q.push(10);
    q.push(20);
    q.push(30);

    cout<<"Front element of queue: " << q.front() << endl; // Access front element
    q.pop(); // Remove front element
    cout<<"Front element of queue: " << q.front() << endl; // Access front element
    cout << "Size of queue: " << q.size() << endl; // Get size of queue
    cout << "Empty or not " << q.empty() << endl; // Check if
    cout<<"Back element of queue: " << q.back() << endl; // Access back
    return 0;
}