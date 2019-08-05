#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct POS{
    int a,b,c;

};
const int MAX_SIZE = 1e5+5;
vector <POS> adj;
int p[MAX_SIZE],ans,last,M,N;

int find(int c){
    if(p[c] == -1) return c;
    return p[c] = find(p[c]);
}

bool Marge(int u,int v){
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
    cin >> N >> M;
    for(int i=0; i<M; i++){
        POS in;
        cin >> in.a >> in.b >> in.c;
        adj.push_back(in);
    }
    for(int i =0; i<=N; i++) p[i] = -1;

    sort(adj.begin(),adj.end(),[](const POS &l,const POS &r){
        return l.c < r.c;
    });
    for(int i =0; i<M; i++){
        if( Marge(adj[i].a,adj[i].b) ) {
            ans += adj[i].c;
            last = i;
        }
    }
    ans -= adj[last].c;
    cout <<ans <<'\n';

    return 0;
}