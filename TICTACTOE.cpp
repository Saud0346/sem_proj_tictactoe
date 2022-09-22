#include <iostream>
#include <iomanip>
#include <windows.h>


using namespace std;
int Grid(char users_input[][3]);
int Conditions(char users_input[][3]);
int machine(char users_input[][3]);
void lose();
void win();
char play =0;
int main()
{
    system("CLS");
    char users_input[3][3] = {0};
    int choice = 0;

    if(play==0)
    {
        cout << "Enter any key to play " << endl;
        cin >> play;
    }


    if (play > 0)
    {
        
        while (1)
        {
            Grid(users_input);
            cout << "User turn " << endl;
            cin >> choice;
            if (choice == 1)
                users_input[0][0] = 'O';
            else if (choice == 2)
                users_input[0][1] = 'O';
            else if (choice == 3)
                users_input[0][2] = 'O';
            else if (choice == 4)
                users_input[1][0] = 'O';
            else if (choice == 5)
                users_input[1][1] = 'O';
            else if (choice == 6)
                users_input[1][2] = 'O';
            else if (choice == 7)
                users_input[2][0] = 'O';
            else if (choice == 8)
                users_input[2][1] = 'O';
            else if (choice == 9)
                users_input[2][2] = 'O';
            machine(users_input);
            choice = 0;
            system("CLS");
            Conditions(users_input);
        }
    }
}

int Conditions(char users_input[3][3])
{
    if (users_input[0][0] == 'O' && users_input[0][1] == 'O' && users_input[0][2] == 'O')
        win();
    if (users_input[0][0] == 'O' && users_input[1][1] == 'O' && users_input[2][2] == 'O')
        win();
    if (users_input[0][0] == 'O' && users_input[1][0] == 'O' && users_input[2][0] == 'O')
        win();
    if (users_input[0][1] == 'O' && users_input[1][1] == 'O' && users_input[2][1] == 'O')
        win();
    if (users_input[0][2] == 'O' && users_input[1][1] == 'O' && users_input[2][0] == 'O')
        win();
    if (users_input[0][2] == 'O' && users_input[1][2] == 'O' && users_input[2][2] == 'O')
        win();
    if (users_input[1][0] == 'O' && users_input[1][1] == 'O' && users_input[1][2] == 'O')
        win();
    if (users_input[2][0] == 'O' && users_input[2][1] == 'O' && users_input[2][2] == 'O')
        win();

    if (users_input[0][0] == 'X' && users_input[0][1] == 'X' && users_input[0][2] == 'X')
        lose();
    if (users_input[0][0] == 'X' && users_input[1][1] == 'X' && users_input[2][2] == 'X')
        lose();
    if (users_input[0][0] == 'X' && users_input[1][0] == 'X' && users_input[2][0] == 'X')
        lose();
    if (users_input[0][1] == 'X' && users_input[1][1] == 'X' && users_input[2][1] == 'X')
        lose();
    if (users_input[0][2] == 'X' && users_input[1][1] == 'X' && users_input[2][0] == 'X')
        lose();
    if (users_input[0][2] == 'X' && users_input[1][2] == 'X' && users_input[2][2] == 'X')
        lose();
    if (users_input[1][0] == 'X' && users_input[1][1] == 'X' && users_input[1][2] == 'X')
        lose();
    if (users_input[2][0] == 'X' && users_input[2][1] == 'X' && users_input[2][2] == 'X')
        lose();

    if(users_input[0][0]>0&&users_input[0][1]>0&&users_input[0][2]>0&&users_input[1][0]>0&&users_input[1][1]>0
    &&users_input[1][2]>0&&users_input[2][0]>0&&users_input[2][1]>0&&users_input[2][2]>0)
    {
        char choice =0;
        cout << "<<Draw>>    Play Again ? Y/N" << endl;
        cin >> choice;

        if(choice == 'y')
        main();

        else if(choice == 'n')
        exit(0);

        else
        cout << "Invalid Input " << endl;

    }

}

