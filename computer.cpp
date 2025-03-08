//Minesweeper
/*
# = unopened cell
! = flag
  = 0 mines around

both rows and columns start at 0 and end at 9

top row(0)-bottom row(9)
left column(0)-right column(9)
*/
#include <iostream>
#include <cstdlib>//for random # generator & system("clear")
#include <ctime>//for random # generator
#include <string>// for to_string
using namespace std;

int row, column;
bool game_running = true;
bool win = false;

string map[10][10]=//values of cells
{
    {" "," "," "," "," "," "," "," "," "," ",},
    {" "," "," "," "," "," "," "," "," "," ",},
    {" "," "," "," "," "," "," "," "," "," ",},
    {" "," "," "," "," "," "," "," "," "," ",},
    {" "," "," "," "," "," "," "," "," "," ",},
    {" "," "," "," "," "," "," "," "," "," ",},
    {" "," "," "," "," "," "," "," "," "," ",},
    {" "," "," "," "," "," "," "," "," "," ",},
    {" "," "," "," "," "," "," "," "," "," ",},
    {" "," "," "," "," "," "," "," "," "," ",},
};

string display[10][10]=//what the player sees
{
    {"#","#","#","#","#","#","#","#","#","#",},
    {"#","#","#","#","#","#","#","#","#","#",},
    {"#","#","#","#","#","#","#","#","#","#",},
    {"#","#","#","#","#","#","#","#","#","#",},
    {"#","#","#","#","#","#","#","#","#","#",},
    {"#","#","#","#","#","#","#","#","#","#",},
    {"#","#","#","#","#","#","#","#","#","#",},
    {"#","#","#","#","#","#","#","#","#","#",},
    {"#","#","#","#","#","#","#","#","#","#",},
    {"#","#","#","#","#","#","#","#","#","#",},
};


