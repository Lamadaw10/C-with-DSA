//Patterns using for loops and if condition
#include <iostream>
using namespace std;

class patterns
{
int n;
public:
    void numOfPatterns()
    {
        cout<<"Enter the number of patterns you want to make: ";
        cin>>n;
    }
    void rightAngledTriangle()
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=i;j++)
            {
                cout<<"*";
            }
            cout<<endl;
        }
    }

    void revRightAngledTriangle()
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n-i;j++)
            {
                cout<<" ";
            }
            for(int j=1;j<=i;j++)
            {
                cout<<"*";
            }
            cout<<endl;
        }
    }

    void fullTriangle()
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n-i;j++)
            {
                cout<<" ";
            }
            for(int j=1;j<=2*i-1;j++)
            {
                cout<<"*";
            }
            cout<<endl;
        }
    }

    void nepalFlag()
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=i;j++)
            {
                if((i==3 && j==2) || (j==2 || j==3) && i==4)
                {
                    cout<<" ";
                }
                else
                {
                    cout<<"*";
                }
            }
            cout<<endl;
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=i;j++)
            {
                if((i==3 && j==2) || (j==2 || j==3) && i==4)
                {
                    cout<<" ";
                }
                else
                {
                    cout<<"*";
                }
            }
            cout<<endl;
        }
        for(int i=1;i<=5;i++)
        {
            for(int j=1;j<=2;j++)
            {
                cout<<"*";
            }
            cout<<endl;
        }
    }

    void butterfly()
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=i;j++)
            {
                cout<<"*";
            }
            for(int j=1;j<=2*n - 2*i;j++)
            {
                cout<<" ";
            }
            for(int j=1;j<=i;j++)
            {
                cout<<"*";
            }
            cout<<endl;
        }
        for(int i=n;i>=1;i--)
        {
            for(int j=1;j<=i;j++)
            {
                cout<<"*";
            }
            for(int j=1;j<=2*n - 2*i;j++)
            {
                cout<<" ";
            }
            for(int j=1;j<=i;j++)
            {
                cout<<"*";
            }
            cout<<endl;
        }
    }

    void numTriangle()
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n-i;j++)
            {
                cout<<" ";
            }
            int k=i;
            for(int j=1;j<=i;j++)
            {
                cout<<k--;
            }
            k=2;
            for(int j=2;j<=i;j++)
            {
                cout<<k++;
            }
            cout<<endl;
        }
    }
};

int main()
{
    patterns p1;
    p1.numOfPatterns();
    p1.rightAngledTriangle();
    p1.revRightAngledTriangle();
    p1.fullTriangle();
    p1.nepalFlag();
    p1.butterfly();
    p1.numTriangle();

    return 0;
}
