#include <iostream>

using namespace std;
struct PIPE{
    int x,y,type;
};

PIPE pipe;

int N;
int map[17][17];
int visited[17][17];
int cnt;

void dfs(struct PIPE pos){ // 0 은 가로 1은 세로 2는 대각선
    if(pos.x == (N-1) && pos.y == (N-1)){
        cnt++;
        //cout <<"find ans\n";
        return;
    }
    else if(pos.x >= N || pos.y >= N){
        //cout <<"there is wall\n";
        return;
    }

    
        if(pos.type==0){ //가로 
           // cout <<"type 0\n";
            if(map[pos.y][pos.x+1] ==0 ){ 
                PIPE next;
                next.x = pos.x +1;
                next.y = pos.y;
                next.type = 0;
                dfs(next);
            }
           if(map[pos.y][pos.x+1] ==0 && map[pos.y+1][pos.x] ==0 && map[pos.y+1][pos.x+1] ==0 ){ 
                PIPE next;
                next.x= pos.x +1;
                next.y= pos.y +1;
                next.type = 2;
                dfs(next);
            }
        }
        else if(pos.type==1){ //세로
            //cout <<"type 1\n";
            if(map[pos.y+1][pos.x] ==0){ 
                PIPE next;
                next.y = pos.y +1;
                next.x = pos.x;
                next.type = 1;
                dfs(next);
            }
           if(map[pos.y][pos.x+1] ==0 && map[pos.y+1][pos.x] ==0 && map[pos.y+1][pos.x+1] ==0 ){ 
                PIPE next;
                next.x =pos.x +1;
                next.y =pos.y+1;
                next.type = 2;
                dfs(next);
            }
        }
        else if(pos.type==2){ //대각선
        //cout <<"type 2\n";
            if(map[pos.y][pos.x+1] ==0){ 
                PIPE next;
                next.x =pos.x +1;
                next.y = pos.y;
                next.type = 0;
                dfs(next);
            }
            if(map[pos.y+1][pos.x] ==0){ 
                PIPE next;
                next.y= pos.y+1;
                next.x =pos.x;
                next.type = 1;
                dfs(next);
            }
           if(map[pos.y][pos.x+1] ==0 && map[pos.y+1][pos.x] ==0 && map[pos.y+1][pos.x+1] ==0 ){ 
                PIPE next;
                next.x =pos.x+1;
                next.y = pos.y+1;
                next.type = 2;
                dfs(next);
            }
        }
}
int main(void){
    cin >> N;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin >> map[i][j];
        }
    }
    pipe.x = 1;
    pipe.y = 0;
    pipe.type = 0; // 0 은 가로 1은 세로 2는 대각선
    dfs(pipe);

    cout << cnt;
    return 0;
}