void Mines_Values()//assigns mine positions and values of spaces around mines
{
    for(int i = 0; i < 10; i++)//place mines
    {
        for(int j = 0; j < 10; j++)
        {
            int dice = 1+rand()%6;//1 in 6 chance of placing mine
            if(dice==6)
            {
                map[i][j] = "X";
            }
        }
    }

    for(int i = 0; i < 10; i++)//place numbers that show where mines are
    {
        for(int j = 0; j < 10; j++)
        {
            if(map[i][j]=="X")//if space is a mine, skip it
            {
                continue;
            }
            else if(i==0 && j==0)//top left corner
            {
                int count = 0;//counts mines around space
                if(map[i][j+1]=="X")
                {
                    count++;
                }
                if(map[i+1][j]=="X")
                {
                    count++;
                }
                if(map[i+1][j+1]=="X")
                {
                    count++;
                }
                if(count>0)
                {
                    map[i][j]=to_string(count);
                }
            }
            else if(i==0 && j!=9)//top center 8
            {
                int count = 0;//counts mines around space
                if(map[i][j-1]=="X")
                {
                    count++;
                }
                if(map[i][j+1]=="X")
                {
                    count++;
                }
                if(map[i+1][j-1]=="X")
                {
                    count++;
                }
                if(map[i+1][j]=="X")
                {
                    count++;
                }
                if(map[i+1][j+1]=="X")
                {
                    count++;
                }
                if(count>0)
                {
                    map[i][j]=to_string(count);
                }
            }
            else if(i==0 && j==9)//top right corner
            {
                int count = 0;//counts mines around space
                if(map[i][j-1]=="X")
                {
                    count++;
                }
                if(map[i+1][j]=="X")
                {
                    count++;
                }
                if(map[i+1][j-1]=="X")
                {
                    count++;
                }
                if(count>0)
                {
                    map[i][j]=to_string(count);
                }
            }
            else if(j==0 && i!=0 && i!=9)//left center 8
            {
                int count = 0;//counts mines around space
                if(map[i-1][j]=="X")
                {
                    count++;
                }
                if(map[i-1][j+1]=="X")
                {
                    count++;
                }
                if(map[i][j+1]=="X")
                {
                    count++;
                }
                if(map[i+1][j+1]=="X")
                {
                    count++;
                }
                if(map[i+1][j]=="X")
                {
                    count++;
                }
                if(count>0)
                {
                    map[i][j]=to_string(count);
                }
            }
            else if(i==9 && j==0)//bottom left corner
            {
                int count = 0;//counts mines around space
                if(map[i-1][j]=="X")
                {
                    count++;
                }
                if(map[i-1][j+1]=="X")
                {
                    count++;
                }
                if(map[i][j+1]=="X")
                {
                    count++;
                }
                if(count>0)
                {
                    map[i][j]=to_string(count);
                }
            }
            else if(i==9 && j!=0 && j!=9)//bottom center 8
            {
                int count = 0;//counts mines around space
                if(map[i][j-1]=="X")
                {
                    count++;
                }
                if(map[i-1][j-1]=="X")
                {
                    count++;
                }
                if(map[i-1][j]=="X")
                {
                    count++;
                }
                if(map[i-1][j+1]=="X")
                {
                    count++;
                }
                if(map[i][j+1]=="X")
                {
                    count++;
                }
                if(count>0)
                {
                    map[i][j]=to_string(count);
                }
            }
            else if(i==9 && j==9)//bottom right corner
            {
                int count = 0;//counts mines around space
                if(map[i][j-1]=="X")
                {
                    count++;
                }
                if(map[i-1][j-1]=="X")
                {
                    count++;
                }
                if(map[i-1][j]=="X")
                {
                    count++;
                }
                if(count>0)
                {
                    map[i][j]=to_string(count);
                }
            }
            else if(j==9 && i!=0 && i!=9)//right center 8
            {
                int count = 0;//counts mines around space
                if(map[i-1][j]=="X")
                {
                    count++;
                }
                if(map[i-1][j-1]=="X")
                {
                    count++;
                }
                if(map[i][j-1]=="X")
                {
                    count++;
                }
                if(map[i+1][j-1]=="X")
                {
                    count++;
                }
                if(map[i+1][j]=="X")
                {
                    count++;
                }
                if(count>0)
                {
                    map[i][j]=to_string(count);
                }
            }
            else//center 64
            {
                int count = 0;//counts mines around space
                if(map[i-1][j-1]=="X")
                {
                    count++;
                }
                if(map[i-1][j]=="X")
                {
                    count++;
                }
                if(map[i-1][j+1]=="X")
                {
                    count++;
                }
                if(map[i][j-1]=="X")
                {
                    count++;
                }
                if(map[i][j+1]=="X")
                {
                    count++;
                }
                if(map[i+1][j-1]=="X")
                {
                    count++;
                }
                if(map[i+1][j]=="X")
                {
                    count++;
                }
                if(map[i+1][j+1]=="X")
                {
                    count++;
                }
                if(count>0)
                {
                    map[i][j]=to_string(count);
                }
            }
        }
    }
};

void GameOver()//called when player digs on a mine space
{
    #ifdef _WIN32//checks which system game is being run on to use correct clear command
        system("cls"); // Clear terminal on Windows
    #else
        system("clear"); // Clear terminal on Mac and Linux
    #endif

    for(int i = 0; i < 10; i++)//reveals all mines
    {
        for(int j = 0; j < 10; j++)
        {
            if(map[i][j]=="X")
            {
                display[i][j]="X";
                cout << "\033[0;31;101m";
                cout << display[i][j];
            }
            else if(display[i][j]=="#")
            {
                cout << "\033[0;32;102m";
                cout << display[i][j];
            }
            else
            {
                cout << display[i][j];
            }
            cout << "\033[0m";
        }
        cout << endl;
    }
}

bool Check_Win()//checks if the player has won
{
    int non_mines = 0;
    int revealed_cells = 0;

    for(int i = 0; i < 10; i++)
    {
        for(int j = 0; j < 10; j++)
        {
            if(map[i][j] != "X")
            {
                non_mines++;
            }
            if(display[i][j] != "#" && display[i][j] != "!")
            {
                revealed_cells++;
            }
        }
    }

    if(non_mines == revealed_cells)//checks if all of the non-mine cells have been revealed
    {
        return true;
    }
    else
    {
        return false;
    }
};

