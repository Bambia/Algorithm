#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

struct POS{
    int x,y;
};

int N,M;
int map[8][8];
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

int ret=0,ans=0;

void bfs(){
    
    int cmap[8][8] = {0,};
    int visited[8][8] = {0,};

    memcpy(cmap,map,sizeof(map));
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(!visited[i][j] && cmap[i][j] == 2){
                visited[i][j] = 1;
                queue <POS> q;
                q.push({j,i});

                while(!q.empty()){
                    POS cur = q.front();
                    q.pop();

                    for(int i=0; i<4; i++){
                        POS next;
                        next.x = cur.x + dx[i];
                        next.y = cur.y + dy[i]; 

                        if(next.y >= N || next.x >= M ||next.y < 0 || next.x < 0  ) continue;

                        if(cmap[next.y][next.x] == 0 && !visited[next.y][next.x] ) {
                            cmap[next.y][next.x] = 2;
                            visited[next.y][next.x] = 1;
                            q.push(next);
                        }
                    }
                }
            }
        }
    }
    ret = 0;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(cmap[i][j] == 0 ) ret++;
        }
    }
    if(ret > ans ) ans = ret;
}
void dfs(int idx){
    
    if(idx == 3){
        bfs();
        return;
    }

    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(map[i][j] != 1 && map[i][j] != 2){
                map[i][j] = 1;
                dfs(idx+1);
                map[i][j] = 0;
            }
        }
    }
    

}

int main(){

    cin >> N >> M;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin >> map[i][j];
        }
    }

    dfs(0);
    cout <<ans<<'\n'; 
    return 0;
}