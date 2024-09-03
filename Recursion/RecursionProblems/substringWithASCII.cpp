//Recursion Problem-7
//WAF that generates substrings with ASCII number
#include <iostream>
using namespace std;

//Function with recursion to generate substring with ASCII
void subASCII(string s, string ans)
{
    //checks the length of s is equal to 0
    if (s.length() == 0)
    {
        cout<<ans<<endl;
        return;
    }
    char ch = s[0];
    int code = ch; //holds the integer value of ch
    string ros = s.substr(1);

    //Recursion used to generate substring first
    subASCII(ros,ans);
    subASCII(ros,ans+ch); //calls the last character of string
    
    //Generates integer to string in ASCII number
    subASCII(ros,ans + to_string(code)); 
}

int main()
{
    subASCII("AB", " ");
    return 0;
}