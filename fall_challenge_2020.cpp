#include <iostream>
#include <vector>
using namespace std;

struct item{
    string type;
    int id=-1;
    int price=0;
    int delta[4];
    static int inv[4];
    static int score;
    //static int gems[4];
    bool used = false;
    static bool able_to_rest;

    bool Can_afford(){
        for(int i=0;i<4;i++){
            if(delta[i] + inv[i] < 0){
                return false;
            }
        }
        return true;
    }
    int howfav(){
        if(Can_afford()){
            int fav =0;
            for(int i=0;i<4;i++){
                // if(gems[i] <0)
                //     gems[i] =0;
                if(delta[i] > 0)
                    fav += delta[i] * (i+10);
                else
                    fav += delta[i] * (i+2);
                    
                fav += this->price *100;
            }
            return fav;
        }
        return 0;
    }
};


int item::inv[] = {};
int item::score = 0;
bool item::able_to_rest = false;
//int item::gems[] ={1,2,3,4};



// void set_value_for_gems(int delta[4]){
//     for(int i=0;i<4;i++){
//         if(delta[i] < 0){
//             item::gems[i]+=5;
//         }else if(delta[i] > 0){
//             item::gems[i]-=2*delta[i];
//         }

//     }
// }

int main()
{
    vector<int> ids;

    while (1) {
        int action_count; // the number of spells and recipes in play
        cin >> action_count; cin.ignore();
        item items[action_count];
        for (int i = 0; i < action_count; i++) {
            int tome_index; // in the first two leagues: always 0; later: the index in the tome if this is a tome spell, equal to the read-ahead tax; For brews, this is the value of the current urgency bonus
            int tax_count; // in the first two leagues: always 0; later: the amount of taxed tier-0 ingredients you gain from learning this spell; For brews, this is how many times you can still gain an urgency bonus
            bool castable; // in the first league: always 0; later: 1 if this is a castable player spell
            bool repeatable; // for the first two leagues: always 0; later: 1 if this is a repeatable player spell
            cin >>items[i].id >> items[i].type >> items[i].delta[0] >> items[i].delta[1] >> items[i].delta[2] >> items[i].delta[3] >> items[i].price >> tome_index >> tax_count >> castable >> repeatable; cin.ignore();
        }

        for (int i = 0; i < 2; i++)
            cin >> item::inv[0] >> item::inv[1] >> item::inv[2] >> item::inv[3] >> item::score; cin.ignore();



        int brew_fav=0,id_temp=0,cast_fav=0,id_cast=0;


        for(int i=0;i<action_count;i++){
            for(int j=0;j<ids.size();j++){
                if(items[i].id == ids[j]){
                    items[i].used =true;
                }
            }
        }

        for(int i=0;i<action_count;i++){
            if(items[i].type == "BREW" && items[i].Can_afford() && !items[i].used){
                int b = items[i].howfav();
                if(brew_fav < b){
                    brew_fav = b;
                    id_temp = i;
                }
            }
            if(items[i].type == "CAST" && items[i].Can_afford() && !items[i].used){
                int a = items[i].howfav();
                if(cast_fav < a){
                    cast_fav = a;
                    id_cast = i;
                }
            }
        }

        if(id_temp != 0){
            cout << "BREW " << items[id_temp].id<<endl;
            items[id_temp].used = true;
            item::able_to_rest = true;
            ids.push_back(items[id_temp].id);
        }else if(id_cast != 0){
            cout << "CAST " << items[id_cast].id<<endl;
            items[id_cast].used = true;
            item::able_to_rest = true;
            ids.push_back(items[id_cast].id);
            //set_value_for_gems(items[id_cast].delta);
        }else if(item::able_to_rest){
            cout << "REST" << endl;
            item::able_to_rest = false;
            ids.clear();
        }else {
            cout << "WAIT" << endl;
        }
    }
}
