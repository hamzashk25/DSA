#include <iostream>
#include <iomanip>
#include <string>
#include <cstring>
#include <fstream>
using namespace std;

class StackArray
{

public:
    int *arr;
    int capacity = 5;
    int TOS = -1;
    int *simple_arr;

    StackArray(int n_arr[])
    {
        arr = new int[capacity];
        simple_arr = n_arr;
    }

    bool isfull()
    {
        if (TOS == capacity-1)
        {
            return true;
        }
        return false;
    }

    bool isempty()
    {
        if (TOS == -1)
        {
            return true;
        }
        return false;
    }
    void push(int data)
    {
        if (!isfull())
        {
            arr[++TOS] = data;
        }
    }

    int pop()
    {
        if (TOS == -1)
        {
            cout << "Stack is Empty " << endl;
            return -1;
        }
        return arr[TOS--];
    }

    int getsize()
    {
        return TOS + 1;
    }
    void Display()
    {
        for (int i = TOS; i >= 0; i--)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};
int main()
{
    int arr[10]={0,1,2,3,4,5,6,7,8,9};
    StackArray st(arr);
    st.push(9);
    st.push(8);
    st.push(7);
    st.push(6);
    st.push(5);
    st.Display();

    cout << st.getsize() << endl;
    st.pop();

    st.Display();
    st.push(4);
    cout << st.getsize() << endl;
    // cout << st.pop() << endl;
    st.Display();

    return 0;
}