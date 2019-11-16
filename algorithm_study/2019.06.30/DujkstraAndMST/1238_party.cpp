#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>
using namespace std;

const int MAX_SIZE = 1e3+2,MAX_VALUE = 1e9+5;

int M,N,X,maxTime;

vector <pair <int,int> > adj1[MAX_SIZE],adj2[MAX_SIZE];
int dist1[MAX_SIZE],dist2[MAX_SIZE];

void init(){
    for(int i =1; i<=N; i++) {
        dist1[i] = MAX_VALUE;
        dist2[i] = MAX_VALUE;
    }
}
int djikstra1(int s){
    priority_queue <pair<int,int> > pq;
    dist1[s] =0;
    pq.push({-dist1[s],s});

    while(!pq.empty()){
        int cost = -pq.top().first; 
        int cur =  pq.top().second;
        pq.pop();
        if(cost > dist1[cur]) continue;
        for(int i=0; i< adj1[cur].size(); i++){
            int nCost = adj1[cur][i].first + cost; 
            int next = adj1[cur][i].second;

            if( nCost < dist1[next] ) {
                dist1[next] = nCost;
                pq.push({-nCost,next});
            }
        }
    }
}
int djikstra2(int s){
    priority_queue <pair<int,int> > pq;
    dist2[s] =0;
    pq.push({-dist2[s],s});

    while(!pq.empty()){
        int cost = -pq.top().first; 
        int cur =  pq.top().second;
        pq.pop();
        if(cost > dist2[cur]) continue;
        for(int i=0; i< adj2[cur].size(); i++){
            int nCost = adj2[cur][i].first + cost; 
            int next = adj2[cur][i].second;

            if( nCost < dist2[next] ) {
                dist2[next] = nCost;
                pq.push({-nCost,next});
            }
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M >> X;
    for(int i=0; i<M; i++){
        int a,b,t;
        cin >> a >> b >> t;
        adj1[a].push_back({t,b});
        adj2[b].push_back({t,a});
    } 
    
    init();
    djikstra1(X);
    djikstra2(X);

    for(int i =1; i<=N; i++){
        if(dist1[i]+dist2[i] > maxTime) maxTime = dist1[i]+ dist2[i];
    }
        
    cout << maxTime <<'\n';

    return 0;
}