#include <iostream>
#include <iomanip>
#include <string>
#include <cstring>
#include <fstream>
#include <deque>
using namespace std;

// Deque is a double ended queue that allows the insertion and deletion of elements from both ends.
// It is similar to vector but it is more efficient for insertion and deletion of elements from both ends.
// It is implemented as a dynamic array of fixed size arrays.
// it is not a continuous memory allocation like vector.
// It is a sequence container that allows the insertion and deletion of elements from both ends.
// it is used in sliding window problems.
// It is used in BFS and DFS algorithms.
// you can use deque as a stack and queue both.

int main()
{

    deque<int> dq;

    dq.push_front(1);
    dq.push_back(2);

    dq.size();
    cout << "Deque size: " << dq.size() << endl;

    cout << "Front element: " << dq.front() << endl;
    cout << "Back element: " << dq.back() << endl;
    cout << "Element at index 1: " << dq.at(1) << endl;
    cout << "Deque is empty: " << (dq.empty() ? "Yes" : "No") << endl;
    dq.pop_front();
    dq.pop_back();

    cout << "Deque size after pop: " << dq.size() << endl;
    return 0;
}