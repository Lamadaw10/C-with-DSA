//Strings
//1.Declaring string using getline
//2.ADD FUNCTION
//3.PRINT 2ND WORD
//4.CLEAR THE STRING
//5.COMPARE TWO STRING
//6.CHECK IF THE STRING IS EMPTY OR NOT
//7.DELETE CHARACTER FROM STRING
//8.FINDING CHARACTER FROM STRING
//9.INSERTING CHARACTER IN STRING
//10.LENGTH OF STRING
//11.SUBSTRING
//12.CONVERTING STRING TO INTEGER
//13.CONVERTING INTEGER TO STRING
//14.SORTING STRING
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

void declare()
{
    string str;
    cout<<"Enter any string here: ";
    getline(cin, str);
    cout<<str<<endl;
}

void append(string a, string b)
{
    a.append(b);
    cout<<a<<endl;
}

void clears(string c)
{
    c.clear();
    cout<<c<<endl;
}

void compare(string d,string e)
{
    if(d.compare(e) == 0)
    {
        cout<<"string is equal"<<endl;
    }
    else
    {
        cout<<"String is not equal"<<endl;
    }
}

void nothing(string f)
{
    f.clear();
    if(f.empty())
    {
        cout<<"String is empty"<<endl;
    }
    else
    {
        cout<<"String is not empty"<<endl;
    }
}

void delet(string g)
{
    g.erase(4,2);
    cout<<g<<endl;
}

void finding(string h)
{
    cout<<h.find("com")<<endl;
}

void inserting(string i)
{
    i.insert(5, "gg");
    cout<<i<<endl;
}

void length(string j)
{
    cout<<j.length()<<endl;
    for(int i=0;i<j.size();i++)
    {
        cout<<j[i]<<endl;
    }
}


int main()
{
    string s1 = "fam";
    string s2 = "ily";
    string s3 = "I wanna go there";
    string s4 = "nincompoop";
    string s5 = "1256";
    int gg = 123;
    string s6 = "xcmnmvzcxmfas";

    declare();
    append(s1,s2);
    clears(s4);
    compare(s1,s2);
    nothing(s4);
    delet(s4);
    finding(s4);
    inserting(s4);
    length(s4);
    //substring(s4);
    //strtoint(s5);
    //inttostr(gg);
    //sorting(s6);

    return 0;
}