void dig()
{   
    display[row][column] = map[row][column];//reveal chosen cell

    if(row > 0 && row < 9 && column > 0 && column < 9 && map[row][column] == " ")//inner cells
    {
        for(int i = row-1; i >= 0; i--)//going up;
        {
            if(map[i][column] == " ")//if blank, reveal cell and continue
            {
                display[i][column] = map[i][column];
            }
            else if(map[i][column] == "X")//if mine is found, stop
            {
                break;
            }
            else//if number is found, reveal cell and then stop
            {
                display[i][column] = map[i][column];
                break;
            }
        }
        for(int i = row+1; i <= 9; i++)//going down;
        {
            if(map[i][column] == " ")
            {
                display[i][column] = map[i][column];
            }
            else if(map[i][column] == "X")
            {
                break;
            }
            else
            {
                display[i][column] = map[i][column];
                break;
            }
        }
        for(int i = column-1; i >= 0; i--)//going left;
        {
            if(map[row][i] == " ")
            {
                display[row][i] = map[row][i];
            }
            else if(map[row][i] == "X")
            {
                break;
            }
            else
            {
                display[row][i] = map[row][i];
                break;
            }
        }
        for(int i = column+1; i <= 9; i++)//going right;
        {
            if(map[row][i] == " ")
            {
                display[row][i] = map[row][i];
            }
            else if(map[row][i] == "X")
            {
                break;
            }
            else
            {
                display[row][i] = map[row][i];
                break;
            }
        }
    }
    else if(row == 0 && column != 0 && column != 9)//top center 8
    {
        for(int i = row+1; i <= 9; i++)//going down;
        {
            if(map[i][column] == " ")
            {
                display[i][column] = map[i][column];
            }
            else if(map[i][column] == "X")
            {
                break;
            }
            else
            {
                display[i][column] = map[i][column];
                break;
            }
        }
        for(int i = column-1; i >= 0; i--)//going left;
        {
            if(map[row][i] == " ")
            {
                display[row][i] = map[row][i];
            }
            else if(map[row][i] == "X")
            {
                break;
            }
            else
            {
                display[row][i] = map[row][i];
                break;
            }
        }
        for(int i = column+1; i <= 9; i++)//going right;
        {
            if(map[row][i] == " ")
            {
                display[row][i] = map[row][i];
            }
            else if(map[row][i] == "X")
            {
                break;
            }
            else
            {
                display[row][i] = map[row][i];
                break;
            }
        }
    }
    else if(column == 9 && row != 0 && row != 9)//right center 8
    {
        for(int i = row-1; i >= 0; i--)//going up;
        {
            if(map[i][column] == " ")
            {
                display[i][column] = map[i][column];
            }
            else if(map[i][column] == "X")
            {
                break;
            }
            else
            {
                display[i][column] = map[i][column];
                break;
            }
        }
        for(int i = row+1; i <= 9; i++)//going down;
        {
            if(map[i][column] == " ")
            {
                display[i][column] = map[i][column];
            }
            else if(map[i][column] == "X")
            {
                break;
            }
            else
            {
                display[i][column] = map[i][column];
                break;
            }
        }
        for(int i = column-1; i >= 0; i--)//going left;
        {
            if(map[row][i] == " ")
            {
                display[row][i] = map[row][i];
            }
            else if(map[row][i] == "X")
            {
                break;
            }
            else
            {
                display[row][i] = map[row][i];
                break;
            }
        }
    }
    else if(row == 9 && column != 0 && column != 9)//bottom center 8
    {
        for(int i = row-1; i >= 0; i--)//going up;
        {
            if(map[i][column] == " ")
            {
                display[i][column] = map[i][column];
            }
            else if(map[i][column] == "X")
            {
                break;
            }
            else
            {
                display[i][column] = map[i][column];
                break;
            }
        }
        for(int i = column-1; i >= 0; i--)//going left;
        {
            if(map[row][i] == " ")
            {
                display[row][i] = map[row][i];
            }
            else if(map[row][i] == "X")
            {
                break;
            }
            else
            {
                display[row][i] = map[row][i];
                break;
            }
        }
        for(int i = column+1; i <= 9; i++)//going right;
        {
            if(map[row][i] == " ")
            {
                display[row][i] = map[row][i];
            }
            else if(map[row][i] == "X")
            {
                break;
            }
            else
            {
                display[row][i] = map[row][i];
                break;
            }
        }
    }
    else if(column == 0 && row != 0 && row != 9)//left center 8
    {
        for(int i = row-1; i >= 0; i--)//going up;
        {
            if(map[i][column] == " ")
            {
                display[i][column] = map[i][column];
            }
            else if(map[i][column] == "X")
            {
                break;
            }
            else
            {
                display[i][column] = map[i][column];
                break;
            }
        }
        for(int i = row+1; i <= 9; i++)//going down;
        {
            if(map[i][column] == " ")
            {
                display[i][column] = map[i][column];
            }
            else if(map[i][column] == "X")
            {
                break;
            }
            else
            {
                display[i][column] = map[i][column];
                break;
            }
        }
        for(int i = column+1; i <= 9; i++)//going right;
        {
            if(map[row][i] == " ")
            {
                display[row][i] = map[row][i];
            }
            else if(map[row][i] == "X")
            {
                break;
            }
            else
            {
                display[row][i] = map[row][i];
                break;
            }
        }
    }
    else if(row == 0 && column == 0)//top left corner
    {
        for(int i = row+1; i <= 9; i++)//going down;
        {
            if(map[i][column] == " ")
            {
                display[i][column] = map[i][column];
            }
            else if(map[i][column] == "X")
            {
                break;
            }
            else
            {
                display[i][column] = map[i][column];
                break;
            }
        }
        for(int i = column+1; i <= 9; i++)//going right;
        {
            if(map[row][i] == " ")
            {
                display[row][i] = map[row][i];
            }
            else if(map[row][i] == "X")
            {
                break;
            }
            else
            {
                display[row][i] = map[row][i];
                break;
            }
        }
    }
    else if(row == 0 && column == 9)//top right corner
    {
        for(int i = row+1; i <= 9; i++)//going down;
        {
            if(map[i][column] == " ")
            {
                display[i][column] = map[i][column];
            }
            else if(map[i][column] == "X")
            {
                break;
            }
            else
            {
                display[i][column] = map[i][column];
                break;
            }
        }
        for(int i = column-1; i >= 0; i--)//going left;
        {
            if(map[row][i] == " ")
            {
                display[row][i] = map[row][i];
            }
            else if(map[row][i] == "X")
            {
                break;
            }
            else
            {
                display[row][i] = map[row][i];
                break;
            }
        }
    }
    else if(row == 9 && column == 9)//bottom right corner
    {
        for(int i = row-1; i >= 0; i--)//going up;
        {
            if(map[i][column] == " ")
            {
                display[i][column] = map[i][column];
            }
            else if(map[i][column] == "X")
            {
                break;
            }
            else
            {
                display[i][column] = map[i][column];
                break;
            }
        }
        for(int i = column-1; i >= 0; i--)//going left;
        {
            if(map[row][i] == " ")
            {
                display[row][i] = map[row][i];
            }
            else if(map[row][i] == "X")
            {
                break;
            }
            else
            {
                display[row][i] = map[row][i];
                break;
            }
        }
    }
    else//bottom left corner
    {
        for(int i = row-1; i >= 0; i--)//going up;
        {
            if(map[i][column] == " ")
            {
                display[i][column] = map[i][column];
            }
            else if(map[i][column] == "X")
            {
                break;
            }
            else
            {
                display[i][column] = map[i][column];
                break;
            }
        }
        for(int i = column+1; i <= 9; i++)//going right;
        {
            if(map[row][i] == " ")
            {
                display[row][i] = map[row][i];
            }
            else if(map[row][i] == "X")
            {
                break;
            }
            else
            {
                display[row][i] = map[row][i];
                break;
            }
        }
    }
};

