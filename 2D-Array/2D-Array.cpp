#include <iostream>
using namespace std;
//Function to search the key in 2D array
//arr: 2D array where we search the key
//n: number of rows in the 2D array
//m: number of columns in the 2D array
//key: the number we are finding in the 2D array
bool search(int arr[][100], int n, int m, int key)
{
    bool found = false;
    int r=0, c=m-1; //Starts from top right corner
    while(r<n && c>=0)
    {
        if(arr[r][c] == key) //key found
        {
            cout<<r<<" "<<c<<endl;
            return true;
        }
        else if(arr[r][c] > key) //if the data is greater than key, decrease column to make it go left
        {
            c--;
        }
        else //if the data is less than key, increase row to make it go down
        {
            r++;
        }
    }
    return false; //key not found
}

int main()
{
    int n,m;
    cout<<"Enter the number of rows: ";
    cin>>n;
    cout<<"Enter the number of columns: ";
    cin>>m;
    int arr[100][100]; //declare the 2D array with fixed maximum size of 100x100
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>arr[i][j]; //input the elements of an array
        }
    }

    int key;
    cout<<"Enter the key you are looking for: ";
    cin>>key;

    //Search for the key in array
    if (search(arr, n, m, key))
    {
        cout << "Element found" << endl;
    }
    else
    {
        cout << "Element not found" << endl;
    }
    return 0;
}

//Spiral Order Matrix Traversal
#include <iostream>
using namespace std;
//Function having spiral order matrix working mechanism
//order: 2D array for traversal
//n: number of rows in 2D array
//m: number of columns in 2D array
int traversalOrder(int order[100][100],int n,int m)
{
    int row_start = 0;
    int column_start = 0;
    int row_end = n-1;
    int column_end = m-1;
    //loop for printing the array in spiral order
    while(row_start <= row_end && column_start <= column_end)
    {
        //Travers from left to right along the row_start
        for(int col = column_start;col<=column_end;col++)
        {
            cout<<order[row_start][col]<<" ";
        }
        row_start++;

        //Travers from top to bottom along the column_end
        for(int row = row_start;row<=row_end;row++)
        {
            cout<<order[row][column_end]<<" ";
        }
        column_end--;

        //Travers from right to left along the row_end
        if(row_start<=row_end)//Avoid the double counting rows
        {
            for(int col = column_end;col>=column_start;col--)
            {
                cout<<order[row_end][col]<<" ";
            }
            row_end--;
        }


        //Traverse from bottom to top along the column_start
        if(column_start<=column_end)//Avoid the double counting columns
        {
            for(int row = row_end;row>=row_start;row--)
            {
                cout<<order[row][column_start]<<" ";
            }
            column_start++;
        }
    }
}
int main()
{
    //Inputs the number of rows and columns
    int n,m;
    cout<<"Enter the number of rows: ";
    cin>>n;
    cout<<"Enter the number of columns: ";
    cin>>m;

    //Declaring the 2D array with fixed maximum size to 100x100
    int order[100][100];
    cout<<"Enter numbers below"<<endl;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>order[i][j];
        }
    }
    //Display the spiral order traversal array
    traversalOrder(order,n,m);

    return 0;
}

//2D Array Challenges
//Matrix Transpose
#include <iostream>
using namespace std;

//Function for printing matrix transpose
//matrix: 2D array representing the matrix
//n: number of rows in 2D array
//m: number of columns in 2D array
void matrixTranspose(int matrix[100][100], int n, int m)
{
    for(int i=0;i<n;i++)
    {
        for(int j=i;j<m;j++)
        {
            //swapping the elements in the array
            int temp = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = temp;
        }
    }
}


int main()
{
    //Input for rows and columns
    int n,m;
    cout<<"Enter the number for rows: ";
    cin>>n;
    cout<<"Enter the number for columns: ";
    cin>>m;

    //Declaring the 2D array with fixed maximum size of 100x100
    int matrix[100][100];

    cout<<"Enter the number below: "<<endl;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>matrix[i][j]; //input the element in the array
        }
    }
    //Calls the 2D array of matrix Transpose function
    matrixTranspose(matrix,n,m);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cout<<matrix[i][j]<<" ";//prints the element of the array
        }
        cout<<endl;
    }
    return 0;
}

//Matrix Multiplication
#include <iostream>
using namespace std;
int main()
{
    //Input rows and columns for 2 matrix
    int n1,n2,n3;
    cin>>n1>>n2>>n3;
    int matrix1[n1][n2];
    int matrix2[n2][n3];

    //Input for 1st matrix
    cout<<"Enter the number below for the 1st matrix"<<endl;
    for(int i=0;i<n1;i++)
    {
        for(int j=0;j<n2;j++)
        {
            cin>>matrix1[i][j];
        }
    }

    //Input for 2nd matrix
    cout<<"Enter the number below for the 2nd matrix"<<endl;
    for(int i=0;i<n2;i++)
    {
        for(int j=0;j<n3;j++)
        {
            cin>>matrix2[i][j];
        }
    }

    int ans[n1][n3];
    //Declaring the ans value to 0 as default
    for(int i=0;i<n1;i++)
    {
        for(int j=0;j<n3;j++)
        {
            ans[i][j] = 0;
        }
    }

    //Calculates the multiplication of the matrix
    for(int i=0;i<n1;i++)
    {
        for(int j=0;j<n3;j++)
        {
            for(int k=0;k<n2;k++)
            {
                ans[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }

    //Display the matrix multiplication
    for(int i=0;i<n1;i++)
    {
        for(int j=0;j<n3;j++)
        {
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}

//Character Arrays
//Check Palindrome
#include <iostream>
using namespace std;
int main()
{
    //Input number of character in array
    int n;
    cout<<"Enter the number of characters in array: ";
    cin>>n;

    char arr[n+1];
    cin>>arr;

    bool check = true;
    //Checking if the characters are palindrome or not
    for(int i=0;i<n;i++)
    {
        if(arr[i] != arr[n-i-1])
        {
            return false;
            break;
        }
    }
    //Prints palindrome if the condition is satisfied
    if(check)
    {
        cout<<"Word is palindrome"<<endl;
    }
    else
    {
        cout<<"Word is not palindrome"<<endl;
    }
    return 0;
}

//Largest word in a sentence
#include <iostream>
using namespace std;
int main()
{
    //Input number of character
    int n;
    cout<<"Enter numbers of character in array: ";
    cin>>n;

    char arr[n+1];
    cin.getline(arr, n); //Stores the whole sentence
    cin.ignore(); //Clears the buffer

    int i=0;
    //Declaring the values to 0
    int currlen = 0, maxlen = 0, st = 0, maxst = 0;
    while(1)
    {
        //Checks if the current character is a space or end of the sentence
        if(arr[i] == ' ' || arr[i] == '\0')
        {
            //Checks if the current word is the longest
            if(currlen>maxlen)
            {
                maxlen = currlen;
                maxst = st;
            }

            currlen = 0;//Reset current length for the next word
            st= i+1;//Update start index for the next word
        }
        //Increments the currlen if there are no space
        else
        {
            currlen++;
        }
        //Breaks from the loop if the end of the array has space
        if(arr[i] == '\0')
        {
            break;
        }
        i++;
    }
    //Displays the length of the word
    cout<<maxlen<<endl;
    //Displays the maxlength word
    for(int i=0;i<maxlen;i++)
    {
        cout<<arr[i+maxst]<<endl;
    }
    return 0;
}
