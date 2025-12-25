#include <iostream>
#include <iomanip>
#include <string>
#include <cstring>
#include <fstream>
using namespace std;

// const int Max_Size = 1000;
class Arraylist
{
public:
    int *arr;
    int capacity;
    int U_Size;

    Arraylist() {}
    Arraylist(int cap)
    {
        capacity = cap;
        U_Size = 0;
        arr = new int[capacity];
    }

    ~Arraylist()
    {
        delete[] arr;
    }

    void resize()
    {
        capacity *= 2;
        int *newarr = new int[capacity];
        for (int i = 0; i < U_Size; i++)
        {
            newarr[i] = arr[i];
        }
        delete[] arr;
        arr = newarr;
    }
    bool isfull()
    {
        if (U_Size == capacity)
        {
            resize();
            return false;
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
        if (U_Size != capacity)
        {
            arr[U_Size++] = x;
            return;
        }
        else
            resize();
        arr[U_Size++] = x;
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

    void Bubblesort()
    {
        int swaps = 0;
        int comaparisons = 0;
        for (int i = 0; i < U_Size - 1; i++)
        {
            for (int j = 0; j < U_Size - i - 1; j++)
            {
                comaparisons++;
                if (arr[j] > arr[j + 1])
                {
                    swaps++;
                    swap(arr[j], arr[j + 1]);
                }
            }
        }

        cout << "Total Number of swaps in Bubbble Sort = " << swaps << endl;
        cout << "Total Number of comparisons in Bubbble Sort = " << comaparisons << endl;
    }

    void SelectionSort()
    {
        int swaps = 0;
        int comaparisons = 0;
        for (int i = 0; i < U_Size - 1; i++)
        {
            int min_index = i;
            for (int j = i + 1; j < U_Size; j++)
            {
                comaparisons++;
                if (arr[j] < arr[min_index])
                {
                    min_index = j;
                }
            }
            swaps++;
            swap(arr[i], arr[min_index]);
        }

        cout << "Total Number of swaps in Selection Sort = " << swaps << endl;
        cout << "Total Number of comparisons in Selection Sort = " << comaparisons << endl;
    }

    void InsertionSort()
    {
        int swaps = 0;
        int comaparisons = 0;
        for (int i = 1; i < U_Size; i++)
        {
            int key = arr[i];
            int j = i - 1;
            while (j >= 0)
            {
                comaparisons++;
                if (arr[j] > key)
                {
                    swaps++;
                    arr[j + 1] = arr[j];
                    j = j - 1;
                }
                else
                {
                    break;
                }
            }

            arr[j + 1] = key;
        }

        cout << "Total Number of swaps in Insertion Sort = " << swaps << endl;
        cout << "Total Number of comparisons in Insertion Sort = " << comaparisons << endl;
    }
};
int main()
{
    Arraylist al1(2);
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
    cout << endl;

    // cout<<"Bubble Sort is "<<endl;
    // al1.Bubblesort();
    // al1.Display();
    // cout << endl;

    // cout<<"selection Sort is "<<endl;
    // al1.SelectionSort();
    // al1.Display();
    // cout << endl;

    cout << "Insertion Sort is " << endl; 
    al1.InsertionSort(); 
    al1.Display(); 

    // al1.deletionAtindex(2);
    // al1.Display(); 

    return 0;
}