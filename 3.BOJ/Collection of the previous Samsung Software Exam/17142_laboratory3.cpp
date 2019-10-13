#include <iostream>
#include <queue>
#include <cstring>
#include <vector>

using namespace std;
struct POS{
    int x,y;
    //int time;
};

const int INF = 1e9;
int N,M,t,ans=INF,K;

bool Select[10];
int map[50][50];
int visited[50][50];
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
vector <POS> v;
queue <POS> q;

void bfs(){
    
    int cnt =0,t=0;
    //cout <<"bfs\n";
    while(!q.empty()){
        POS cur = q.front(); q.pop();

        for(int i=0; i<4; i++){
            POS next;
            next.x = cur.x + dx[i];
            next.y = cur.y + dy[i];
            //next.time = cur.time +1;
            
            if(next.x >= N || next.y >= N || next.x<0 || next.y <0 ) continue;
            if(map[next.y][next.x] != 1 && visited[next.y][next.x] == -1){
                visited[next.y][next.x] = visited[cur.y][cur.x]+1;
                if(map[next.y][next.x] == 0){
                    cnt ++ ;
                    t = visited[next.y][next.x];
                }
                q.push(next);
            }
            
             
        }

    }
    if(cnt == K && t < ans ) ans = t;
}

void solve(int idx,int cnt,int size){
    if(cnt == M){
        memset(visited,-1,sizeof(visited));
        for(int i=0; i<size; i++){
            if(Select[i]){ // 3개의 activation point를 q에 넣어주고 3개의 방문 표시를 0으로 만든다. 
                q.push({v[i].x,v[i].y});
                visited[v[i].y][v[i].x] = 0;
            } 
        }
        bfs();
        return;
    }
    for(int i=idx; i<size; i++){
            if(!Select[i] ) {
                Select[i] = true;
                solve(i+1,cnt+1,size);
                Select[i] = false;
            }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> M;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin >> map[i][j];
            if(map[i][j] == 2) v.push_back({j,i});
            if(map[i][j] == 0) K += 1;
        }
    }

    solve(0,0,v.size());
    if(ans == INF) cout << -1<<'\n';
    else cout << ans <<'\n';

    return 0;
}