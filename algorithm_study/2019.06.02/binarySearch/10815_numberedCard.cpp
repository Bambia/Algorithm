#include <iostream>
#include <algorithm>
using namespace std;

int M,N,req;
int card[500001];

bool check(int idx, int num){
    if(card[idx]>=num) return true;
    else return false;
}

bool binarny_search(int num){
    int l = 0, r = N-1;
    while(l<r){
        int mid = (l+r+1)/2; // upper bound
        if(check(mid,num)){
            l = mid;
        }
        else {
            r = mid-1;
        }
    }
    if(card[l] == num) return true;
    else return false;

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N;
    for(int i=0; i<N; i++) cin >> card[i];
    sort(card, card+N, [](const int &l,const int &r){
        return l>r;
    } );

    cin >> M;
    for(int i=0; i<M; i++) {
        cin >> req;
        cout << binarny_search(req) <<'\n';

    }
    return 0;
}