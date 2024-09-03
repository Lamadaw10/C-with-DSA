//Recursion Problem-3
//WAP to make move of elements from a src to a destination
#include <iostream>
using namespace std;

//Function with recursion to print elements move from a src to destination
void towerOfHanoi(int n, char src, char helper, char dest)
{
    //checks if the n is equal to 0
    if(n==0)
    {
        return;
    }
    
    //move n-1 elements from src to helper
    towerOfHanoi(n-1,src,dest,helper);

    //Prints the movement of elements
    cout<<"Move elements from "<<src<<" to "<<dest<<endl;
    
    //move nth element from src to dest
    towerOfHanoi(n-1,src,helper,dest);
}

int main()
{
    towerOfHanoi(3, 'A', 'B', 'C');
    return 0;
}