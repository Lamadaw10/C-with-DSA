//Reduce given array from 0 to array.size() - 1, find the array of their value index
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool myCompare(pair<int, int> p1 , pair<int, int> p2)
{
    return p1.first < p2.first;
}

int main()
{
    int arr[] = {10, 16, 7, 14, 5, 3, 2, 9};
    vector<pair<int, int>> v;

    // Step 1: Create a vector of pairs (value, index)
    for(unsigned int i = 0; i < (sizeof(arr)/sizeof(arr[0])); i++)
    {
        v.push_back(make_pair(arr[i], i));
    }

    // Step 2: Sort the vector based on the values
    sort(v.begin(), v.end(), myCompare);

    // Step 3: Assign new values based on the index in the sorted array
    int rank = 0;
    for(unsigned int i = 0; i < v.size(); i++)
    {
        arr[v[i].second] = rank++;  // Assign rank and increment
    }

    // Step 4: Output the modified array
    for(unsigned int i = 0; i < v.size(); i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}