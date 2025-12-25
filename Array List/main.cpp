#include <iostream>
#include <iomanip>
#include <string>
#include <cstring>
#include <fstream>
using namespace std;

const int Max_Size = 1000;
class Arraylist
{
public:
    int arr[Max_Size];
    int capacity;
    int U_Size;

    Arraylist() {}
    Arraylist(int usize = 0)
    {
        U_Size = usize;
    }

    void resize()
    {
        capacity*=2;
    }
    bool isfull()
    {
        if (U_Size == Max_Size)
        {
            return true;
        }
        return false;
    }

    bool isempty()
    {
        if (U_Size == 0)
            return true;
        return false;
    }

    bool search(int x)
    {
        for (int i = 0; i < U_Size; i++)
        {
            if (arr[i] == x)
            {
                return true;
            }
        }
        return false;
    }
    void Insert(int x)
    {
        if (!isfull())
        {
            arr[U_Size++] = x;
            return;
        }
        else
            return;
    }

    void Delete(int x)
    {
        for (int i = 0; i < U_Size; i++)
        {
            if (arr[i] == x)
            {
                for (int j = i; j < U_Size - 1; j++)
                {
                    arr[j] = arr[j + 1];
                }
                U_Size--;
                return;
            }
        }
    }

    void insertAtindex(int x, int index)
    {
        if (!isfull() && index >= 0 && index <= U_Size)
        {
            for (int j = U_Size; j > index; j--)
            {
                arr[j] = arr[j - 1];
            }
            arr[index] = x;
            U_Size++;
        }
    }

    void setAtindex(int x, int index)
    {
        if (index >= 0 && index < U_Size)
        {
            arr[index] = x;
        }
    }

    void insertatAtbegin(int x)
    {
        insertAtindex(x, 0);
    }

    void insertatAtend(int x)
    {
        Insert(x);
    }

    void deletionAtindex(int index)
    {
        if (index >= 0 && index < U_Size)
        {
            for (int j = index; j < U_Size; j++)
            {
                arr[j] = arr[j + 1];
            }
            U_Size--;
        }
    }
    void Display()
    {
        for (int i = 0; i < U_Size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};
int main()
{
    Arraylist al1(0);
    al1.Insert(12);
    al1.Insert(13);
    al1.Insert(14);
    al1.Insert(15);
    al1.Display();
    
    // al1.Delete(13);
    // al1.Display();

    al1.insertAtindex(20, 1);
    al1.Display();

    al1.insertatAtbegin(33);
    al1.Display();

    // al1.deletionAtindex(2);
    // al1.Display();
  

    return 0;
}