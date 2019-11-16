#include <iostream>
#include <queue>
#include <vector>
#include <utility>
#include <string>
using namespace std;

struct POS {
    int x,y;
    int t;     
};
bool operator < (POS l , POS r){
    return l.t > r.t;
}


const int MAX_SIZE = 101,INF = 1e9+5;

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int N,M,block;
int visited[MAX_SIZE][MAX_SIZE];
int dist[MAX_SIZE][MAX_SIZE];
string map[MAX_SIZE];
priority_queue <POS> pq;

void djikstra(POS s){
    dist[s.y][s.x] = 0;
    pq.push(s);

    //while(!pq.empty()){
    for(int i=0; i<N*M-1; i++){
        POS cur;
        
        cur.x = pq.top().x;
        cur.y = pq.top().y;
        cur.t = pq.top().t;
        pq.pop();
        
        
        for(int i =0; i<4; i++){
            POS next;
            next.x = cur.x +dx[i];
            next.y = cur.y +dy[i];
            if(next.x < 0 || next.y < 0 || next.x >=M || next.y >=N ) continue;
            if( map[next.y][next.x] =='1') block = 1;
            else if( map[next.y][next.x] =='0' ) block = 0;

            next.t = cur.t+ block;

            if( (dist[next.y][next.x] > next.t ) ){
                //cout <<"["<<next.y<<"]" <<" ["<<next.x<<"]";
                //cout <<"  ="<<next.t<<'\n';
                dist[next.y][next.x] =next.t;
                pq.push(next);
            }
        }
        
    }

}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> M >> N;
    for(int i=0; i<N; i++){
            cin >> map[i];
    }
    POS start;
    start.x =0;
    start.y = 0;
    start.t = 0;

    for(int i=0; i<N; i++) 
        for(int j=0; j<M; j++) dist[i][j] = INF;
    
    djikstra(start);

    cout << dist[N-1][M-1] <<'\n';

    return 0;
}