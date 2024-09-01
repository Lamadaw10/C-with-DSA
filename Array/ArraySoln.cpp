
#include <iostream>
#include <climits>
using namespace std;

class arr {
private:
    int n;
    int *a;
    int *b;
    int *c;
    int *d;
    int *e;
    int *f;

public:
    // Function to get the number of elements in the array
    void numOfArray() {
        cout << "Enter the number of elements in the array: ";
        cin >> n;
    }

    // Function to get the array elements from the user
    void getArray() {
        a = new int[n];
        cout << "Enter the array elements:" << endl;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
    }

    // Function to print the maximum number from the array
    void getMax() {
        int maxNum = INT_MIN;
        for (int i = 0; i < n; i++) {
            maxNum = max(maxNum, a[i]);
        }
        cout << "Maximum number: " << maxNum << endl;
    }

    // Function to print the total sum of subarrays
    void getSumSubArray() {
        int sum = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                sum += a[j];
            }
        }
        cout << "Sum of subarrays: " << sum << endl;
    }

    // Function to get the array elements for longest arithmetic subarray
    void getNumOfArr() {
        b = new int[n];
        cout << "Enter the numbers for finding the longest arithmetic subarray:" << endl;
        for (int i = 0; i < n; i++) {
            cin >> b[i];
        }
    }

    // Function to print the length of the longest arithmetic subarray
    void longestSubArray() {
        if (n < 2) {
            cout << "Longest arithmetic subarray length: 0" << endl;
            return;
        }

        int ans = 2;
        int pd = b[1] - b[0];
        int curr = 2;

        for (int j = 2; j < n; j++) {
            if (pd == b[j] - b[j - 1]) {
                curr++;
            } else {
                pd = b[j] - b[j - 1];
                curr = 2;
            }
            ans = max(ans, curr);
        }
        cout << "Longest arithmetic subarray length: " << ans << endl;
    }

    // Function to get the array elements for record breaking day
    void getNumberOfArray() {
        c = new int[n];
        cout << "Enter the numbers for finding the record breaking day:" << endl;
        for (int i = 0; i < n; i++) {
            cin >> c[i];
        }
    }

    // Function to print the number of record breaking days
    void recordBreakingDay() {
        if (n == 1) {
            cout << "1" << endl;
            return;
        }

        int ans = 0;
        int mx = -1;

        for (int i = 0; i < n; i++) {
            if (c[i] > mx && (i == n - 1 || c[i] > c[i + 1])) {
                ans++;
            }
            mx = max(mx, c[i]);
        }
        cout << "Number of record breaking days: " << ans << endl;
    }

    // Function to get the array elements for first repeating element
    void getNum() {
        d = new int[n];
        cout << "Enter the numbers to find the first repeating element:" << endl;
        for (int i = 0; i < n; i++) {
            cin >> d[i];
        }
    }

    // Function to print the first repeating element's index
    void firstRepeatingElement() {
        const int N = 1e6 + 2;
        int idx[N];
        for (int i = 0; i < N; i++) {
            idx[i] = -1;
        }

        int minidx = INT_MAX;
        for (int i = 0; i < n; i++) {
            if (idx[d[i]] != -1) {
                minidx = min(minidx, idx[d[i]]);
            } else {
                idx[d[i]] = i;
            }
        }

        if (minidx == INT_MAX) {
            cout << "-1" << endl;
        } else {
            cout << "First repeating element index: " << minidx + 1 << endl;
        }
    }

    // Function to get the array elements for subarray with given sum
    void getSubArr() {
        e = new int[n];
        cout << "Enter the numbers to find the subarray with given sum:" << endl;
        for (int i = 0; i < n; i++) {
            cin >> e[i];
        }
    }

    // Function to print the subarray with the given sum
    void subArray() {
        int s;
        cout << "Enter the sum you want to search for in the subarray: ";
        cin >> s;

        int i = 0, j = 0, sum = 0;
        while (j < n && sum + e[j] <= s) {
            sum += e[j];
            j++;
        }

        if (sum == s) {
            cout << "Subarray indices: " << i + 1 << " " << j << endl;
            return;
        }

        while (j < n) {
            sum += e[j];
            while (sum > s) {
                sum -= e[i];
                i++;
            }
            if (sum == s) {
                cout << "Subarray indices: " << i + 1 << " " << j + 1 << endl;
                return;
            }
            j++;
        }
        cout << "No subarray with given sum found" << endl;
    }

    // Function to get the array elements for smallest positive missing number
    void getNumber() {
        f = new int[n];
        cout << "Enter the numbers to get the smallest positive missing number:" << endl;
        for (int i = 0; i < n; i++) {
            cin >> f[i];
        }
    }
        // Function to print the smallest positive missing number
    void smallPositiveNum() {
        const int N = 1e6 + 2;
        bool check[N];
        for (int i = 0; i < N; i++) {
            check[i] = false;
        }

        for (int i = 0; i < n; i++) {
            if (f[i] >= 0 && f[i] < N) {
                check[f[i]] = true;
            }
        }

        int num = -1;
        for (int i = 1; i < N; i++) {
            if (!check[i]) {
                num = i;
                break;
            }
        }
        cout << "Smallest positive missing number: " << num << endl;
    }
};

int main() {
    arr ar;

    ar.numOfArray();
    ar.getArray();
    ar.getMax();
    ar.getSumSubArray();

    ar.getNumOfArr();
    ar.longestSubArray();

    ar.getNumberOfArray();
    ar.recordBreakingDay();

    ar.getNum();
    ar.firstRepeatingElement();

    ar.getSubArr();
    ar.subArray();

    ar.getNumber();
    ar.smallPositiveNum();

    return 0;
}
