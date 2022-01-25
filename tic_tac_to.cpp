#include <iostream>
using namespace std;

int right(int (&boardarr)[10][10],int x,int y){
    int d=0;
    if(y == 9 || x == 9 || y == 0 || x == 0){
        return d=7;
    }
    if(boardarr[x][y+1] == 2 )
    {
        d++;
        if(boardarr[x+1][y+1] == 2){
            d++;
            if( boardarr[x+1][y] == 2){
                d++;
                if(boardarr[x+1][y-1] == 2){
                    d++;
                    if(boardarr[x][y-1] == 2){
                        d++;
                    }
                }
            }
        }
    }
    if(boardarr[x][y+1] == 1 )
    {
        d--;
        if(boardarr[x+1][y+1] == 1){
            d--;
            if( boardarr[x+1][y] == 1){
                d--;
                if(boardarr[x+1][y-1] == 1){
                    d--;
                    if(boardarr[x][y-1] == 1){
                        d--;
                    }
                }
            }
        }
    }
    return d;
}

int up(int (&boardarr)[10][10],int x,int y){
    int d=0;
    if(y == 9 || x == 9 || y == 0 || x == 0){
        return d=7;
    }
    if(boardarr[x][y+1] == 2 )
    {
        d++;
        if(boardarr[x+1][y+1] == 2){
            d++;
            if( boardarr[x+1][y] == 2){
                d++;
                if(boardarr[x-1][y] == 2){
                    d++;
                    if(boardarr[x-1][y+1] == 2){
                        d++;
                    }
                }
            }
        }
    }
    if(boardarr[x][y+1] == 1 )
    {
        d--;
        if(boardarr[x+1][y+1] == 1){
            d--;
            if( boardarr[x+1][y] == 1){
                d--;
                if(boardarr[x-1][y] == 1){
                    d--;
                    if(boardarr[x-1][y+1] == 1){
                        d--;
                    }
                }
            }
        }
    }
    return d;
}
int left(int (&boardarr)[10][10],int x,int y){
    int d=0;
    if(y == 9 || x == 9 || y == 0 || x == 0){
        return d=7;
    }
    if(boardarr[x][y+1] == 2 )
    {
        d++;
        if(boardarr[x-1][y+1] == 2){
            d++;
            if( boardarr[x-1][y] == 2){
                d++;
                if(boardarr[x-1][y-1] == 2){
                    d++;
                    if(boardarr[x][y-1] == 2){
                        d++;
                    }
                }
            }
        }
    }
    if(boardarr[x][y+1] == 1 )
    {
        d--;
        if(boardarr[x-1][y+1] == 1){
            d--;
            if( boardarr[x-1][y] == 1){
                d--;
                if(boardarr[x-1][y-1] == 1){
                    d--;
                    if(boardarr[x][y-1] == 1){
                        d--;
                    }
                }
            }
        }
    }
    return d;
}
int down(int (&boardarr)[10][10],int x,int y){
   int d=0;
   if(y == 9 || x == 9 || y == 0 || x == 0){
        return d=7;
    }
    if(boardarr[x][y-1] == 2 )
    {
        d++;
        if(boardarr[x+1][y-1] == 2){
            d++;
            if( boardarr[x+1][y] == 2){
                d++;
                if(boardarr[x-1][y] == 2){
                    d++;
                    if(boardarr[x-1][y-1] == 2){
                        d++;
                    }
                }
            }
        }
    }
    if(boardarr[x][y-1] == 1 )
    {
        d--;
        if(boardarr[x+1][y-1] == 1){
            d--;
            if( boardarr[x+1][y] == 1){
                d--;
                if(boardarr[x-1][y] == 1){
                    d--;
                    if(boardarr[x-1][y-1] == 1){
                        d--;
                    }
                }
            }
        }
    }
    return d;
}

int main()
{

    int board[10][10],selectedmove;
    bool first = true;
    // if 0 its empty if 1 then its yours if 2 the enemy has it
    for(int i =0;i<10;i++){
        for(int g=0;g<0;g++){
            board[i][g] = 0;
        }
    }


    while (1) {
        int opponent_row;
        int danger=10; // The coordinates of your opponent's last move
        int opponent_col;
        cin >> opponent_row >> opponent_col; cin.ignore();
        int valid_action_count; // the number of possible actions for your next move
        cin >> valid_action_count; cin.ignore();
        board[opponent_row][opponent_col]= 2;
        int avi[valid_action_count][2];
        for (int i = 0; i < valid_action_count; i++) {
            cin >> avi[i][0] >> avi[i][1]; cin.ignore();
            //cerr << "row: " << row << " col: " << col << endl;
        }

        for(int i=0;i<valid_action_count;i++){
            int someof = up(board,avi[i][0],avi[i][1]) + down(board,avi[i][0],avi[i][1]) +left(board,avi[i][0],avi[i][1]) +right(board,avi[i][0],avi[i][1]);
            if(someof/4 < danger){
                danger = someof/4;
                selectedmove = i;
            }
        }
        cout << avi[selectedmove][0] << " " << avi[selectedmove][1] << endl;
        board[avi[selectedmove][0]][avi[selectedmove][1]] = 1;
    }
}
