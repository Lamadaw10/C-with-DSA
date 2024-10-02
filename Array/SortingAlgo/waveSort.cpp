//WAP to perform the algorithemic implementation of wave sort
#include <iostream>
using namespace std;

void swap(int arr[], int i, int j)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void waveSort(int arr[], int n)
{
    for(int i = 1; i < n; i += 2)
    {
        if(arr[i] > arr[i - 1])
        {
            swap(arr, i, i - 1);
        }
        if(arr[i] > arr[i + 1] && i <= n-2)
        {
            swap(arr, i, i + 1);
        }
    }
}

int main()
{
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;
    int arr[n];
    cout << "Enter the elements of the array: ";
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    waveSort(arr, n);
    cout << "Sorted array: ";
    for(int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}