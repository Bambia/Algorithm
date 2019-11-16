/*
아기 상어
시간 제한	메모리 제한	제출	정답	맞은 사람	정답 비율
2 초	512 MB	6428	2500	1531	36.918%
문제
N×N 크기의 공간에 물고기 M마리와 아기 상어 1마리가 있다. 공간은 1×1 크기의 정사각형 칸으로 나누어져 있다. 한 칸에는 물고기가 최대 1마리 존재한다.

아기 상어와 물고기는 모두 크기를 가지고 있고, 이 크기는 자연수이다. 가장 처음에 아기 상어의 크기는 2이고, 아기 상어는 1초에 상하좌우로 인접한 한 칸씩 이동한다.

아기 상어는 자신의 크기보다 큰 물고기가 있는 칸은 지나갈 수 없고, 나머지 칸은 모두 지나갈 수 있다. 아기 상어는 자신의 크기보다 작은 물고기만 먹을 수 있다. 따라서, 크기가 같은 물고기는 먹을 수 없지만, 그 물고기가 있는 칸은 지나갈 수 있다.

아기 상어가 어디로 이동할지 결정하는 방법은 아래와 같다.

더 이상 먹을 수 있는 물고기가 공간에 없다면 아기 상어는 엄마 상어에게 도움을 요청한다.
먹을 수 있는 물고기가 1마리라면, 그 물고기를 먹으러 간다.
먹을 수 있는 물고기가 1마리보다 많다면, 거리가 가장 가까운 물고기를 먹으러 간다.
거리는 아기 상어가 있는 칸에서 물고기가 있는 칸으로 이동할 때, 지나야하는 칸의 개수의 최소값이다.
거리가 가까운 물고기가 많다면, 가장 위에 있는 물고기, 그러한 물고기가 여러마리라면, 가장 왼쪽에 있는 물고기를 먹는다.
아기 상어의 이동은 1초 걸리고, 물고기를 먹는데 걸리는 시간은 없다고 가정한다. 즉, 아기 상어가 먹을 수 있는 물고기가 있는 칸으로 이동했다면, 이동과 동시에 물고기를 먹는다. 물고기를 먹으면, 그 칸은 빈 칸이 된다.

아기 상어는 자신의 크기와 같은 수의 물고기를 먹을 때 마다 크기가 1 증가한다. 예를 들어, 크기가 2인 아기 상어는 물고기를 2마리 먹으면 크기가 3이 된다.

공간의 상태가 주어졌을 때, 아기 상어가 몇 초 동안 엄마 상어에게 도움을 요청하지 않고 물고기를 잡아먹을 수 있는지 구하는 프로그램을 작성하시오.

입력
첫째 줄에 공간의 크기 N(2 ≤ N ≤ 20)이 주어진다.

둘째 줄부터 N개의 줄에 공간의 상태가 주어진다. 공간의 상태는 0, 1, 2, 3, 4, 5, 6, 9로 이루어져 있고, 아래와 같은 의미를 가진다.

0: 빈 칸
1, 2, 3, 4, 5, 6: 칸에 있는 물고기의 크기
9: 아기 상어의 위치
아기 상어는 공간에 한 마리 있다.

출력
첫째 줄에 아기 상어가 엄마 상어에게 도움을 요청하지 않고 물고기를 잡아먹을 수 있는 시간을 출력한다.

*/

#include <iostream>
#include <vector>
#include <queue>


struct point{
    int x,y;
    int time;
};

point babyShark;
using namespace std;

const int MAX = 20;

int N;
int map[MAX][MAX];

int sizeOfShark=0;
int eatCnt=0;
int isEatEnabled;


int dx[4]={0,-1,0,1}; //위 왼 아래 오른
int dy[4]={-1,-0,1,0}; //위 왼 아래 오른

point pFish; // 우선순위의 물고기를 찾아야 하기 떄문에
        

bool in_range(struct point pos){
    if(pos.x >=0 && pos.x <N && pos.y>=0 && pos.y <N) return true;
    else return false;
}

