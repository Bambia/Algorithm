#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
struct POS{
    int y,x;
    int dis;
};

int N,M,D,ans;
int map[15][15],cmap[15][15];
int dx[3] = {-1,0,1}; // 좌 위 우
int dy[3] = {0,-1,0}; // 좌 위 우
vector <POS> detect;
vector <int> archer;

void bfs(int archer,int dist){
    queue<POS> q;
    int find =0,limitDist= 0;
    q.push({N-1,archer,1});

    while(!q.empty()){
        POS cur = q.front();
        q.pop();
        
        if(cmap[cur.y][cur.x] == 1&& !find ){
                detect.push_back(cur);
                //cout <<"Archer("<<archer<<"): ["<< cur.x <<','<<cur.y<<"]"<<'\n'; 
                find = 1;
        }
        if(find) break;
        if(cur.dis == dist) limitDist = 1;
        
        if(!limitDist){
            for(int i=0; i<3; i++){
                POS next;
                next.y = cur.y + dy[i];
                next.x = cur.x + dx[i];
                next.dis = cur.dis +1;
                if(next.x >= M || next.y <0 || next.x <0 ) continue;
                q.push(next);
                
            }
        }
        
    }
}
void mapUpdate(){
    for(int i=N-1; i>=1; i--){
        for(int j=0; j<M; j++){
            cmap[i][j] = cmap[i-1][j]; 
        }
    }
    for(int j=0; j<M; j++) cmap[0][j] = 0;
    
    // cout <<"updated\n";
    // for(int i=0; i<N; i++){
    //     for(int j=0; j<M; j++){
    //         cout <<cmap[i][j]<<' ';
    //     }
    //     cout <<'\n';
    // }
    // cout <<'\n';
}
bool checkEnemy(){
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(cmap[i][j] == 1) return true;
        }
    }

    return false;
}
void dfs(int idx){
    if(archer.size() == 3){
        //for(int i =0; i<archer.size(); i++) cout <<archer[i] <<' ';
        //cout <<'\n';
        memcpy(cmap,map,sizeof(map));
        int ret = 0;
        // cout <<"original\n";
        // for(int i=0; i<N; i++){
        //     for(int j=0; j<M; j++){
        //         cout <<cmap[i][j]<<' ';
        //     }
        //     cout <<'\n';
        // }
        // cout <<'\n';
        //for(int k = 0; k<N; k++){ // 맵의 세로크기만큼 반복
        while(checkEnemy()){
            for(int i =0; i<3; i++) bfs(archer[i],D);
            for (int i=0; i<detect.size(); i++) {
                if(cmap[detect[i].y][detect[i].x] != 0 ) {
                    cmap[detect[i].y][detect[i].x] = 0;// 타겟팅된 궁수 제거
                    ret++;
                }
            }
            detect.clear();
            mapUpdate();// 턴 넘김
        }
        //cout << "ret:"<<ret <<'\n';
        if(ret > ans) ans = ret;
    }
    for(int i=idx; i<M; i++){
        archer.push_back(i);
        dfs(i+1);
        archer.pop_back();
    }
}

int main(){

    cin >> N >> M >> D;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin >> map[i][j];
        }
    }
    dfs(0);
    cout <<ans<<'\n';
    return 0;
}