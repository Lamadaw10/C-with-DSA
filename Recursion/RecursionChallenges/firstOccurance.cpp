//Challenges-3
//WAP to find the first occurance of a number in an array
#include <iostream>
using namespace std;

//Function finds the first occurance of a number
int findFirstOccurance(int arr[], int n, int num, int key)
{
    //checks if the num is equal to n
    if(num == n)
    {
        return -1; //returns -1 if num is equal to n
    }
    //checks if there is a key in the array
    if(arr[num] == key)
    {
        return num;
    }
    return findFirstOccurance(arr, n, num+1, key);
}

//Function finds the last occurance of a number
int findLastOccurance(int arr[], int n, int num, int key)
{
    //checks if the num is equal to n
    if(num == n)
    {
        return -1; //returns -1 if num is equal to n
    }
    int restArray = findLastOccurance(arr,n,num+1,key);
    if(restArray != -1)
    {
        return restArray;
    }
    if(arr[num] == key)
    {
        return num;
    }
    return -1;
}

int main()
{
    int arr[] = {4, 2, 1, 2, 5, 2, 7};
    cout<<findFirstOccurance(arr, 7, 0, 2)<<endl;

    cout<<findLastOccurance(arr, 7, 0, 2)<<endl;

    return 0;
}