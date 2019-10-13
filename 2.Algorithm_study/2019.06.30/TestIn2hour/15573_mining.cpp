#include <iostream>
using namespace std;
struct POS{
    int y,x;
};

int M,N,K,cnt,ans;
int visited[1001][1001];
int map[1001][1001];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
bool isInRange(POS pos){
    if(pos.x< 0 ||pos.y< 0 || pos.x>= M || pos.y >= N) return false;
    return true;
}
void init_visit(){
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++) visited[i][j] = 0;
    }
}
void dfs(POS pos,int cost){
    visited[pos.y][pos.x] = 1;
    //if(cnt >= K) return;
    cnt++;
    //cout <<"cnt : "<<cnt <<' '<<pos.y <<" "<<pos.x <<'\n';
    

    for(int i=0; i<4; i++){
        POS next;
        next.x = pos.x +dx[i];
        next.y = pos.y +dy[i];
        if(!isInRange(next)) continue;
        if(!visited[next.y][next.x] && cost >= map[next.y][next.x]){
            visited[next.y][next.x] =1;
            dfs(next,cost);
        }
    }
    
}
bool check(int D){
    init_visit();
    cnt =0;
    //cout <<" check value\n";
    for(int i =0; i<M; i++){    
        //cout <<"start-----\n";
        if(map[0][i]<= D && !visited[0][i]) dfs({0,i},D);
    }
    for(int i =0; i<N; i++){    
        //cout <<"start||||||1\n";
        if(map[i][0]<= D && !visited[i][0]) dfs({i,0},D);
    }
    for(int i =0; i<N; i++){    

        //cout <<"start||||||2\n";
        if(map[i][M-1]<= D&& !visited[i][M-1]) dfs({i,M-1},D);

    }
    if(cnt >=K) {
        ans = D;
        return true;
    }
    return false;

}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> M >> K;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++) cin >> map[i][j];
    }

    int l=0,r=1e6;
    while(l<r){
        int mid = (l+r+1)/2;
        //cout<<"D: " <<mid<<'\n';
        if(!check(mid)) l = mid;
        else r = mid-1;  
    }

    cout <<ans;

    return 0;
}