int machine(char users_input[][3])
{

    if (users_input[0][0] == 0 && users_input[0][1] == 0 && users_input[0][2] == 0 && users_input[1][0] == 0 && users_input[1][1] == 0 && users_input[1][2] == 0 && users_input[2][0] == 0 && users_input[2][1] == 0 && users_input[2][2] == 0)
        users_input[1][1] = 'X';
    else if (users_input[0][0] == 'X' && users_input[0][1] == 'X' && users_input[0][2] == 0)
        users_input[0][2] = 'X';
    else if (users_input[0][0] == 'X' && users_input[0][2] == 'X' && users_input[0][1] == 0)
        users_input[0][1] = 'X';
    else if (users_input[0][1] == 'X' && users_input[0][2] == 'X' && users_input[0][0] == 0)
        users_input[0][0] = 'X';

    else if (users_input[0][0] == 'X' && users_input[1][1] == 'X' && users_input[2][2] == 0)
        users_input[2][2] = 'X';
    else if (users_input[0][0] == 'X' && users_input[2][2] == 'X' && users_input[1][1] == 0)
        users_input[1][1] = 'X';
    else if (users_input[1][1] == 'X' && users_input[2][2] == 'X' && users_input[0][0] == 0)
        users_input[0][0] = 'X';

    else if (users_input[0][0] == 'X' && users_input[1][0] == 'X' && users_input[2][0] == 0)
        users_input[2][0] = 'X';
    else if (users_input[0][0] == 'X' && users_input[2][0] == 'X' && users_input[1][0] == 0)
        users_input[1][0] = 'X';
    else if (users_input[1][0] == 'X' && users_input[2][0] == 'X' && users_input[0][0] == 0)
        users_input[0][0] = 'X';

    // second 1 possibility
    else if (users_input[0][1] == 'X' && users_input[1][1] == 'X' && users_input[2][1] == 0)
        users_input[2][1] = 'X';
    else if (users_input[0][1] == 'X' && users_input[2][1] == 'X' && users_input[1][1] == 0)
        users_input[1][1] = 'X';
    else if (users_input[1][1] == 'X' && users_input[2][1] == 'X' && users_input[0][1] == 0)
        users_input[0][1] = 'X';

    // akjdk
    else if (users_input[0][2] == 'X' && users_input[1][1] == 'X' && users_input[2][0] == 0)
        users_input[2][0] = 'X';
    else if (users_input[0][2] == 'X' && users_input[2][0] == 'X' && users_input[1][1] == 0)
        users_input[1][1] = 'X';
    else if (users_input[1][1] == 'X' && users_input[2][0] == 'X' && users_input[0][2] == 0)
        users_input[0][2] = 'X';

    else if (users_input[0][2] == 'X' && users_input[1][2] == 'X' && users_input[2][2] == 0)
        users_input[2][2] = 'X';
    else if (users_input[0][2] == 'X' && users_input[2][2] == 'X' && users_input[1][2] == 0)
        users_input[1][2] = 'X';
    else if (users_input[1][2] == 'X' && users_input[2][2] == 'X' && users_input[0][2] == 0)
        users_input[0][2] = 'X';

    // hjghgfh
    else if (users_input[1][0] == 'X' && users_input[1][1] == 'X' && users_input[1][2] == 0)
        users_input[1][2] = 'X';
    else if (users_input[1][0] == 'X' && users_input[1][2] == 'X' && users_input[1][1] == 0)
        users_input[1][1] = 'X';
    else if (users_input[1][1] == 'X' && users_input[1][2] == 'X' && users_input[1][0] == 0)
        users_input[1][0] = 'X';

    // akjfk
    else if (users_input[2][0] == 'X' && users_input[2][1] == 'X' && users_input[2][2] == 0)
        users_input[2][2] = 'X';
    else if (users_input[2][0] == 'X' && users_input[2][2] == 'X' && users_input[2][1] == 0)
        users_input[2][1] = 'X';
    else if (users_input[2][1] == 'X' && users_input[2][2] == 'X' && users_input[2][0] == 0)
        users_input[2][0] = 'X';

    else if (users_input[0][0] == 'O' && users_input[0][1] == 'O' && users_input[0][2] == 0)
        users_input[0][2] = 'X';
    else if (users_input[0][0] == 'O' && users_input[0][2] == 'O' && users_input[0][1] == 0)
        users_input[0][1] = 'X';
    else if (users_input[0][1] == 'O' && users_input[0][2] == 'O' && users_input[0][0] == 0)
        users_input[0][0] = 'X';
    else if (users_input[0][0] == 'O' && users_input[1][1] == 'O' && users_input[2][2] == 0)
        users_input[2][2] = 'X';
    else if (users_input[0][0] == 'O' && users_input[2][2] == 'O' && users_input[1][1] == 0)
        users_input[1][1] = 'X';
    else if (users_input[1][1] == 'O' && users_input[2][2] == 'O' && users_input[0][0] == 0)
        users_input[0][0] = 'X';
    else if (users_input[0][0] == 'O' && users_input[1][0] == 'O' && users_input[2][0] == 0)
        users_input[2][0] = 'X';
    else if (users_input[0][0] == 'O' && users_input[2][0] == 'O' && users_input[1][0] == 0)
        users_input[1][0] = 'X';
    else if (users_input[1][0] == 'O' && users_input[2][0] == 'O' && users_input[0][0] == 0)
        users_input[0][0] = 'X';
    else if (users_input[0][1] == 'O' && users_input[1][1] == 'O' && users_input[2][1] == 0)
        users_input[2][1] = 'X';
    else if (users_input[0][1] == 'O' && users_input[2][1] == 'O' && users_input[1][1] == 0)
        users_input[1][1] = 'X';
    else if (users_input[1][1] == 'O' && users_input[2][1] == 'O' && users_input[0][1] == 0)
        users_input[0][1] = 'X';
    else if (users_input[0][2] == 'O' && users_input[1][1] == 'O' && users_input[2][0] == 0)
        users_input[2][0] = 'X';
    else if (users_input[0][2] == 'O' && users_input[2][0] == 'O' && users_input[1][1] == 0)
        users_input[1][1] = 'X';
    else if (users_input[1][1] == 'O' && users_input[2][0] == 'O' && users_input[0][2] == 0)
        users_input[0][2] = 'X';
    else if (users_input[0][2] == 'O' && users_input[1][2] == 'O' && users_input[2][2] == 0)
        users_input[2][2] = 'X';
    else if (users_input[0][2] == 'O' && users_input[2][2] == 'O' && users_input[1][2] == 0)
        users_input[1][2] = 'X';
    else if (users_input[1][2] == 'O' && users_input[2][2] == 'O' && users_input[0][2] == 0)
        users_input[0][2] = 'X';

    else if (users_input[1][0] == 'O' && users_input[1][1] == 'O' && users_input[1][2] == 0)
        users_input[1][2] = 'X';
    else if (users_input[1][0] == 'O' && users_input[1][2] == 'O' && users_input[1][1] == 0)
        users_input[1][1] = 'X';
    else if (users_input[1][1] == 'O' && users_input[1][2] == 'O' && users_input[1][0] == 0)
        users_input[1][0] = 'X';

    else if (users_input[2][0] == 'O' && users_input[2][1] == 'O' && users_input[2][2] == 0)
        users_input[2][2] = 'X';
    else if (users_input[2][0] == 'O' && users_input[2][2] == 'O' && users_input[2][1] == 0)
        users_input[2][1] = 'X';
    else if (users_input[2][1] == 'O' && users_input[2][2] == 'O' && users_input[2][0] == 0)
        users_input[2][0] = 'X';



    else if (users_input[0][0] >0 && users_input[0][1] == 0 && users_input[0][2] == 0 && users_input[1][0] == 0 && users_input[1][1] == 0 
            && users_input[1][2] == 0 && users_input[2][0] == 0 && users_input[2][1] == 0 && users_input[2][2] == 0)
    users_input[1][1] = 'X';

    else if (users_input[0][0] ==0 && users_input[0][1] > 0 && users_input[0][2] == 0 && users_input[1][0] == 0 && users_input[1][1] == 0 
            && users_input[1][2] == 0 && users_input[2][0] == 0 && users_input[2][1] == 0 && users_input[2][2] == 0)
    users_input[1][1] = 'X';

    else if (users_input[0][0] ==0 && users_input[0][1] == 0 && users_input[0][2] > 0 && users_input[1][0] == 0 && users_input[1][1] == 0 
            && users_input[1][2] == 0 && users_input[2][0] == 0 && users_input[2][1] == 0 && users_input[2][2] == 0)
    users_input[1][1] = 'X';

    else if (users_input[0][0] ==0 && users_input[0][1] == 0 && users_input[0][2] == 0 && users_input[1][0] > 0 && users_input[1][1] == 0 
            && users_input[1][2] == 0 && users_input[2][0] == 0 && users_input[2][1] == 0 && users_input[2][2] == 0)
    users_input[1][1] = 'X';

    else if (users_input[0][0] ==0 && users_input[0][1] == 0 && users_input[0][2] == 0 && users_input[1][0] == 0 && users_input[1][1] > 0 
            && users_input[1][2] == 0 && users_input[2][0] == 0 && users_input[2][1] == 0 && users_input[2][2] == 0)
    users_input[1][2] = 'X';

    else if (users_input[0][0] ==0 && users_input[0][1] == 0 && users_input[0][2] == 0 && users_input[1][0] == 0 && users_input[1][1] == 0 
            && users_input[1][2] > 0 && users_input[2][0] == 0 && users_input[2][1] == 0 && users_input[2][2] == 0)
    users_input[1][1] = 'X';

    else if (users_input[0][0] ==0 && users_input[0][1] == 0 && users_input[0][2] == 0 && users_input[1][0] == 0 && users_input[1][1] == 0 
            && users_input[1][2] == 0 && users_input[2][0] > 0 && users_input[2][1] == 0 && users_input[2][2] == 0)
    users_input[1][1] = 'X';

    else if (users_input[0][0] ==0 && users_input[0][1] == 0 && users_input[0][2] == 0 && users_input[1][0] == 0 && users_input[1][1] == 0 
            && users_input[1][2] == 0 && users_input[2][0] == 0 && users_input[2][1] > 0 && users_input[2][2] == 0)
    users_input[1][1] = 'X';

    else if (users_input[0][0] ==0 && users_input[0][1] == 0 && users_input[0][2] == 0 && users_input[1][0] == 0 && users_input[1][1] == 0 
            && users_input[1][2] == 0 && users_input[2][0] == 0 && users_input[2][1] == 0 && users_input[2][2] > 0)
    users_input[1][1] = 'X';

    
    else if(users_input[0][0]==0)
    users_input[0][0] = 'X';

    else if(users_input[0][1]==0)
    users_input[0][1] = 'X';

    else if(users_input[0][2]==0)
    users_input[0][2] = 'X';

    else if(users_input[1][0]==0)
    users_input[1][0] = 'X';

    else if(users_input[1][1]==0)
    users_input[1][1] = 'X';

    else if(users_input[1][2]==0)
    users_input[1][2] = 'X';

    else if(users_input[2][0]==0)
    users_input[2][0] = 'X';


    else if(users_input[2][1]==0)
    users_input[2][1] = 'X';

    else if(users_input[2][2]==0)
    users_input[2][2] = 'X';

    

}

