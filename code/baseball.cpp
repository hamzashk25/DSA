#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <stack>

using namespace std;
// An integer x: Record a new score of x by adding it to the score record.
// "+": Record a new score that is the sum of the previous two scores in the record.
// "D": Record a new score that is twice the previous score in the record.
// "C": Invalidate and remove the most recent score in the record.

int callpoints(vector<string> arr)
{
    stack<int> st;
    for (string op : arr)
    {
        if (op == "C")
        {
            st.pop();
        }
        else if (op == "D")
        {
            st.push(2 * st.top());
        }
        else if (op == "+")
        {
            int top1 = st.top();
            st.pop();
            int top2 = st.top();
            st.push(top1);
            st.push(top1 + top2);
        }
        else
        {
            st.push(stoi(op));
        }
    }

    int sum = 0;

    while (!st.empty())
    {
        sum += st.top();
        st.pop();
    }
    return sum;
}
int main()
{

    // vector<string> arr = {"5", "2", "C", "D", "+"};
    int n;
    cin >> n;

    vector<string> arr(n);
    string operation;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << "sum " << callpoints(arr);
    // for (int i = 0; i < arr.size(); i++)
    // {
    //     cout << arr[i];
    // }

    return 0;
}