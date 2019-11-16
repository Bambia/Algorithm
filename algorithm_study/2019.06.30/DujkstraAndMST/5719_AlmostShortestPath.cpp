#include <iostream>
#include <vector>
#include <queue>

using namespace std;
struct MAP {
    int d,cost;
    bool operator < (const MAP a) const {return cost > a.cost;}

};

const int MAX_SIZE = 501,INF = 1e9+5;
int S,E,N,M,U,V,P,ans;
vector <MAP> adj[MAX_SIZE],path[MAX_SIZE];
int visited[MAX_SIZE][MAX_SIZE];

int dist[MAX_SIZE];
void init(){
    for(int i =0; i<=N; i++) {
        adj[i].clear();
        path[i].clear();   
    }
    for(int i =0; i<=N; i++){
        for(int j=0; j<=N; j++){
            visited[i][j] =0;
        }
    }
}

int dijkstra(int s){
    for(int i =0; i<=N; i++) dist[i] = INF;
    priority_queue <MAP> pq;
    dist[s] = 0;
    pq.push({s,dist[s]});
    while(!pq.empty()){
        int cost = pq.top().cost ;
        int cur = pq.top().d;
        pq.pop();
        if(cost > dist[cur]) continue;
        
        for(int i=0; i<adj[cur].size(); i++){
            int nCost = adj[cur][i].cost +  cost;
            int next = adj[cur][i].d;
            
            if(visited[cur][next]) continue;

            if(nCost < dist[next]){
                dist[next] = nCost;
                pq.push({next,nCost});
            }
        }
    }

    return dist[E];
}

int deletePath(int E){
    queue <int> q;
    q.push(E);
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        for(int i=0; i< path[cur].size(); i++){
            int prev = path[cur][i].d;
            int pCost = path[cur][i].cost;
            if(dist[prev]+ pCost == dist[cur] ){
                visited[prev][cur] = 1;
                q.push(prev);
            }
        }
    }
    //cout <<"delete shortest path \n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    while(1){
        cin >> N >> M;
        if(N == 0 && M == 0) break;
        cin >> S >> E;
        init();
        for(int i=0; i<M; i++) {
            cin >> U >> V >> P;
            adj[U].push_back({V,P});
            path[V].push_back({U,P});
        }
        dijkstra(S);
        deletePath(E);
        ans = dijkstra(S);

        if(ans == INF) cout <<"-1" <<'\n';
        else cout <<ans <<'\n';
        
    }
    return 0;
}