int Grid(char users_input[][3])
{
    char grid_array[25][30] = {0};

    for (int i = 0; i < 25; i++)
    {
        for (int j = 0; j < 30; j++)
        {
            // conditions to set vertical lines in the grid
            if (j == 9 || j == 18)
                grid_array[i][j] = '|';
            else if (j == 10 || j == 19)
                grid_array[i][j] = '*';
            else if (j == 11 || j == 20)
                grid_array[i][j] = '|';
            else
                grid_array[i][j] = ' ';

            // conditions to set horizental lines in the grid
            if (i == 7 || i == 14)
                grid_array[i][j] = '-';
            else if (i == 8 || i == 15)
                grid_array[i][j] = '-';
        }
    }

    if (users_input[0][0] > 0)
        grid_array[4][5] = users_input[0][0];
    if (users_input[0][1] > 0)
        grid_array[4][15] = users_input[0][1];
    if (users_input[0][2] > 0)
        grid_array[4][25] = users_input[0][2];
    if (users_input[1][0] > 0)
        grid_array[12][5] = users_input[1][0];
    if (users_input[1][1] > 0)
        grid_array[12][15] = users_input[1][1];
    if (users_input[1][2] > 0)
        grid_array[12][25] = users_input[1][2];
    if (users_input[2][0] > 0)
        grid_array[20][5] = users_input[2][0];
    if (users_input[2][1] > 0)
        grid_array[20][15] = users_input[2][1];
    if (users_input[2][2] > 0)
        grid_array[20][25] = users_input[2][2];

    for (int i = 0; i < 25; i++)
    {
        cout << setw(60);
        for (int j = 0; j < 30; j++)
        {
            cout << grid_array[i][j];
        }
        cout << endl;
    }

}

void lose()
{
    char choice=0;
    cout << "Lose " << endl;
    Sleep(1000);
    cout << "Do you want to play again Y/N " << endl;
    cin >> choice;
    if(choice == 'y')
    main();

    else if(choice == 'N')
    exit(0);

    else
    cout << "Invalid Input ";
    lose();

}

void win()
{
    char choice=0;
    cout << "WIN " << endl;
    Sleep(1000);
    cout << "Do you want to play again Y/N " << endl;
    cin >> choice;
    if(choice == 'y')
    main();

    else if(choice == 'N')
    exit(0);

    else
    cout << "Invalid Input ";
    win();
    
    
}
