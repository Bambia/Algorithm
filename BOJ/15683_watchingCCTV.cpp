#include <iostream>

using namespace std;
struct CCTV{
    int x,y,type;
};


int rotate_table[5] = {4,2,4,4,1}; //1번 카메라부터 5번까지

int N,M;
int map[9][9];
//int cmap[9][9];
CCTV cctv[9];
int cctv_size;
int ret = 100;

void map_cpy(int dest[9][9] , int src[9][9]){
        for(int i=0; i<N; i++){
            for(int j=0; j<M; j++){
                dest[i][j] = src [i][j];
            }
        }
}
void update(int dir, struct CCTV cctv){
    dir = (dir % 4) ;

    if(dir == 0){ //북쪽
        for(int i =cctv.y-1; i>=0; i--){
            if(map[i][cctv.x] == 6 ) break;
            else if(map[i][cctv.x] == 0 ) map[i][cctv.x] = -1;
            else continue;
        }
    }
    else if(dir ==1){ // 동쪽
        for(int i =cctv.x+1; i<M; i++){
            if(map[cctv.y][i] == 6 ) break;
            if(map[cctv.y][i] == 0 ) map[cctv.y][i] = -1;
            else continue;
        }
    }
    else if(dir ==2){ // 남쪽
        for(int i =cctv.y+1; i<N; i++){
            if(map[i][cctv.x] == 6 ) break;
            else if(map[i][cctv.x] == 0 ) map[i][cctv.x] = -1;
            else continue;
        }
    }
    else if(dir ==3){ // 서쪽
        for(int i =cctv.x-1; i>=0; i--){
            if(map[cctv.y][i] == 6 ) break;
            else if(map[cctv.y][i] == 0 ) map[cctv.y][i] = -1;
            else continue;
        }
    }
}

void dfs(int cctv_idx){
    if(cctv_idx == cctv_size){
        int cnt=0;
        for(int i=0; i<N; i++){
            for(int j=0; j<M; j++){
                if(map[i][j]== 0) cnt ++;
            }
        }
        if(ret > cnt) ret = cnt;

        return;
    }

    int type = cctv[cctv_idx].type;
    int dir = rotate_table[type];

    int backup[9][9];
    for(int i=0; i<dir; i++){
        map_cpy(backup,map);
        if(type == 0){
            update(i,cctv[cctv_idx]);
        }
        else if(type ==1){
            update(i,cctv[cctv_idx]);
            update(i+2,cctv[cctv_idx]);
            
        }
        else if(type ==2){
            update(i,cctv[cctv_idx]);
            update(i+1,cctv[cctv_idx]);
        }
        else if(type ==3){
            update(i,cctv[cctv_idx]);
            update(i+1,cctv[cctv_idx]);
            update(i+2,cctv[cctv_idx]);
        }
        else if(type ==4){
            update(i,cctv[cctv_idx]);
            update(i+1,cctv[cctv_idx]);
            update(i+2,cctv[cctv_idx]);
            update(i+3,cctv[cctv_idx]);
        }
        dfs(cctv_idx+1);
        map_cpy(map,backup);
    }
}   
int main(void){
    cin >> N >> M;
    for(int i =0; i<N; i++){
        for(int j=0; j<M; j++){
            cin >> map[i][j];

            if(map[i][j]!= 6 && map[i][j]!= 0) {// 6은 벽 0은 공간
                    cctv[cctv_size].x = j;
                    cctv[cctv_size].y = i;
                    cctv[cctv_size].type = map[i][j] -1;  //인덱스가 카메라 크기보다 1씩 작기 떄문
                    cctv_size++;

            }
        }
    }

    dfs(0);
    cout << ret;

    return 0;
} 