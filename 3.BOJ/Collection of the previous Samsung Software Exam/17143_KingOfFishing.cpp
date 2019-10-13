#include <iostream>
#include <cstring>

using namespace std;

struct Shark{
    int s,d,z;
};
struct POS{
    int r,c;
    int dir;
};
Shark map[101][101];
int R,C,N;
int r,c,s,d,z,ans;
void debugging(){
    cout <<"speed map\n";
    for(int i=0; i<R; i++){
        for(int j=0; j<C; j++){
            cout << map[i][j].s<<' ';
        }
        cout <<'\n';
    }
    cout <<'\n';
    cout <<"direction map\n";
    for(int i=0; i<R; i++){
        for(int j=0; j<C; j++){
            cout << map[i][j].d<<' ';
        }
        cout <<'\n';
    }
    cout <<'\n';
    cout <<"size map\n";
    for(int i=0; i<R; i++){
        for(int j=0; j<C; j++){
            cout << map[i][j].z<<' ';
        }
        cout <<'\n';
    }
    cout <<'\n';
}
POS moveShark(int speed,POS pos){
    POS nPos = pos;
    int dist = speed; // 속도만큼 1초에 움직이기 때문에
    if(nPos.dir == 1 || nPos.dir == 2) dist = dist%((R-1)*2);
    else if(nPos.dir == 3 || nPos.dir == 4) dist = dist%((C-1)*2);
    
    //cout <<"["<<pos.r<<'.'<<pos.c<<"] have to move "<<dist <<" steps\n";
    while(dist--){
        if(nPos.dir == 1) {
            nPos.r--;
            if(nPos.r < 0 ) {
                nPos.r = 1;
                nPos.dir = 2;
            } 
        }
        else if(nPos.dir == 2){
            nPos.r++;
            if(nPos.r >= R ) {
                nPos.r = R-2;
                nPos.dir = 1;
            } 
        }
        else if(nPos.dir == 3){
            nPos.c++;
            if(nPos.c >= C ) {
                nPos.c = C-2;
                nPos.dir = 4;
            } 
        }
        else if(nPos.dir == 4){
            nPos.c--;
            if(nPos.c < 0 ) {
                nPos.c = 1;
                nPos.dir = 3;
            } 
        }
    }
    //cout <<"next location: ["<<nPos.r<<'.'<<nPos.c<<"]\n";
    return nPos;
}

void update(){
    Shark cmap[101][101] = {0,};
    for(int i=0; i<R; i++){
        for(int j=0; j<C; j++){
            if(map[i][j].z != 0){ //현재 위치의 상어가 있으면 이동이 필요함 
                POS target = moveShark(map[i][j].s,{i,j,map[i][j].d}); // 맵 정보와 현재 상어의 위치를 넘겨주고 다음 상어의 위치와 변한 dir을 알려준다.
                
                if(cmap[target.r][target.c].z != 0 && map[i][j].z < cmap[target.r][target.c].z ) continue; //이미 그 자리에 상어가 있을수도 있으니 충돌(collusion) 처리 해주자
                    
                cmap[target.r][target.c] = map[i][j]; // 임시 맵에 1초후의 상어의 크기,속도를 넘겨준다
                cmap[target.r][target.c].d = target.dir; // 방향은 변경이 생기기 때문에 따로 저장한 정보를 넘겨준다.
                
            }
        }
    }
    memcpy(map,cmap,sizeof(cmap));
}

void solve(){
    Shark clean = {0,};
    int king = 0;
    //debugging();
    while(king<C){
        for(int i =0; i<R; i++){
            if(map[i][king].z != 0) {
                ans += map[i][king].z;
                map[i][king] = clean;
                break;
            } 
        }
        //debugging();
        update();
        king++;
    }
    

}

int main(){
    cin >> R >> C >> N;

    for(int i=0; i<N; i++){
        Shark in;
        cin >> r >> c >> in.s >> in.d >> in.z;
        map[r-1][c-1] = in;    
    }
    // debugging();
    // update();
    // debugging();
    if(N!=0) solve();
    cout <<ans<<'\n';

    return 0;
}

