#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;
struct POS{
    int a,b,c;
};
const int MAX_SIZE = 1e3+5;
int M,N,result;
vector <POS> v;

int parent[MAX_SIZE];
int find(int cmp){
    if(parent[cmp] == -1) return cmp;
    else return parent[cmp] = find(parent[cmp]);
}

bool Marge(int u , int v){
    u = find(u);
    v = find(v);

    if(u == v) return false;

    parent[u] = v;
    
    return true;

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    for(int i=0; i<M; i++) {
        POS in;
        cin >> in.a >> in.b >> in.c;
        v.push_back(in);
    }
    sort(v.begin(),v.end(),[](const POS &l , const POS &r){
        return l.c < r.c;
    });

    for(int i =1; i<=N; i++) parent[i] = -1;
    
    for(int i =0; i<M; i++){
        if(Marge(v[i].a,v[i].b)){
            result += v[i].c;
        }
    }
    cout <<result <<'\n';

    return 0;
}