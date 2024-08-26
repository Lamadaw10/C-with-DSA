//Implementation of inseriton sorting algorithm
#include <iostream>
using namespace std;

void insertionSort(int arr[], int n)
{
    for(int i=1;i<n;i++)
    {
        int counter = arr[i];
        int j = i-1;
        while(arr[j]>counter && j>=0)
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = counter;
    }
}

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    insertionSort(arr,n);
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}

//
#include <iostream>
#include <climits>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int a[n+1];
    a[n] = -1;

    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }

    if(n == 1)
    {
        cout<<"1";
        return 0;
    }

    int ans = 0;
    int mx = -1;
    for(int i=0;i<n;i++)
    {
        if(a[i]>mx && a[i]>a[i+1])
        {
            ans++;
        }
        mx = max(mx, a[i]);
    }
    cout<<ans<<endl;
    return 0;
}

