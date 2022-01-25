#include <iostream>
#include <vector>
using namespace std;




struct items{
    int delta[4];
    int fav = 0;
    int inv;
    int getfav(){
        
        return fav;
    }
};







int bestCAST(int (&delta)[5],int inv[4]){
    bool DONUTUSE= false;

    int favrable = 0 ,all_amount_for_delta=0,all_amount_for_inv = 0;
    //cerr << delta[4] << " id_out_CASt" << endl;
    for(int i=0;i<4;i++){
        //cerr << delta[4] << " id_out_CASt" << endl;
        if((delta[i] + inv[i]) < 0){
            cerr << delta[4] << " id_CASt"<<endl;
            return -10;
        }

        if(delta[i] > inv[i]){
            favrable++;
        }
        all_amount_for_delta += delta[i] * (i +2);
        all_amount_for_inv += inv[i] * (i +2);
    }
    
    if(all_amount_for_delta > all_amount_for_inv){
        favrable++;
    }
    return favrable;
}






int bestbrew(int id,int (&delta)[5],int price,int inv[5]){
    int bestcost = 0;
    for(int i =0;i<4;i++){
        if((delta[i] + inv[i]) < 0){
            return -10;
        }
        bestcost += delta[i] * (i+1);
    }
    bestcost += price * 10;
    return bestcost;
}


int main()
{
    vector<int> cas_id;

    bool rested = false;
    while (1) {
        int action_id,action_count; // the number of spells and recipes in play
        cin >> action_count; cin.ignore();

        int price[action_count],inv[4]={0,0,0,0};

        int deltabrew[action_count][5],deltacast[action_count][5];

        int sizeofbre=0,sizeofcast=0;
        
        for (int i = 0; i < action_count; i++) {
             // the unique ID of this spell or recipe
            string action_type; // in the first league: BREW; later: CAST, OPPONENT_CAST, LEARN, BREW // tier-3 ingredient change
            int delta[5];
            int id;
            int tome_index; // in the first two leagues: always 0; later: the index in the tome if this is a tome spell, equal to the read-ahead tax; For brews, this is the value of the current urgency bonus
            int tax_count; // in the first two leagues: always 0; later: the amount of taxed tier-0 ingredients you gain from learning this spell; For brews, this is how many times you can still gain an urgency bonus
            bool castable; // in the first league: always 0; later: 1 if this is a castable player spell
            bool repeatable; // for the first two leagues: always 0; later: 1 if this is a repeatable player spell
            cin >> delta[4] >> action_type >> delta[0] >> delta[1] >> delta[2] >> delta[3] >> price[i] >> tome_index >> tax_count >> castable >> repeatable; cin.ignore();
            if(action_type=="BREW"){
                for(int i=0;i<5;i++)
                    deltabrew[sizeofbre][i] = delta[i];
                
                sizeofbre++;
            }else if(action_type=="CAST"){
                for(int i=0;i<5;i++)
                    deltacast[sizeofcast][i]= delta[i];

                sizeofcast++;
            }
                    
        }
        for (int i = 0; i < 2; i++) {
            int score; // amount of rupees
            for(int j=0;j<4;j++)
                inv[j] = 0;

            cin >> inv[0]>> inv[1] >> inv[2] >> inv[3] >> score; cin.ignore();
        }




        //-----------------------------------------


        int largamount=-1,idfo;
        for(int i=0;i<sizeofbre;i++){
            int value = bestbrew(deltabrew[i][4],deltabrew[i],price[i],inv);
            //cerr << value << " value"<< endl;
            if(value >= largamount){
                idfo = deltabrew[i][4];
                largamount = value;
            }
        }





        int bestmove=-1;
        if(largamount == -1){

            int id_CAST =0;

            for(int i=0;i<sizeofcast;i++){
                //cerr << sizeofcast << " size" << endl;
                int currentslecelt=-2;
                bool go = true;
                for(int j=0;j<cas_id.size();j++){
                    if(cas_id[j] == deltacast[i][4]){
                        go = false;
                        break;
                    }
                }

                if(go){
                    currentslecelt = bestCAST(deltacast[i],inv);
                }else{
                    continue;
                }
                    

                cas_id.push_back(deltacast[i][4]);

                cerr << deltacast[i][4] << " slecet"<< endl;

                if(bestmove < currentslecelt && go){
                    bestmove = currentslecelt;
                    id_CAST = deltacast[i][4];
                }
            }
            
            if(bestmove > 0){
                cout << "CAST " << id_CAST << endl;
                rested = false;
            }else if(!rested){
                cout << "REST" << endl;
                rested = true;
                cas_id.clear();
            }else{
                cout << "WAIT" << endl;
            }
                
        }else{
            cout << "BREW " << idfo << endl;
        }
    }
}
