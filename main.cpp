#include <iostream>
#include <string>
using namespace std;

void printArray(char arr[][3], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout<<"|";
        for (int j = 0; j < n; j++)
        {
            cout << arr[i][j] << "|";
        }
        cout << endl;
    }

    cout << "--------------------------------" << endl;
}

void game(char arr[3][3]);

void restart(char arr[3][3],int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            arr[i][j] = ' ';
        }
    }

    game(arr);

}


void winner(char arr[3][3])
{
    int n = 3;
    char p1 = 'X';
    char p2 = 'O';
    int j = 0;
    int flag = 0;
    for (int i = 0; i < n; i++)
    {
        
            if( arr[i][j] == p1 && arr[i][j+1]==p1 && arr[i][j+2] == p1)
            {
                cout<<"Player X wins"<<endl;
                printArray(arr, n);
                flag = 1;
                break;
            }

            else if( arr[i][j] == p2 && arr[i][j+1]==p2 && arr[i][j+2] == p2)
            {
                cout<<"Player O wins"<<endl;
                printArray(arr, n);
                flag = 1;
                
                break;
            }
        
    }

    int i = 0;

    for (int j = 0; j < n; j++)
    {
        
            if( arr[i][j] == p1 && arr[i+1][j]==p1 && arr[i+2][j] == p1)
            {
                cout<<"Player X wins"<<endl;
                printArray(arr, n);
                 flag = 1;
                break;
            }

            else if( arr[i][j] == p2 && arr[i+1][j]==p2 && arr[i+2][j] == p2)
            {
                cout<<"Player O wins"<<endl;
                printArray(arr, n);
                 flag = 1;
               break;
            }
        
    }


    if(arr[0][0] == p1 && arr[1][1] == p1 && arr[2][2]==p1)
    {
        cout<<"Player X wins"<<endl;
         flag = 1;
        printArray(arr, n);

    }

    else if(arr[0][0] == p2 && arr[1][1] == p2 && arr[2][2]==p2)
    {
        cout<<"Player O wins"<<endl;
         flag = 1;
        printArray(arr, n);

    }
    
    else if(arr[0][2] == p1 && arr[1][1] == p1 && arr[2][0]==p1)
    {
        cout<<"Player X wins"<<endl;
         flag = 1;
        printArray(arr, n);

    }

    else if(arr[0][2] == p2 && arr[1][1] == p2 && arr[2][0]==p2)
    {
        cout<<"Player X wins"<<endl;
         flag = 1;
        printArray(arr, n);

    }

    if(flag ==1)
    {

    

    char t = ' ';

    cout<<"Do you want to restart the game ? (Y/N)"<<endl;
    cin>>t;

    if(t == 'y' || t =='Y')
    {
        cout<<"...........New Game..............."<<endl;
        restart(arr,n);
    }
    else
    {
        cout<<"Game ended...."<<endl;
        exit(0);
    }

    }



}

void Xgame(char arr[3][3])
{
    char p1 = 'X';
    int row, col;
    cout << "Enter value for X" << endl;
    cin >> row >> col;
    if (arr[row][col] != ' ')
    {
        cout << "Invalid command try again.." << endl;
        Xgame(arr);
    }
    else if (row > 3 || col > 3)
    {
        cout << "Invalid command try again.." << endl;
        Xgame(arr);
    }
    else
    {
        arr[row][col] = p1;
        printArray(arr, 3);
        winner(arr);
    }
}

void Ogame(char arr[3][3])
{
    char p2 = 'O';
    int row, col;
    cout << "Enter value for O" << endl;

    cin >> row >> col;
    if (arr[row][col] != ' ')
    {
        cout << "Invalid command try again.." << endl;
        Ogame(arr);
    }

    else if (row > 3 || col > 3)
    {
        cout << "Invalid command try again.." << endl;
        Ogame(arr);
    }
    else
    {
        arr[row][col] = p2;
        printArray(arr, 3);
        winner(arr);
    }
}

void game(char arr[][3])
{
    while (1)
    {

        Xgame(arr);
        
        Ogame(arr);
      
    }
}

int main()
{
    char arr[3][3];
    int n = 3;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            arr[i][j] = ' ';
        }
    }
    
    cout<<"............Welcome to Tic Tac Toe game..........."<<endl;
    cout<<endl;
    printArray(arr, 3);
    cout<<endl;
    

    game(arr);
}