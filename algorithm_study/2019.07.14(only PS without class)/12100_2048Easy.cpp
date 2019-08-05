#include <iostream>
#include <queue>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;


queue <int> q;
int map[20][20];
int N,ans=0;

int getData(int y,int x){
    if(map[y][x]){
        q.push(map[y][x]);
        map[y][x] =0;
    }
}
int addLine(int y, int x, int dy, int dx){
    //3가지 상태 1. 현재 위치 값이 0일 때 2. 현재 값과 전의 값이 합쳐져야할 때 3. 둘다 값이 있지만 합쳐지지 않을 때
    
    while(!q.empty()){
         int value = q.front(); q.pop();
        if(!map[y][x]){ 
            map[y][x] = value;
        }
        else if(map[y][x] == value){
            map[y][x] *= 2;
            x += dx; y += dy;
        }
        else{
            x += dx; y += dy;
            map[y][x] = value;
        }
    }

}
int Move(int dir){
    if(dir == 0){
        // up
        for(int i =0; i<N; i++){
            for(int j=0; j<N; j++) getData(j,i);
            addLine(0,i,1,0);
        }
    }
    else if(dir== 1){
        // down
        for(int i =0; i<N; i++){
            for(int j=N-1; j>=0; j--) getData(j,i);
            addLine(N-1,i,-1,0);
        }
    }
    else if(dir ==2){
        //left
        for(int i =0; i<N; i++){
            for(int j=0; j<N; j++) getData(i,j);
            addLine(i,0,0,1);
        }
    }
    else if(dir ==3){
        //right
        for(int i =0; i<N; i++){
            for(int j=N-1; j>=0; j--) getData(i,j);
            addLine(i,N-1,0,-1);
        }
    }
}
void findMax(){
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){  
            if(ans < map[i][j]) ans = map[i][j];
        }
    }
}
void solve(int pos){

    if( pos== 5){
        findMax();
        return;
    }

    int cmap[20][20];
    memcpy(cmap,map,sizeof(map));
    for(int i =0; i<4; i++){
        Move(i);
        solve(pos+1);
        memcpy(map,cmap,sizeof(cmap));
    }
}

int main(){
    cin >> N;

    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++){
            cin >> map[i][j];
        }
    }
    solve(0);

    cout << ans<<'\n';
    return 0;
}