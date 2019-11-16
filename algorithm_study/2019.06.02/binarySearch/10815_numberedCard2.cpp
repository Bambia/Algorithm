#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct CARD{
    int num,amount;
};

int M,N,req;
vector <CARD> card;
vector <int> v;

bool check(int idx, int num){
    if(card[idx].num >=num) return true;
    else return false;
}

int binarny_search(int num){
    int l = 0, r = card.size()-1;
    while(l<r){
        int mid = (l+r+1)/2; // upper bound
        if(check(mid,num)){
            l = mid;
        }
        else {
            r = mid-1;
        }
    }
    //cout <<"l = "<<l << " card[l]="<<card[l].num <<" req: "<<num << " amount : "<<card[l].amount<<'\n';
    if(card[l].num == num) return card[l].amount;
    else return 0;

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N;
    for(int i=0; i<N; i++) {
        int n;
        cin >> n;
        v.push_back(n);
    }
    sort(v.begin(), v.end(), [](const int &l,const int &r){
        return l>r;
    } );
    /*
    for(int i=0; i<N-1; i++) {
        cout << v[i] <<'.';
    }
    cout <<'\n';
    */
    CARD temp;
    temp.num = v[0];
    temp.amount = 1;
    card.push_back(temp);
    //card.push_back({v[0],0});
    int j =0;
    for(int i=1; i<v.size(); i++){
        if(v[i]== card[j].num) card[j].amount++;
        else {
            card.push_back({v[i],1});
            j++;
        }
    }

    /*for(int i=0; i<card.size(); i++) {
        cout << card[i].num <<'(' <<card[i].amount<<')'<<' ';
    }
    cout <<'\n';
    */

    cin >> M;
    for(int i=0; i<M; i++) {
        cin >> req;
        cout << binarny_search(req) <<' ';

    }
    return 0;
}