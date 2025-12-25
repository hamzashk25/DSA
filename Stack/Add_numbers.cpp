#include <iostream>
#include <string>

using namespace std;

// Function to add two large numbers represented as strings
string addLargeNumbers(string num1, string num2) {
    string result = "";

    int i = num1.length() - 1; // pointer for num1
    int j = num2.length() - 1; // pointer for num2
    int carry = 0;

    while (i >= 0 || j >= 0 || carry != 0) {
        int digit1 = 0;
        int digit2 = 0;

        if (i >= 0) {
            digit1 = num1[i] - '0';
            i--;
        }

        if (j >= 0) {
            digit2 = num2[j] - '0';
            j--;
        }

        int sum = digit1 + digit2 + carry;
        carry = sum / 10;
        result += (sum % 10 + '0'); // append digit to result
    }

    // The result is in reverse order, so reverse it manually
    int start = 0;
    int end = result.length() - 1;
    while (start < end) {
        char temp = result[start];
        result[start] = result[end];
        result[end] = temp;
        start++;
        end--;
    }

    return result;
}

int main() {
    string n1 = "5923";
    string n2 = "1029";

    cout << "Number 1: " << n1 << endl;
    cout << "Number 2: " << n2 << endl;
    cout << "Expected Output: 6952" << endl;
    cout << "Actual Output:   " << addLargeNumbers(n1, n2) << endl;

    return 0;
}
