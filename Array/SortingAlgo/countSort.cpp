//WAP to find count of every distinct element in array
//And Calculate position of each element in sorted array
#include <iostream>
#include <vector>
using namespace std;

//Function to perform count sorting algorithm
void countSort(int arr[], int n)
{
    // Step 1: Find the maximum element in the array
    int maxNum = arr[0];
    for(int i = 1; i < n; i++) {
        maxNum = max(maxNum, arr[i]);
    }

    // Step 2: Create and initialize the count array based on the maximum element
    vector<int> count(maxNum + 1, 0);  // Count array size is maxNum + 1

    // Step 3: Store the occurrences of each element in the count array
    for(int i = 0; i < n; i++) {
        count[arr[i]]++;
    }

    // Step 4: Calculate the cumulative count (prefix sum)
    for(int i = 1; i <= maxNum; i++) {
        count[i] += count[i - 1];
    }

    // Step 5: Build the output array based on the count array
    int output[n];
    for(int i = n - 1; i >= 0; i--) {
        output[--count[arr[i]]] = arr[i];
    }

    // Step 6: Copy the sorted elements back into the original array
    for(int i = 0; i < n; i++) {
        arr[i] = output[i];
    }

    // Step 7: Print the occurrences of distinct elements
    cout << "Occurrences of distinct elements:\n";
    vector<int> distinct(maxNum + 1, 0);
    for (int i = 0; i < n; i++) {
        if (distinct[arr[i]] == 0) {
            int element = arr[i];
            int occurrences = 0;
            for (int j = 0; j < n; j++) {
                if (arr[j] == element) 
                {
                    occurrences++;
                }
            }
            cout << element << ": " << occurrences << " times\n";
            distinct[element] = 1;
        }
    }
}

int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    int arr[n];
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Sort the array and calculate occurrences of distinct elements
    countSort(arr, n);

    // Output the sorted array
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}