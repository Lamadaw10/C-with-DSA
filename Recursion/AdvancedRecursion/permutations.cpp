//Advanced Recursion Problem-1
//WAF to print all possible permutations of a string
#include <iostream>
using namespace std;

//Function to find possible permutation of string
void permutation(string s, string ans)
{
    //check if the length of s is equal to 0
    if(s.length() == 0)
    {
        cout<<ans<<endl;
        return;
    }

    //Loop iterates over s and finds possible permutation of s
    for(unsigned int i=0; i<s.length(); i++)
    {
        char ch = s[i];
        string ros = s.substr(0, i) + s.substr(i+1);

        permutation(ros, ans+ch);
    }
}

int main()
{
    permutation("ABC", "");
    return 0;
}