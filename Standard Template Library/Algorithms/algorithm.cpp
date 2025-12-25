#include <iostream>
#include <iomanip>
#include <string>
#include <cstring>
#include <fstream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    
    vector<int> v;

    v.push_back(5);
    v.push_back(2);
    v.push_back(8);
    v.push_back(1);

    for(auto i:v)
    {
        cout<<i<<" "; // Display elements in the vector
    }

    cout<<endl;
    cout<<"display first element: "<<v.front()<<endl; // Display the first element in the vector
    cout<<"display last element: "<<v.back()<<endl; // Display the last element in

    cout<<"Beginning of vector: "<<*v.begin()<<endl; // Display the address of the first element in the vector

    cout<<"Findeing 2: "<<binary_search(v.begin(),v.end(),2)<<endl; // Find element 2 in the vector
    sort(v.begin(),v.end()); // Sort the vector
    cout<<"After sorting: ";
    for(auto i:v)
    {
        cout<<i<<" "; // Display elements in the vector
    }
    
    cout<<endl;
    cout<<"Findeing 2: "<<binary_search(v.begin(),v.end(),2)<<endl; // Find element 2 in the vector


    cout<<"Lower bound of 2: "<<lower_bound(v.begin(),v.end(),2)-v.begin()<<endl; // Lower bound of element 2
    cout<<"Upper bound of 2: "<<upper_bound(v.begin(),v.end(),2)-v.begin()<<endl; // Upper bound of element 2 upper mean from the back side of the array

    cout<<"begin: "<<*v.begin()<<endl; // Display the first element in the vector using begin()
    return 0;
}
