#include <iostream>
using namespace std;
const int MAX_SIZE = 1e6+1;
int parent[MAX_SIZE];
int m,n;
int cmd,x,y;

int Find(int element){
    if(parent[element] == -1 )  return element;
    
    else return parent[element] = Find(parent[element]);
}

void Union(int u,int v){
    u = Find(u);
    v = Find(v);
    if(u == v) return;

    parent[u] = v;
}


int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;

    for(int i=0; i<n+1; i++) parent[i] = -1;
    for(int i=1; i<=m; i++) {
        cin >> cmd >> x >> y;
        if(!cmd) Union(x,y);
        else {
            if(Find(x)==Find(y)) cout <<"YES\n";
            else cout <<"NO\n";
        }
    }
    return 0;
}