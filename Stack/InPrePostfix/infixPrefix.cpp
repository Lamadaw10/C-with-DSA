//WAP to transform infix to prefix
//Example:(a-b/c)*(a/k-l)
#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

int prec(char c)
{
    if (c == '^')
    {
        return 3;
    }
    else if (c == '/' || c == '*')
    {
        return 2;
    }
    else if (c == '+' || c == '-')
    {
        return 1;
    }
    else
    {
        return -1;
    }
}

string infixPrefix(string s)
{
    // Reverse the input string
    reverse(s.begin(), s.end());

    // Switch parentheses
    for (unsigned int i = 0; i < s.length(); i++)
    {
        if (s[i] == '(')
        {
            s[i] = ')';
        }
        else if (s[i] == ')')
        {
            s[i] = '(';
        }
    }

    stack<char> st;
    string res;

    for (unsigned int i = 0; i < s.length(); i++)
    {
        // If the character is an operand, add it to the result
        if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z'))
        {
            res += s[i];
        }
        // If '(' is encountered, push to stack
        else if (s[i] == '(')
        {
            st.push(s[i]);
        }
        // If ')' is encountered, pop until '(' is found
        else if (s[i] == ')')
        {
            while (!st.empty() && st.top() != '(')
            {
                res += st.top();
                st.pop();
            }
            if (!st.empty())
            {
                st.pop();
            }
        }
        // An operator is encountered
        else
        {
            while (!st.empty() && prec(s[i]) <= prec(st.top()))
            {
                res += st.top();
                st.pop();
            }
            st.push(s[i]);
        }
    }

    // Pop all the remaining operators from the stack
    while (!st.empty())
    {
        res += st.top();
        st.pop();
    }

    // Reverse the result to get the prefix expression
    reverse(res.begin(), res.end());

    return res;
}

int main()
{
    cout << infixPrefix("(a-b/c)*(a/k-l)") << endl; // Expected output: "*-a/bc-/akl"
    return 0;
}
