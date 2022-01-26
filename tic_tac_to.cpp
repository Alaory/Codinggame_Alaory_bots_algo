#include <iostream>
#include <cmath>
using namespace std;

// int Dist(int x1,int y1,int x2,int y2){
//     return (sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)));
// }

void slecetmove(int x,int y, int (&board)[10][10], int &fav,int &numofrec,int& round){
        if(numofrec <= 0)
            return;

        int movy=-1,movx=-1,ar=3;
        if(y == 0)
            movy =0;
        if(x == 0)
            movx =0;

        
        if((x == 4 && y == 4 ) || (x == 5 && y == 5) || (x == 4 && y == 5) || (x == 5 && y == 4) ){
            fav += 80*10;
        }

        
        for(int i=y + movy;i<y+ar && (i <= 9 || i >= 0);i++)
        {
            for(int j=x + movx;j<x+ar && (j <= 9 || j>= 0);j++)
            {
                if(board[j][i] == 1)
                {
                    fav++;
                    numofrec--;
                    slecetmove(j,i,board,fav,numofrec,round);
                    int currentrow = board[j + ((j-x)*2)][i+ ((i-y)*2)];
                    if(currentrow == 1){ //row check
                        fav+=2;
                        if(currentrow == 1){ //row check
                            fav+=2;
                        }else if(currentrow == 0){ // check for empty rows
                            fav+=2;
                        }else{
                            fav --;
                        }
                    }
                    
                }
            }
        }
}


int main()
{

    int board[10][10],selectedmove=0,round=0,valid=0;// if 0 its empty if 1 then its yours if 2 the enemy has it
    bool first = true;
    
    while (1) {

        if(round ==0 || round ==100){
            for(int i =0;i<10;i++){
                for(int g=0;g<0;g++){
                board[i][g] = 0;
                }
            }
            cerr << "cleaning board" << endl;
        }

        

        int opponent_row;
        int danger=0; 
        int opponent_col;
        cin >> opponent_row >> opponent_col; cin.ignore();
        int valid_action_count; // the number of possible actions for your next move
        cin >> valid_action_count; cin.ignore();

        if(valid_action_count > valid){
            valid = valid_action_count;
        }

        board[opponent_row][opponent_col]= 2;
        int avi[valid_action_count][2];
        
        
        for (int i = 0; i < valid_action_count; i++) {
            cin >> avi[i][0] >> avi[i][1]; cin.ignore();
        }
        
        

        for(int i=0;i<valid_action_count;i++){
            int fav = 1;
            int numofrecerkon = 3;
            slecetmove(avi[i][0],avi[i][1],board,fav,numofrecerkon,round);
            if(fav > danger){
                danger = fav;
                selectedmove = i;
            }
        }


        cout << avi[selectedmove][0] << " " << avi[selectedmove][1] << endl;
        board[avi[selectedmove][0]][avi[selectedmove][1]] = 1;
        round+=2;
    }
}


