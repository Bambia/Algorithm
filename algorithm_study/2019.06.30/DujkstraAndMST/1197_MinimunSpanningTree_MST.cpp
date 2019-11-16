#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;
const int MAX_SIZE = 10001;

struct POS{
    int a,b,w;
    POS(){}
};

int p[MAX_SIZE];
int V,E;
vector <POS> v;
int result=0;
int find(int cp){
    if(p[cp]== -1) return cp;
    else return p[cp] = find(p[cp]); 
}

bool Merge(int u,int v){
    u = find(u);
    v = find(v);
    if(u == v) return false;

    p[u] = v;
    return true;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> V >> E;
    for(int i=0; i<E; i++){
        POS C;
        cin >> C.a >>C.b >> C.w;
        v.push_back(C);
    }
    sort(v.begin(), v.end(),[]( POS l,  POS r){
        return l.w < r.w;
    });
    for(int i=0; i<=V; i++) p[i] = -1;
    

    for(int i=0; i<E; i++){
        if(Merge(v[i].a,v[i].b)) {
            result += v[i].w;
        }

    }
    cout<< result<<'\n';

    return 0;
}