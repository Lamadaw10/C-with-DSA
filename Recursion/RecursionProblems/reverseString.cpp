//Recursion Problem-1
//WAP to reverse a string using recursion
#include <iostream>
using namespace std;

//Function with recursion to reverse a string
void reverseString(string s)
{
    //Checks if the length of the string is equal to 0
    if(s.length() == 0)
    {
        return;
    }
    string ros = s.substr(1); //substring used to start the string with 1
    //Recursion used as function is called by itself
    reverseString(ros); //after the function call itself the string starts with 2nd char from a string
    cout << s[0];
}

int main()
{
    reverseString("dawa");
    cout<<endl;
    return 0;
}