void printDisplay()//prints display - what the player is supposed to see when not cheating
{
    for(int a = 0; a < 10; a++)
    {
        for(int b = 0; b < 10; b++)
        {
            if(display[a][b] == "!")//if the cell is marked with a flag, make flag(!) red
            {
                cout << "\033[0;91;101m";
            }
            else if(display[a][b] == "#")//if the cell is unopened make background green
            {
                cout << "\033[0;92;42m";
            }
            else if(display[a][b] == "X")
            {
                cout << "\033[0;91;101m";//bright red background
            }
            else if(display[a][b] == "1")
            {
                cout << "\033[0;94m";//bright blue foreground
            }
            else if(display[a][b] == "2")
            {
                cout << "\033[0;92m";//bright green foreground
            }
            else if(display[a][b] == "3")
            {
                cout << "\033[0;91m";//bright red foreground
            }
            else if(display[a][b] == "4")
            {
                cout << "\033[0;95m";//bright magenta foreground
            }
            else if(display[a][b] == "5")
            {
                cout << "\033[0;96m";//bright cyan foreground
            }
            else if(display[a][b] == "6")
            {
                cout << "\033[0;93m";//bright yellow foreground
            }
            else if(display[a][b] == "7")
            {
                cout << "\033[0;97m";//bright white foreground
            }
            else if(display[a][b] == "8")
            {
                cout << "\033[0;30m";//black foreground
            }
            cout << display[a][b];
            cout <<  "\033[0m";
        }
        cout << endl;
    }
};

