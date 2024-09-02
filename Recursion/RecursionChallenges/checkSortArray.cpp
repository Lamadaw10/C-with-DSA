//Recursion Challenges
//Challenge-1
//WAP to check if the given array is sorted or not
#include <iostream>
using namespace std;

//Function to check if an array is sorted or not
bool sortedArray(int arr[], int n)
{
    if(n == 1)
    {
        return true;
    }
    bool restArray = sortedArray(arr + 1, n-1);
    if(arr[0] <= arr[1] && restArray)
    {
        return true;
    }
    return false;
}

int main()
{
    int arr[] = {2, 1, 3, 4, 5, 6, 7};
    cout<<sortedArray(arr, 7)<<endl;

    int arr2[] = {1, 2, 3, 4, 5, 6, 7};
    cout<<sortedArray(arr2, 7)<<endl;
    return 0;
}