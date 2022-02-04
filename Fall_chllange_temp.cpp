#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct item{
    string type;
    int id=-1;
    int price=0;
    int delta[4];
    int recom = 0;
    static int inv[4];
    static int score;
    static int hights_price;
    static int hights_price_index;
    static vector<int> ids;
    bool used = false;
    static bool able_to_rest;

    static int find_eazy_po(item *Items,int size){
        int current_id=-1;
        int favo = -100;
        for(int i=0;i<size && Items[i].type == "BREW";i++){
            int favA=0;
            for(int j=0;j<4;j++){
                favA += j*(Items[i].delta[j]);
            }
            if(favA > favo){
                favo = favA;
                current_id = i;
            }
        }
        return current_id;
    }

    static void update(int &action_count,item* items){
        for(int i=0;i<action_count;i++){
            for(int j=0;j<item::ids.size();j++){
                if(items[i].id == item::ids[j]){
                    items[i].used = true;
                }
            }
        }
    }
    bool Can_afford(){
        for(int i=0;i<4;i++){
            if(delta[i] + inv[i] < 0){
                return false;
            }
        }
        return true;
    }

    static void get_igre(int Gem_id,item* Items,int &size,int &wanted_cast,int &limitrec){//get ingreatangts
        cerr << "checking for best cast inside the function..." << endl;
        for(int i=0;i<size ;i++){
            if(Items[i].type != "CAST")
                continue;

            
            if(Items[i].used){
                item::able_to_rest = true;
                return;
            }

            if(Items[i].delta[Gem_id] > 0){
                for(int j=0;j<=Gem_id;j++){
                    if(j == Gem_id)
                        continue;

                    if((Items[i].delta[j] + item::inv[j]) < 0){
                        get_igre(j,Items,size,wanted_cast,limitrec);
                    }
                }
                
                if(limitrec){
                    cerr << "i'll use " << Items[i].id  << " which is " << i << endl;
                    wanted_cast = i;
                    limitrec = 0;
                }
                return;
            }
        }
    }
};





int item::inv[] = {};
//int item::Gem_Vlaue[] ={1,1,1,1};
int item::score = 0;
bool item::able_to_rest = false;
int item::hights_price = 0;
int item::hights_price_index = 0;
vector<int> item::ids ={};


int main()
{

    
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

        item::update(action_count,items);
        

        bool doaloop=false;
        for(int i=0;i<action_count;i++){
            if(items[i].Can_afford() && items[i].type == "BREW"){
                cout << "BREW " << items[i].id << endl;
                doaloop = true;
            }
        }
        if(doaloop)
            continue; //continue with while if done


        int id_ezpo = item::find_eazy_po(items,action_count);//cant find a potion need to fix
        int wanted_cast= 0;
        cerr << "checking for best cast for " << id_ezpo << endl;
        
        for(int i=3;i>=0;i--){
            if((items[id_ezpo].delta[i] + item::inv[i]) < 0 ){
                int limitrec = 1;
                item::get_igre(i,items,action_count,wanted_cast,limitrec);
                cerr << "i: " << i << endl;
                cerr << "id " << items[wanted_cast].id << " is requested and it is " << wanted_cast << endl;
                cerr << "limitrec is "<< limitrec  << endl;
                break;
            }
        }
        
        if(wanted_cast > 0 && items[wanted_cast].Can_afford()){
            cout << "CAST "<< items[wanted_cast].id << endl;
            item::ids.push_back(items[wanted_cast].id);
            item::able_to_rest = true;
        }else if(item::able_to_rest == true){
            cout << "REST" << endl;
            item::able_to_rest = false;
            item::ids.clear();
        }else{
            cout << "WAIT" << endl;
        }
    }
}
