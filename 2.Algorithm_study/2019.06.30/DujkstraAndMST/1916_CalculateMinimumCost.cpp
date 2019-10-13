#include <iostream>
#include <queue>
#include <vector>
#include <utility>

using namespace std;

struct POS{
    int w,v;
};

const int MAX_SIZE = 1e3+5,MAX_VALUE = 1e9+5;
int N,M,S,E;

priority_queue < pair<int,int> > pq;
vector <pair<int,int> > adj_list[MAX_SIZE];

int dist[MAX_SIZE];


void dijkstra(int start){
    
    dist[start] =0;

    pq.push({-dist[start],start});
    
    while(!pq.empty()){
        int cost = -pq.top().first;
        int cur = pq.top().second;
        pq.pop();

        if(dist[cur] < cost ) continue;

        for(int i=0; i<adj_list[cur].size(); i++){
            int next = adj_list[cur][i].second;
            int nCost = cost + adj_list[cur][i].first;

            if(nCost < dist[next]) {
                //cout <<"vertex :"<<next <<" cost:"<<cost<<'\n';
                dist[next] = nCost;
                pq.push({-nCost,next});
            }
        }


    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    for(int i=0; i<M; i++){
        int a,b,w;
        cin >> a >> b >> w;
        adj_list[a].push_back({w,b});
        //adj_list[b].push_back({w,a});
    }
    cin >> S >> E;
    for(int i =1; i<=N; i++) dist[i] = MAX_VALUE;
    dijkstra(S);
    cout << dist[E]<<'\n';


    return 0;

}