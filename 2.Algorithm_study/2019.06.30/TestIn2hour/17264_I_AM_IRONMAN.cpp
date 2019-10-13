#include <iostream>
#include <string>
#include <map>
using namespace std;
const int MAX_SIZE = 1001;

int n,p,w,l,g,escape,score;
char condition;
string teamPlayer;
map <string, int> player;

int main(){
    
    cin >> n >> p;
    cin >> w >> l >> g;
    for(int i =0; i<p; i++) {
        string name;
        cin >> name >> condition;
        if(condition == 'W')player.insert({name,1}); 
        else player.insert({name,2});
    }
    for(int i =0; i< n; i++){
        cin >> teamPlayer;
        if (player[teamPlayer] == 1) {
            score += w;
            if(score>=g) escape =1;
        }
        else {
            score -= l;
            if(score<=0) score =0;
        }
    }

    if(escape) cout <<"I AM NOT IRONMAN!!\n";
    else  cout <<"I AM IRONMAN!!\n";
    return 0;
}