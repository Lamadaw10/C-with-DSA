//WAP to evaluate postfix expression
//Example: 4 6 + 2 / 5 * 7 +

#include <iostream>
#include <stack>
#include <math.h>
using namespace std;

int postfixExpression(string s)
{
    stack<int> st;
    //Loop iteration for calculating the postfix expression evalutaion
    for(unsigned i=0;i<s.length();i++)
    {
        //Checks if the character are integer numbers
        if(s[i] >= '0' && s[i] <= '9')
        {
            st.push(s[i] - '0'); //push the ASCII value inside stack
        }
        else{
            int op2 = st.top();
            st.pop();
            int op1 = st.top();
            st.pop();

            switch(s[i])
            {
                case '+':
                    st.push(op1 + op2);
                    break;
                case '-':
                    st.push(op1 - op2);
                    break;
                case '*':
                    st.push(op1 * op2);
                    break;
                case '/':
                    st.push(op1 / op2);
                    break;
                case '^':
                    st.push(pow(op1, op2));
                    break;
            }
        }
    }
    return st.top();
}

int main()
{
    cout << postfixExpression("46+2/5*7+") << endl;
    return 0;
}