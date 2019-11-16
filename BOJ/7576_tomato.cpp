#include <iostream>
#include <queue>

using namespace std;
const int MAX = 1000;
int visited[MAX][MAX];
int map[MAX][MAX];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
int N,M,res;

struct point{
    int x;
    int y;
    int t;
};

bool is_inrange(struct point pos){
    if(pos.x >=0 && pos.x <M && pos.y >=0 && pos.y <N) return true;
    else return false;
}
void bfs(){
    queue <point> q;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++ ){
            if(map[i][j]==1){
                point start;
                start.x =j;
                start.y =i;
                start.t =0;  
                q.push(start);
                visited[start.y][start.x]=1;
            }
        }
    }

    while(!q.empty()){
        point cur;
        cur = q.front();
        q.pop();

        for(int i=0; i<4; i++){
            point next;
            next.x = cur.x+dx[i];
            next.y = cur.y+dy[i];
            next.t = cur.t+1;
            
            if(!is_inrange(next)) continue;

            if(visited[next.y][next.x]==0 && map[next.y][next.x] == 0){
                visited[next.y][next.x] =1;
                map[next.y][next.x]=1;
                q.push(next);
                
                res = next.t;
            }
        }
    }
 
}

int main(){
    cin >> M >> N;

    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++ ){
            cin >> map[i][j];
        }
    }

  
    bfs();
    /*
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++ ){
            cout << map[i][j]<<' ';
        }
        cout <<'\n';
    }*/

    int not_search=0;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++ ){
            if(map[i][j]==0) not_search =1;
        }
    }
    if(not_search) cout <<"-1";
    else cout << res;
    return 0;
}