void Cheat()//a function to show the numbers and mines
{
    for(int a = 0; a < 10; a++)
    {
        for(int b = 0; b < 10; b++)
        {
            cout << map[a][b];
        }
        cout << endl;
    }
};

void FlagCounter()//counts how many flags should be placed
{
    int mines = 0;
    int flags = 0;
    for(int i = 0; i < 10; i++)
    {
        for(int j = 0; j < 10; j++)
        {
            if(map[i][j]=="X")
            {
                mines++;
            }
            if(display[i][j]=="!")
            {
                flags++;
            }
        }
    }
    cout << mines-flags << endl;
};

int main()
{
    //for random number generator
    int x = time(0);
    srand(x);

    //sets up the gameboard
    Mines_Values();
    //Cheat();//uncomment to cheat at start

    while(game_running)
    {   
        printDisplay();

        cout << "Flags remaining " << "\033[0;91;101m ! \033[0m"<< ": ";
        FlagCounter();

        cout << "Enter row #(0-9): "<< endl;
        cin >> row;
        cout << "Enter column #(0-9): "<< endl;
        cin >> column;

        int input;
        cout << "Choose action" << endl;
        cout << "1. dig" << endl;
        cout << "2. mark with flag" << endl;
        cout << "3. take flag off" << endl;
        cout << "4. go back" << endl;
        cin >> input;
        
        switch (input)
        {
        case 1:
            /* code to dig*/
            if(map[row][column]=="X")
            {
                GameOver();
                game_running = false;
            }
            else
            {
                dig();
            }
            break;
        
        case 2://mark with flag
            display[row][column] = "!";
            break;

        case 3://take flag off
            display[row][column] = "#";
            break;

        case 4:
            /*goto start;*/
            break;
            
        default:
            /*goto start;*/
            break;
        }
        //system("clear");

        #ifdef _WIN32//checks which system game is being run on to use correct clear command
            system("cls"); // Clear terminal on Windows
        #else
            system("clear"); // Clear terminal on Mac and Linux
        #endif

        if(Check_Win())
        {   
            win = true;
            game_running = false;
        }
    }

    if(win)
    {
        printDisplay();
        cout << "You win!";
    }
    else
    {
        GameOver();
        cout << "You Lose!" << endl;
    }
    return 0;
}