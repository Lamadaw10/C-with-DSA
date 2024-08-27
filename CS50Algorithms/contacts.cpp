#include <iostream>
#include <string>
using namespace std;

struct person
{
    string name;
    string number;
};

int main()
{
    person people[3];

    people[0].name = "Darrek";
    people[0].number = "+977-9811111111";

    people[1].name = "Sam";
    people[1].number = "+977-9722222222";

    people[2].name = "Harry";
    people[2].number = "+977-9833333333";

    string name;
    cout<<"Name: ";
    cin>>name;

    bool found = false;
    for(int i=0; i<3; i++)
    {
        if(people[i].name == name)
        {
            found = true;
            cout<<"Found: ";
            cout<<people[i].number;
            break;
        }
    }

    if(!found)
    {
        cout<<"Name is not found in the list.";
    }
    return 0;
}