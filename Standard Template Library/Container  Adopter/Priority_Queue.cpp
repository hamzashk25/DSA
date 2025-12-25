#include <iostream>
#include <iomanip>
#include <string>
#include <cstring>
#include <fstream>
#include <queue>
using namespace std;

int main()
{
    // max heap
    priority_queue<int> maxheap;

    // min heap
    priority_queue<int, vector<int>, greater<int>> minheap;
    maxheap.push(5);
    maxheap.push(10);
    maxheap.push(15);
    maxheap.push(20);

    cout << "Size of max heap: " << maxheap.size() << endl; // Get size of max heap

    int n = maxheap.size();

    for (int i = 0; i < n; i++)
    {
        cout << "Max heap element: " << maxheap.top() << endl; // Access top element
        maxheap.pop(); // Remove top element
    }

    cout<<"----------------------------------" << endl;
    minheap.push(5);
    minheap.push(10); 
    minheap.push(15);
    minheap.push(20);

    cout << "Size of min heap: " << minheap.size() << endl; // Get size of min heap 
    n = minheap.size();
    for (int i = 0; i < n; i++)
    {
        cout << "Min heap element: " << minheap.top() << endl; // Access top element
        minheap.pop(); // Remove top element
    }
    return 0;
}