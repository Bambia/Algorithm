#include <iostream>
#include <queue>
#include <vector>
#include <utility>
using namespace std;

const int MAX_SIZE =  2e4+5, MAX_VALUE = 1e9+5;
int dist[MAX_SIZE]; 
int V,E,K,u,v,w;

vector <pair <int,int> > adj[MAX_SIZE];
priority_queue <pair<int,int> > pq;
void dijkstra(int s){
    dist[s] = 0;
    pq.push({-dist[s],s});
    while(!pq.empty()){
        int cost = -pq.top().first;
        int cur = pq.top().second;
        pq.pop();
        if(dist[cur] <cost) continue;

        for(int i=0; i<adj[cur].size(); i++){
            int nCost =  adj[cur][i].first +cost; 
            int next =  adj[cur][i].second;

            if(nCost < dist[next]){
                dist[next] =nCost;
                pq.push({-nCost,next});
            }
        }
    }
}
int main(){

    cin >> V  >> E >> K;

    for(int i=0; i<E; i++) {
        cin >> u >> v >> w;
        adj[u].push_back({w,v});

    }
    for(int i =1; i<=V; i++) dist[i] = MAX_VALUE;

    dijkstra(K);
    for(int i=1; i<=V; i++) {
        if(dist[i] == MAX_VALUE) cout <<"INF\n";
        else cout << dist[i]<<'\n'; 
    }
    return 0;

}