//#include <iostream>
#include <queue>
#include <stdio.h>

using namespace std;

struct point {
    int x,y;
    int dir;
};

int dx[4] ={0,1,0,-1};
int dy[4] ={-1,0,1,0};

int map[51][51];

int ret,N,M;

int main(void){
    point robot;

    scanf("%d %d",&N,&M);
    scanf("%d %d %d",&robot.y,&robot.x,&robot.dir);

    //cin >> N >> M;
    //cin >> robot.y >> robot.x>> robot.dir;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            scanf("%d",&map[i][j]);
        }
    }
    queue <point> q;
    q.push(robot);
    
    while(!q.empty()){
        point cur;    
        cur = q.front();
        q.pop();

            if(map[cur.y][cur.x]==0){
                map[cur.y][cur.x]=2;
                ret++;
            }

            for(int i=0; i<4; i++){
                point next;
                //next.dir = (cur.dir+3)%4; 
                next.dir = (cur.dir+3 -i)%4;
                next.x = cur.x + dx[next.dir];
                next.y = cur.y + dy[next.dir];

                if( (next.x<0 || next.x>=M || next.y<0 || next.y>=N) || map[next.y][next.x] !=0  ) continue;

                q.push(next);
                break; //왼쪽으로 돌다가 원하는 방향 찾으면 더이상 탐색하면 안되므로 q에는 항상 하나의 좌표만 들어가야 한다. 
            }

            if(q.empty()){ //4 방향 탐색해도 찾지 못하면
                point next;
                next.dir = cur.dir; //방향은 그대로
                next.x = cur.x+ dx[(cur.dir+2)%4]; //뒤로 후진 
                next.y = cur.y+ dy[(cur.dir+2)%4];
                

                if(next.x<0 || next.x>=M || next.y<0 || next.y>=N 
                || map[next.y][next.x] ==1  ) continue; //벽이면
                
                q.push(next);
            }
        
    }
    printf("%d",ret);
    return 0;
}