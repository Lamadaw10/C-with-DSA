//Recursion Problem-2
//WAP to replace the pi with 3.14 in string
#include <iostream>
using namespace std;

//Function with recursion to replace pi with 3.14
void replacePi(string s)
{
    //Checks if the length of s is equal to 0
    if(s.length() == 0)
    {
        return;
    }
    //Checks if the first letter is p and second letter is i
    if(s[0]=='p' && s[1] == 'i')
    {
        cout << "3.14";
        replacePi(s.substr(2)); //if the condition is satisfied then strings starts with 3rd character
    }
    else
    {
        cout<<s[0];
        replacePi(s.substr(1)); //else string starts with 2nd character
    }
}

int main()
{
    replacePi("pippxxppiixipi");
    return 0;
}