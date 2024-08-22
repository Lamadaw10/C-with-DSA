/*
//Pointers
//Variables that store the address of another variables
//Declaring pointer to a variable
#include <iostream>
using namespace std;
int main()
{
    int a = 10;
    int *aptr;
    aptr = &a;
    cout<<&a<<endl; //prints the address of itself
    cout<<aptr<<endl; //Prints the address of variable a
    cout<<*aptr<<endl; //Prints the value that a holds
    return 0;
}

//Changing the value of the variable using pointer
#include <iostream>
using namespace std;
int main()
{
    int a = 20;
    int *aptr = &a;
    cout<<*aptr<<endl;
    *aptr = 30;
    cout<<a<<endl;
    return 0;
}

//Pointer Arithmetic (++, --, +, -)
#include <iostream>
using namespace std;
int main()
{
    //IOn integer
    int n = 5;
    int *m = &n;
    cout<<m<<endl;
    m++;
    cout<<m<<endl;

    //In Character
    char ch = 'a';
    char *a = &ch;
    cout<<a<<endl;
    a++;
    cout<<a<<endl;

    return 0;
}

//Pointers in Array
#include <iostream>
using namespace std;

int main()
{
    int arr[] = {10, 20, 30, 40};
    cout<<*arr<<endl; //Prints the first index only

    //For printing all the numbers of aray
    int *ptr = arr;
    for(int i=0;i<4;i++)
    {
        cout<<*ptr<<endl; //prints all number of array
        ptr++; //adds four bytes which makes the index move from 0 to 1 and so on
        cout<<*(arr+i)<<endl; //adds i to the array as array starts from 0 so it increments everytime the i increments
    }

    return 0;
}

//Pointer to pointer
#include <iostream>
using namespace std;
int main()
{
    int a = 10;
    int *p = &a;
    cout<<*p<<endl; //Prints the variable a value
    int **q = &p;
    cout<<*q<<endl; //Prints the address of the value
    cout<<**q<<endl; //Prints the variable p value
    return 0;
}
*/
//Passing pointers to function
#include <iostream>
using namespace std;
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main()
{
    int a=2;
    int b=4;

    swap(&a, &b);
    cout<<a<<" "<<b<<endl;
    retrun 0;
}
