//Recursion Problems-6
//WAP to generate the substring of a string
//Eg: Input = ABC
//Output = { , A, B, C, AB, BC, AC, ABC}
#include <iostream>
using namespace std;

//Function with recursion to generate substring of a string
void subseq(string s, string ans)
{
    //checks the length of string is equal to 0
    if (s.length() == 0)
    {
        cout<<ans<<endl;
        return;
    }
    char ch = s[0];
    //stores rest of string starts from 2nd character in ros 
    string ros = s.substr(1);
    
    //Recursion used to get the substring of the string
    subseq(ros, ans);
    subseq(ros, ans+ch);
}

int main()
{
    subseq("ABC"," ");
    return 0;
}