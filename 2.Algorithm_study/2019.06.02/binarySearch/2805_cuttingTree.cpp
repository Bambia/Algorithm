#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;
typedef double db;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;


ll N, M, l, r;
int tree[1000000];


bool check(long long x){
    long long sum =0;
    for(int i=0; i<N; i++){
        sum += max(0LL, tree[i] - x);
         //if(tree[i]>x)sum += (tree[i]-x);     
    }
    if(sum >= M ) return true;
    else return false;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N>> M;
    for(int i =0; i<N; i++){
        cin >> tree[i];

    }   
    l = 0, r = 1e9;
    while(l<r){
        ll mid = (l+r+1) /2;
        if(check(mid)){
            l = mid;
        }   
        else{
            r = mid-1;
        }
    }
    cout << l;
    return 0;
}