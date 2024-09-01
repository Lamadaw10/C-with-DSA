// Write a program to check if given number is power of 2
#include <iostream>
using namespace std;
bool powerOfTwo(int n)
{
    int min = n-1;
    return (n && !(n & min)); //returns 0 if the n & n-1 is 1 and 1 if the n & n-1 is 0 due to ! sign 
}
int main()
{
    cout<<powerOfTwo(16)<<endl;
    return 0;
}
//Write a program to count the number of ones in binary representation of numbers
#include <iostream>
using namespace std;
int numOfOnes(int n)
{
    int count = 0;
    //loop iterates untill the n becomes zero
    while(n)
    {
        int min = n-1;
        n = n & min; //calculates n value by using & operator with min(n-1)
        count++;
    }
    return count;
}
int main()
{
    cout<<numOfOnes(16)<<endl;
    return 0;
}

//Write a program to generate all possible subsets of set
#include <iostream>
using namespace std;
void subSets(int arr[], int n)
{
    for(int i=0; i<(1<<n); i++)
    {
        for(int j=0; j<n; j++)
        {
            if(i & (1<<j))
            {
                cout<<arr[j]<<" ";
            }
        }
        cout<<endl;
    }
}
int main()
{
    int arr[] = {1, 2, 3, 4};
    subSets(arr,4);
    return 0;
}

//Write a program to find a unique number in an array where all numbers except one, are present twice
#include <iostream>
using namespace std;
//Function for finding the unique number in an array
int findUniqueNum(int arr[], int n)
{
    int uniqueNum = 0;
    //loop iterates over the array
    for(int i=0;i<n;i++)
    {
        //calculates the uniqueNum by using XOR(^) operator
        uniqueNum = uniqueNum ^ arr[i];
    }
    return uniqueNum;
}
int main()
{
    int arr[] = {2, 3, 5, 4, 5, 3, 2};
    cout<<findUniqueNum(arr,7)<<endl;
    return 0;
}

//Write a program to find 2 unique numbers in an array where all numbers except for two, are present twice
#include <iostream>
using namespace std;
//Function for checking if the element in array is unique or not
int setBit(int n, int pos)
{
    return ((n & (1<<pos)) != 0);
}
void findTwoUniqueNums(int arr[], int n)
{
    int sum = 0;
    //loop iterates over the array
    for(int i=0; i<n; i++)
    {
        sum = sum ^ arr[i]; //calculates XOR of unique elements in sum
    }
    int prevSum = sum; //Storing sum value in new variable for incoming use
    int pos = 0;
    int setbit = 0;
    //loop iterates until setbit is  equal to 1
    while(setbit != 1)
    {
        setbit = sum & 1; //calculates sum using & with 1 to check if setbit is 1 or not 
        pos++; //incrments pos everytime the loop runs by 1
        sum = sum >> 1; //shifts right for 1 each time the loop runs
    }
    int firstUniqueNum = 0;
    //loop iterates over the array to ind the unique num
    for(int i=0; i<n; i++)
    {
        //checks the element is setbit or not
        if(setBit(arr[i], pos-1))
        {
            firstUniqueNum = firstUniqueNum ^ arr[i];
        }
    }
    cout<<"First Unique Number is "<<firstUniqueNum<<endl;
    cout<<"Second Unique NUmber is "<<(prevSum ^ firstUniqueNum)<<endl;
}
int main()
{
    int arr[] = {1, 3, 5, 6, 5, 7, 3, 1};
    findTwoUniqueNums(arr,8);
    return 0;
}

//Write a program to find a unique number in an array where all number except one are present in thrice
#include <iostream>
using namespace std;

// Function to check if a specific bit is set
bool getBit(int n, int pos)
{
    return ((n & (1<<pos)) != 0);
}
//Function to set a specific bit
int setBit(int n, int pos)
{
    return (n | (1<<pos));
}
//Function to find the unique number in an array
int uniqueNum(int arr[], int n)
{
    int result = 0; //Variable to store unique number
    //loop over each bit position (0 to 63 for standard int)
    for(int i=0; i<64; i++)
    {
        int sum = 0; //to count how many numbers have i-th bit set
        for(int j=0; j<n; j++)
        {
            if(getBit(arr[j],i)) //checks if the i-th bit is set in arr[j]
            {
                sum++; //increment the sum if the bit is set
            }
        }

        // If the count of the set bits at position i is not a multiple of 3,
        // it means the unique number has this bit set
        if(sum%3 != 0)
        {
            result = setBit(result, i); //set the i-th bit in the result
        }
    }
    return result;
}
int main()
{
    int arr[] = {1, 3, 2, 3, 4, 2, 1, 1, 3, 2};
    cout<<"Unique Number is "<<uniqueNum(arr, 10)<<endl;
    return 0;
}
