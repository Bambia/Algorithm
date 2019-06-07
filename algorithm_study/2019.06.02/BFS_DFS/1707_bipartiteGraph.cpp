#include <iostream>
#include <quque>
#include <vector>

using namespace std;
struct graph{
    int v,color;
}
int tc,V,E,x,y;
vector <int> adj[20000];
int checked[20000];

// blue =1 , red =2

void bfs(int pos){
    queue <graph> q;
    q.push(pos);

    while(!q.empty()){
        graph cur;
        cur = q.front();
        q.pop();

        for(int i=0; i<adj[cur].size(); i++){
            graph next = adj[cur][i];
            q.push(adj[cur][i]);
        }
    } 
}

int main(){
    while(tc--){
        cin >> V >> E;
        for(int i=0; i<E; i++){
            cim >> x >> y;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }

        for(int i=1; i<=V; i++){
            graph a;
            a.v = i;
            a.color = 1;
            if(!checked[i]) bfs(i);
        }
    }     

    return 0;
}