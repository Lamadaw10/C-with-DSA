//To read and write in a file
#include <iostream>
#include <fstream> //use for accessing istream and ostream classes
using namespace std;

int main()
{
    string a;

    //Creation of ofstream class object
    ofstream fout;

    //by default ios::out mode, automatically deletes
    //the content of file.To append the content,open in ios:app
    //fout.open("sample.txt",ios::app)
    fout.open("sample.txt");

    //Executes the loop if the file successfully opens
    while(fout)
    {
        //reads line from standard input
        getline(cin, a);

        //Gets out from loop if the condition is satisfied
        if(a == "-1")
            break;

        //Writes the text that are in a in the file
        fout<<a<<endl;
    }

    //closes the file
    fout.close();

    //creation of ifstream class object
    ifstream fin;

    //by default open mode = ios::in mode
    fin.open("sample.txt");

    //Executes the loop until the end of file (EOF)
    while(getline(fin, a))
    {
        //Displays the a(read from the file)
        cout<<a<<endl;
    }
    //closes the file
    fin.close();

    return 0;
}

//Using fstream class
#include <iostream>
//using fstream for accessing classes of istream and ostream
#include <fstream>
using namespace std;
int main()
{
    string a;
    //Creation of fstream class object
    fstream f;

    //By default open mode = ios::in|ios::out mode
    //Automatically overwrites the content of file. To append
    //the content, open in ios:app
    //f.open("sample.txt",ios::in|ios::out|ios::app)
    //ios::trunc modes deletes all the content before opening
    f.open("sample.txt",ios::trunc|ios::in|ios::out);

    //Executes the loop if file successfully opened
    while(f)
    {
        //Reads the string in standard input
        getline(cin,a);
        //If pressed -1 then loops breaks
        if(a=="-1")
            break;
        //Writes the string in file
        f<<a<<endl;
    }

    //Executes the loop until the EOF(end of file)
    //point read pointer at the beginning of the file
    f.seekg(0, ios::beg);
    while(f)
    {
        //Reads the line from file
        getline(f,a);

        //Prints the line of that file
        cout<<a<<endl;
    }
    f.close();
    return 0;
}

//Tried to make a thangka painters data info
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Thangka
{
private:
    int n;
    struct Painter
    {
        string name;
        int hours;
        double salary;
    };
    Painter* painters;
public:
    Thangka()
    {
        n = 0;
        painters = nullptr;
    }

    ~Thangka()
    {
        delete[] painters;
    }

    void numOfPainters()
    {
        cout << "Enter the number of painters in your company: ";
        cin >> n;
        painters = new Painter[n];
        cin.ignore();  // Clear the newline character from the input buffer
    }

    void getDetails()
    {
        for(int i = 0; i < n; i++)
        {
            cout << "Enter the name of painter: ";
            getline(cin, painters[i].name);
            cout << "Enter the hours the painter is going to work for: ";
            cin >> painters[i].hours;
            cout << "Enter the salary the painter is going to get: ";
            cin >> painters[i].salary;
            cin.ignore();  // Clear the newline character from the input buffer
        }
    }

    void displayNameOnly()
    {
        for(int i = 0; i < n; i++)
        {
            cout << painters[i].name << endl;
        }
    }

    void addPainter()
    {
        int a;
        cout << "Enter the number of painters to add: ";
        cin >> a;
        cin.ignore();  // Clear the newline character from the input buffer

        Painter* newPainters = new Painter[n + a];

        for(int i = 0; i < n; i++)
        {
            newPainters[i] = painters[i];
        }

        delete[] painters;
        painters = newPainters;

        for(int i = n; i < n + a; i++)
        {
            cout << "Enter the name of new painter: ";
            getline(cin, painters[i].name);
            cout << "Enter the hours of that painter: ";
            cin >> painters[i].hours;
            cout << "Enter the salary of the painter: ";
            cin >> painters[i].salary;
            cin.ignore();  // Clear the newline character from the input buffer
        }

        n += a;
    }

    void detailOfPainters()
    {
        ofstream fout("thangka.txt");

        for(int i = 0; i < n; i++)
        {
            fout << i + 1 << "\t" << painters[i].name << "\t" << painters[i].hours << "\t" << painters[i].salary << endl;
        }

        fout.close();

        ifstream fin("thangka.txt");
        string line;

        while(getline(fin, line))
        {
            cout << line << endl;
        }

        fin.close();
    }
};

int main()
{
    Thangka t;
    int choice;

    while (true)
    {
        cout << "\nMenu:\n";
        cout << "1. Enter number of painters\n";
        cout << "2. Get details of painters\n";
        cout << "3. Display names of painters\n";
        cout << "4. Add new painters\n";
        cout << "5. Display details of all painters\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();  // Clear the newline character from the input buffer

        switch(choice)
        {
            case 1:
                t.numOfPainters();
                break;
            case 2:
                t.getDetails();
                break;
            case 3:
                t.displayNameOnly();
                break;
            case 4:
                t.addPainter();
                break;
            case 5:
                t.detailOfPainters();
                break;
            case 6:
                return 0;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}

