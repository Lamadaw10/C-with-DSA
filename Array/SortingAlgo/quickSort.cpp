//Quick Sort Alogrithm Implementation
#include <iostream>
using namespace std;

//Function to perform swapping of elements
void swap(int arr[], int i, int j)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

//Function to find the pivot element
int partition(int arr[], int l, int r)
{
    int pivot = arr[r];
    int i = l - 1;
    for (int j = l; j < r; j++)
    {
        if(arr[j] < pivot)
        {
            i++;
            swap(arr, i, j);
        }
    }
    swap(arr, i+1, r);
    return i+1;
}

//Function to perform quick sort 
void quickSort(int arr[], int l, int r)
{
    if (l < r) 
    {
        int pi = partition(arr, l, r); // Partitioning around pivot element

        quickSort(arr, l, pi - 1);
        quickSort(arr, pi + 1, r);
    }
}

int main()
{
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    quickSort(arr, 0, n-1);
    cout << "Sorted array: ";
    for(int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}