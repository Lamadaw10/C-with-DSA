//Problem-1
//Finding the prime numbers till n using Sieve of Eratosthenes method
#include <iostream>
using namespace std;
//Function finds and prints the prime numbers of a given number
void primeSieve(int n)
{
    int prime[100] = {0}; //initiating the prime variable to 0
    //Loop iterates from 2 to n
    for(int i=2; i<=n; i++)
    {
        //to check if the given number is marked or not
        if(prime[i] == 0)
        {
            //Loop iterats from square of i to n
            for(int j=i*i; j<=n; j+=i)
            {
                prime[j] = 1; //marking the number as composite
            }
        }
    }
    //Printing the prime numbers
    for(int i=2; i<=n; i++)
    {
        //to find the unmarked numbers and print them
        if(prime[i] == 0)
        {
            cout << i << " ";
        }
    }
    cout<<endl;
}

int main()
{
    int range;
    cout<<"Enter the number to find the total prime numbers of it: ";
    cin>>range;

    //Calls the function to print the prime numbers using Sieve method
    primeSieve(range);

    return 0;
}

//Problem-2
//Prime Factorisation using Sieve
//Finding the smallest prime factor of a given number
#include <iostream>
using namespace std;

//Function finds and prints the smallest prime factor of n
void primeFactor(int n)
{
    int spf[100] = {0};
    for(int i=2; i<=n; i++)
    {
        //As the variable spf and i are similar 
        spf[i] = i;
    }

    for(int i=2; i<=n; i++)
    {
        //If spf[i] is not changed, then spf[i] is a prime number
        if(spf[i] == i)
        {
            //Update spf[j] if it is a multiple of i
            for(int j=i*i; j<=n; j=j+i)
            {
                if(spf[j] == j)
                {
                    spf[j] = i;
                }
            }
        }
    }

    //Loop to print out the smallest prime factor
    while(n != 1)
    {
        cout<<spf[n]<<" ";
        n = n/spf[n];
    }
}

int main()
{
    int range;
    cout<<"Enter the number that you want to find the smallest prime factor of: ";
    cin>>range;

    primeFactor(range);
    return 0;
}
