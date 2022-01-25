#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


struct item{
    int fav=0;
    int delta[4];
    static int inv[4];
    static int score;
    static bool should_rest;
    static int size;
    bool used = false;
    int id;
    int price; //if brew
    string type;
    int getfav(){
        for(int i=0;i<4;i++){
            fav += delta[i] *(i+1);
        }
        return fav;
    }
    bool can_afford(){
        bool afford=true;
        for(int i=0;i<4;i++){
            if(inv[i] + delta[i] < 0){
                afford = false;
            }
        }
        return afford;
    }
};


bool item::should_rest = false;
int item::inv[4] = {};
int item::score = 0;
int item::size =0;




bool canget_ingre(item (&items)[item::size],int (&wanted)[4],int id){
    bool afford=false;
    for(int i=0;i<item::size;i++){
        if(items[i].type == "CAST" && items[i].can_afford() && id != items[i].id){
            if() // check for ingrendands
        }
    }
}




int main()
{
    

    while (1) {
        int action_count; // the number of spells and recipes in play
        cin >> action_count; cin.ignore();
        item items[action_count];
        item::size = action_count;
        for (int i = 0; i < action_count; i++) {
            int tome_index; // in the first two leagues: always 0; later: the index in the tome if this is a tome spell, equal to the read-ahead tax; For brews, this is the value of the current urgency bonus
            int tax_count; // in the first two leagues: always 0; later: the amount of taxed tier-0 ingredients you gain from learning this spell; For brews, this is how many times you can still gain an urgency bonus
            bool castable; // in the first league: always 0; later: 1 if this is a castable player spell
            bool repeatable; // for the first two leagues: always 0; later: 1 if this is a repeatable player spell
            cin >> items[i].id >> items[i].type >> items[i].delta[0] >> items[i].delta[1] >> items[i].delta[2] >> items[i].delta[3] >> items[i].price >> tome_index >> tax_count >> castable >> repeatable; cin.ignore();
        }

        for (int i = 0; i < 2; i++)
            cin >> item::inv[0] >> item::inv[1] >> item::inv[2] >> item::inv[3] >> item::score; cin.ignore();
        
        int largest = 0;int slecet_id,wanted;
        for(int i=0;i<action_count;i++){
            if(items[i].type == "BREW" && !items[i].used){                
                if(items[i].price > largest &&){
                    largest = items[i].price;
                    slecet_id = items[i].id;
                    wanted = i;
                }
            }
        }      
    }
}
