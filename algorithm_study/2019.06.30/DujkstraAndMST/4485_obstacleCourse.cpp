#include <iostream>
#include <queue>
#include <vector>

using namespace std;
const int MAX_SIZE = 126 , INF = 1e9;
int map[MAX_SIZE][MAX_SIZE],N,dist[MAX_SIZE][MAX_SIZE];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

struct MAP {
    int x,y,cost;
    bool operator < (const MAP a) const {return cost > a.cost;}
};

void init (){
    for(int i =0; i<N; i++){
        for(int j=0; j<N; j++){
            dist[i][j] = INF;
            map[i][j] = 0;
        }
    }
}

int dijkstra( MAP depart, MAP arrive ){
    priority_queue <MAP> pq; 
    dist[depart.y][depart.x] = map[depart.y][depart.x];
    pq.push({depart.x,depart.y,map[depart.y][depart.x]});

    while(!pq.empty()){
        MAP cur;
        cur.x = pq.top().x;
        cur.y = pq.top().y;
        cur.cost = pq.top().cost;
        pq.pop();
        //cout <<"dist[cur]:"<<dist[cur.y][cur.x]<<'\n';
        if(cur.cost > dist[cur.y][cur.x]) continue;
        
        for(int i =0; i<4; i++){
            MAP next;
            next.x = cur.x +dx[i];
            next.y = cur.y +dy[i];
            next.cost = cur.cost + map[next.y][next.x];
            //cout <<"for-loop\n";
            if(next.x < 0 || next.x >=N ||next.y < 0 || next.y >= N) continue;

            if(next.cost < dist[next.y][next.x]) {
                dist[next.y][next.x] = next.cost;
                pq.push(next);
            }
        }

    }

    return dist[arrive.y][arrive.x];

}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int cnt =0;
    while(1){
        cnt ++;
        cin >> N ;
        if(N == 0) break;
        init();
        for(int i =0; i<N; i++){
            for(int j=0; j<N; j++){
                cin >> map[i][j];
            }
        }
        cout <<"Problem "<<cnt<<": "<<dijkstra({0,0,map[0][0]},{N-1,N-1,map[N-1][N-1]})<<'\n';
    }
    return 0;
}