//Recursion Problem-5
//WAP to move all X elements to the end of string
#include <iostream>
using namespace std;

//Function  with recrusion to move all x elements to end of string
string moveX(string s)
{
    //Checks if the length of s is 0
    if(s.length()==0)
    {
        return "";
    }
    //variable stores the 1st character of string
    char ch= s[0];
    //variable stores the rest of the string
    string ros = moveX(s.substr(1));
    //checks if any character in string is equal to x
    if(ch=='x')
    {
        return (ros+ch); //returns the string that arenot x and then at last puts x  
    }
    return (ch+ros); //returns string the same as it is if no x is found
}

int main()
{
    cout<<moveX("axxbdxcefxhix");
    return 0;
}