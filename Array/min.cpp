/*
#include <iostream>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }
    int sum=0;
    for(int i=0; i<n; i++)
    {
        sum += arr[i];
    }
    cout<<"Sum is "<<sum<<endl;
    return 0;
}
*/
#include <iostream>
#include <climits>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int kids[n];
    int candy[n];
    for(int i=0; i<n; i++)
    {
        cin>>kids[i];
        cin>>candy[i];
    }
    int maxNo = INT_MIN;
    int maxCandyKid = -1;
    for(int i=0; i<n; i++)
    {
        if(candy[i]>maxNo)
        {
            maxNo = candy[i];
            maxCandyKid = kids[i];
        }
    }
    cout<<maxCandyKid<<" "<<maxNo<<endl;
    return 0;
}
