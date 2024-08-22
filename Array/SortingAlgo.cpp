#include <iostream>
using namespace std;

// Selection Sort
// This algorithm sorts an array by repeatedly finding the minimum element (considering ascending order) from the unsorted part and putting it at the beginning.
void selectionSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] > arr[j])
            {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

// Bubble Sort
// This algorithm repeatedly steps through the list, compares adjacent elements and swaps them if they are in the wrong order. The pass through the list is repeated until the list is sorted.
void bubbleSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Insertion Sort
// This algorithm builds the final sorted array one item at a time. It is much less efficient on large lists than more advanced algorithms such as quicksort, heapsort, or merge sort.
void insertionSort(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;
        // Move elements of arr[0..i-1], that are greater than key, to one position ahead of their current position
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int main()
{
    int n;
    cout << "Enter the number of elements for selection sort: ";
    cin >> n;
    int arr[5];
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    selectionSort(arr, n);
    cout << "Sorted array using Selection Sort: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    int a;
    cout << "Enter the number of elements for bubble sort: ";
    cin >> a;
    int swap[5];
    cout << "Enter the elements: ";
    for (int i = 0; i < a; i++)
    {
        cin >> swap[i];
    }

    bubbleSort(swap, a);
    cout << "Sorted array using Bubble Sort: ";
    for (int i = 0; i < a; i++)
    {
        cout << swap[i] << " ";
    }
    cout << endl;

    int b;
    cout << "Enter the number of elements for insertion sort: ";
    cin >> b;
    int correct[5];
    cout << "Enter the elements: ";
    for (int i = 0; i < b; i++)
    {
        cin >> correct[i];
    }

    insertionSort(correct, b);
    cout << "Sorted array using Insertion Sort: ";
    for (int i = 0; i < b; i++)
    {
        cout << correct[i] << " ";
    }
    cout << endl;

    return 0;
}
