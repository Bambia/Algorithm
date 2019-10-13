#include <iostream>
#include <queue>
using namespace std;

struct anxis{
    int x,y;
};
int N,M,K;
int map[51][51];
int visited[51][51];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,-1,0,1};
int ans;
void map_init(){
    for(int i=0; i<N; i++){
        for(int j=0; j <M; j++){
            map[i][j] = 0;
            visited[i][j] = 0;
        }
    }

}
void bfs(anxis pos){
    queue <anxis> q;
    q.push(pos);
    visited[pos.y][pos.x] =1;

    while(!q.empty()){
        anxis cur; 
        cur = q.front();
        q.pop();
        for(int i =0; i<4; i++ ){
            anxis next;
            next .x = cur.x +dx[i];
            next .y = cur.y +dy[i];
            if(next.x <0 ||next.x >=M || next.y <0 ||next.y >=N) continue;
            if(map[next.y][next.x] && !visited[next.y][next.x]){
                q.push(next);
                visited[next.y][next.x] =1;
            }
        }
    }
}
int main(){
    int tc=0;
    cin >> tc;

    while(tc--){
        ans =0;
        cin >> M >> N >> K;
        for(int i=0; i<K; i++){
            int x,y;
            cin >> x >> y;
            map[y][x] = 1;
        }
        /*for(int i=0; i<N; i++){
            for(int j=0; j <M; j++){
                cout <<map[i][j] <<" ";
            }
            cout <<'\n';
        }*/

        for(int i=0; i<N; i++){
            for(int j=0; j<M; j++){
                anxis pos;
                pos.x = j;
                pos.y = i;
                if(map[i][j] && !visited[i][j]) {
                    bfs(pos);
                    //cout << "map[" << i<<"]"<<"[" << j<<"]"<< "\n";
                    ans++;
                }
            }
        }
        
    cout << ans<<'\n' ;
    map_init();
    }
    
    return 0;
} 