void bfs(struct point pos){ //입력값으로 상어의 첫 위치를 넣는다
        //visited[pos.y][pos.x] =1; //상어의 위치 방문 표시
        int visited[20][20]={0,};
        queue <point> q;
        q.push(pos); //시작지점
        
        pFish.y = 20; // 위에있는 놈이 우선순위가 높기 때문에
        pFish.time =-1; // 처음에는 무조건 pFish에 들어가야 하기 떄문에 조건을 맞추기 위해서 -1로 한다 -1보다는 무조건 큰 값이 걸리기 때문

        while(!q.empty()) { //q가 비어있지 않으면 계속 탐색
            
            point cur;
            cur = q.front();
            q.pop();

            if(pFish.time!=-1 && pFish.time < cur.time ) break; // 이미 들어가있는 물고기보다 더 오래걸리면 검사할 필요가 없음

            if(map[cur.y][cur.x]<sizeOfShark && map[cur.y][cur.x]!=0){  //먹을 수 있는 물고기가 나타나면
                isEatEnabled =1;  // 물고기를 찾았기 때문에 다음번 탐색 가능

                    if( pFish.y>cur.y || ( (pFish.y ==cur.y) && pFish.x > cur.x) ){
                        pFish = cur; //먹을 수 있는 물고기가 있다면 우선순위 물고기 교체
                        //cout <<"find fish\n";
                    }
                
            }
                        
            for(int i=0; i<4; i++) { // 4방향 탐색
                point next;
                next.x = cur.x + dx[i];
                next.y = cur.y + dy[i];
                next.time = cur.time +1; // 4방향 탐색 후 값 증가   

                if(!in_range(next)) continue;
                if(visited[next.y][next.x]==0 && map[next.y][next.x]<=sizeOfShark ){ //갈 수 있는 길인지 
                    visited[next.y][next.x]=1;
                    q.push(next);
                }
            }
                
                
        }
        //visited[pos.y][pos.x] =0; // 방문 해제
}
int main(void){

    cin >> N;

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin >> map[i][j];
            if(map[i][j]==9){
                babyShark.x = j;
                babyShark.y = i;
                sizeOfShark =2; 
                babyShark.time =0;
                map[i][j] = 0; //상어의 위치에 빈칸 저장
            }
        }
    }

    //상어가 먹은 물고기가 있는지 
    isEatEnable=1;
    //int time=0;

    while(isEatEnabled){ // 만약 더이상 먹을 물고기가 없으면 빠져나간다.
        isEatEnabled=0; 
        bfs(babyShark); //물고기 먹고 지도 업데이트 및 초기화

        if(isEatEnabled){
            eatCnt++;            
            if(eatCnt ==sizeOfShark){
                sizeOfShark++;
                eatCnt= 0;
            }

            map[pFish.y][pFish.x] =0; //먹었기 때문에 0으로 초기화
            babyShark.x = pFish.x; 
            babyShark.y = pFish.y;
            babyShark.time = pFish.time;
            //time += pFish.time;

        }
    }

    cout <<babyShark.time;

    return 0;
}

/*
예제 입력 1 
3
0 0 0
0 0 0
0 9 0
예제 출력 1 
0
예제 입력 2 
3
0 0 1
0 0 0
0 9 0
예제 출력 2 
3
예제 입력 3 
4
4 3 2 1
0 0 0 0
0 0 9 0
1 2 3 4
예제 출력 3 
14
예제 입력 4 
6
5 4 3 2 3 4
4 3 2 3 4 5
3 2 9 5 6 6
2 1 2 3 4 5
3 2 1 6 5 4
6 6 6 6 6 6
예제 출력 4 
60
예제 입력 5 
6
6 0 6 0 6 1
0 0 0 0 0 2
2 3 4 5 6 6
0 0 0 0 0 2
0 2 0 0 0 0
3 9 3 0 0 1
예제 출력 5 
48
예제 입력 6 
6
1 1 1 1 1 1
2 2 6 2 2 3
2 2 5 2 2 3
2 2 2 4 6 3
0 0 0 0 0 6
0 0 0 0 0 9
예제 출력 6 
39
출처
문제를 만든 사람: baekjoon
메모
*/