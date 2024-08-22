#include <iostream>
using namespace std;

class Algorithm {
private:
    int n;       // Number of elements in the array
    int *arr;    // Pointer to dynamically allocated array

public:
    // Function to input array elements from the user
    void getArr() {
        cout << "Enter how many numbers you want in the array: ";
        cin >> n;
        arr = new int[n]; // Allocate memory for n elements
        cout << "Enter the numbers: ";
        for (int i = 0; i < n; ++i) {
            cin >> arr[i];
        }
    }

    // Function to perform selection sort on the array
    void getSelectionSort() {
        int temp;
        for (int i = 0; i < n - 1; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (arr[j] < arr[i]) {
                    temp = arr[j];
                    arr[j] = arr[i];
                    arr[i] = temp;
                }
            }
        }
    }

    // Function to print the array after selection sort
    void selectionSort() const {
        for (int i = 0; i < n; ++i) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    // Function to perform bubble sort on the array
    void getBubbleSort() {
        int temp;
        for (int i = 0; i < n - 1; ++i) {
            for (int j = 0; j < n - i - 1; ++j) {
                if (arr[j] > arr[j + 1]) {
                    temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
        }
    }

    // Function to print the array after bubble sort
    void bubbleSort() const {
        for (int i = 0; i < n; ++i) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    // Function to perform insertion sort on the array
    void getInsertionSort() {
        for (int i = 1; i < n; ++i) {
            int key = arr[i];
            int j = i - 1;
            while (j >= 0 && arr[j] > key) {
                arr[j + 1] = arr[j];
                j--;
            }
            arr[j + 1] = key;
        }
    }

    // Function to print the array after insertion sort
    void insertionSort() const {
        for (int i = 0; i < n; ++i) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    // Destructor to free dynamically allocated memory
    ~Algorithm() {
        delete[] arr;
    }
};

int main() {
    Algorithm a1;
    a1.getArr();  // Input array elements

    cout << "Selection Sort: ";
    a1.getSelectionSort();  // Perform selection sort
    a1.selectionSort();     // Print sorted array

    cout << "Bubble Sort: ";
    a1.getBubbleSort();     // Perform bubble sort
    a1.bubbleSort();        // Print sorted array

    cout << "Insertion Sort: ";
    a1.getInsertionSort();  // Perform insertion sort
    a1.insertionSort();     // Print sorted array

    return 0;
}
