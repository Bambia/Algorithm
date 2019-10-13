#include <iostream>
#include <utility>
using namespace std;

int main(){
    int N,M,bundle= 1001,single =1001,ans=0;
    pair <int ,int> price[51];

    cin >> N >> M;
    for(int i=0; i<M; i++) {
        cin >> price[i].first >> price[i].second;
        if(price[i].first < bundle) bundle = price[i].first;
        if(price[i].second < single) single = price[i].second;
    }
    
    //cout <<bundle <<' '<<single<<'\n';
    if(bundle<single*6) {
        while(N>6){
            N -= 6;
            ans += bundle;
        }
    }
    else {
        ans = single*N;
        N=0;
    }

    if(single*N>bundle) ans += bundle;
    else ans += single*N;
    

    cout <<ans <<'\n';
    return 0;
}