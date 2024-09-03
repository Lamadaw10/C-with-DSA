//Recursion Problem-4
//Same type of problem in LeetCode
//WAP to remove all duplicates from the string
#include <iostream>
using namespace std;

//Function with recursion to remove duplicates from the stirng
string removeDuplicates(string s)
{
    //Checks if the length of string is equal to 0
    if(s.length() == 0)
    {
        return "";
    }
    //variable stores the first character of the string
    char ch = s[0];
    //variable stores the all characters of string starting from 2nd character
    string rest = removeDuplicates(s.substr(1));
    //checks if the first character of string is same as 2nd character
    if(ch == rest[0])
    {
        return rest;
    }
    return (ch+rest);
}

int main()
{
    cout<<removeDuplicates("aaaabbbeeeecdddd");
    return 0;
}