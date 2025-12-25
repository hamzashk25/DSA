#include <iostream>
#include <iomanip>
#include <string>
#include <cstring>
#include <fstream>
#include <sstream>
using namespace std;

int main()
{
    string input = "NC4 by2 Codek1 ACM3";
    string input;
    getline(cin, input);
    string words[20];
    string word;

    int maxpos = 0;
    stringstream ss(input);

    while (ss >> word)
    {
        int pos = word.back() - '0';

        word.pop_back();
        words[pos - 1] = word;
        if (pos > maxpos)
        {
            maxpos = pos;
        }
    }

    for (int i = 0; i < maxpos; i++)
    {
        cout << words[i] << " ";
    }

    return 0;
}