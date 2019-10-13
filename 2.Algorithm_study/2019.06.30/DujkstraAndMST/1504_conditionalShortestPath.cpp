#include <iostream>
#include <vector>
#include <utility>
#include <queue>

using namespace std;

const long long MAX_SIZE = 1e3,INF = 1e9+5;
int a,b,c,C1,C2,N,E;
long long dist[MAX_SIZE],path1,path2;

vector <pair <int,int> > adj[MAX_SIZE];

void init(){
    for(int i =0; i<=N; i++) dist[i] = INF;
}

int dijkstra(vector<pair<int,int> > v[], long long dist[], int start, int end){
    init();
    priority_queue <pair<int,int> > pq;
    dist[start] = 0;
    pq.push({-dist[start],start});
    while(!pq.empty()){
        int cost = -pq.top().first;
        int cur = pq.top().second;
        pq.pop();

        if(cost > dist[cur] ) continue;

        for(int i =0; i<v[cur].size(); i++  ){
            int nCost = v[cur][i].first + cost; 
            int next = v[cur][i].second;
            if(nCost < dist[next]){
                pq.push({-nCost,next});
                dist[next] = nCost;
            }

        }
    }

    return dist[end];
}



int main(){
    cin >> N >> E;

    for(int i =0; i<E; i++) {
        cin >> a >> b >>c;
        adj[a].push_back({c,b});
        adj[b].push_back({c,a});
    
    }
    cin >> C1 >> C2;
    
    path1 = dijkstra(adj,dist,1,C1) + dijkstra(adj,dist,C1,C2) + dijkstra(adj,dist,C2,N);
    path2 = dijkstra(adj,dist,1,C2) + dijkstra(adj,dist,C2,C1) + dijkstra(adj,dist,C1,N);
    //cout <<path1 << " "<<path2 <<'\n';
    if(path1 <INF && path1 < path2) cout <<path1<<'\n';
    else if(path2 <INF && path2 < path1) cout <<path2 <<'\n';
    else cout <<"-1\n";

    return 0;
}