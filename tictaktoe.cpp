//tictaktoe game

#include<iostream>
using namespace std;
char current_p;
int current_m;
char board[3][3]={0};

void initialize()
{
    char cell='1';
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            board[i][j]=cell++;
        }
    }
}

void display()
{
    cout << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << "\n"<<board[1][0]<<" | "<<board[1][1]<<" | "<<board[1][2]<<"\n"<<board[2][0] <<" | "<<board[2][1]<<" | "<< board[2][2]<<"\n";
}

bool iswinner(char symbol)
{
    int j=0;
    int i=0;
    for( i=0;i<3;i++)
    {
        if(board[i][j]==symbol  && board[i][j+1]==symbol && board[i][j+2]==symbol)return true;
        if( board[j][i]==symbol && board[j+1][i]==symbol && board[j+2][i]==symbol )return true;
        j=0;
    }
     if(board[i][j]==symbol && board[i+1][j+1]==symbol && board[i+2][j+2]==symbol )return true;
     if(board[i][j+2]==symbol && board[i+1][j+1]==symbol && board[i+2][j]==symbol){
            return true;
        }
    return false;
}

bool draw()
{
    int d=0;
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(board[i][j]!='o' && board[i][j]!='x')
            {return false;}
        }
    }
   return true;
}

void playermove(char symbol)
{
    int s=0;
    char position;
    cout<<"enter the position\n";
    cin>>position;
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(board[i][j]==position)
            {
                board[i][j]=symbol;
                s=0;
                return;
            }
            else{
                s=1;
            }

        }
    }
    if(s==1)
    {cout<<"Inter valid position"<<endl;}
    
}

void switchplayer()
{
    current_p=current_p=='x'? 'o':'x';
}

void game()
{
    initialize();
    display();
    cout<<"choose current player:\n";
        cin>>current_p;
    while(true)
    {
        
        playermove(current_p);
        display();
        if(iswinner(current_p))
        {cout<<"Player :"<< current_p<<" wins the game"<<endl;
        break;
        }
        if(draw())
        {cout<<"the game is a draw"<<endl;
        break;
        }
        switchplayer();    
    }
    

}

int main()
{
    game();
    return 0;
}