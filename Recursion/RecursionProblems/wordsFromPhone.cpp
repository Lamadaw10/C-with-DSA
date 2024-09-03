//Recurion Problem-8
//WAF to print all the possible words from phone digits
#include <iostream>
using namespace std;

string keypad[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
//Function to print all words of phone digits
void printWords(string s, string ans)
{
    if(s.length()==0)
    {
        cout<<ans<<endl;
        return;
    }
    //first character of string
    char ch = s[0];
    
    //Corresponding code for digit
    string code = keypad[ch-'0'];
    
    //rest of string
    string ros = s.substr(1);

    //loop iterates over each character in the code
    for(unsigned int i=0; i<code.size(); i++)
    {
        printWords(ros, ans + code[i]);
    }
}

int main()
{
    printWords("23", "");
    return 0;
}