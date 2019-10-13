/*

테트로미노
시간 제한	메모리 제한	제출	정답	맞은 사람	정답 비율
2 초	512 MB	15660	5388	3470	32.406%
문제
폴리오미노란 크기가 1×1인 정사각형을 여러 개 이어서 붙인 도형이며, 다음과 같은 조건을 만족해야 한다.

정사각형은 서로 겹치면 안된다.
도형은 모두 연결되어 있어야 한다.
정사각형의 꼭짓점끼리 연결되어 있어야 한다. 즉, 변과 꼭짓점이 맞닿아있으면 안된다.
정사각형 4개를 이어 붙인 폴리오미노는 테트로미노라고 하며, 다음과 같은 5가지가 있다.



아름이는 크기가 N×M인 종이 위에 테트로미노 하나를 놓으려고 한다. 종이는 1×1 크기의 칸으로 나누어져 있으며, 각각의 칸에는 정수가 하나 쓰여 있다.

테트로미노 하나를 적절히 놓아서 테트로미노가 놓인 칸에 쓰여 있는 수들의 합을 최대로 하는 프로그램을 작성하시오.

테트로미노는 반드시 한 정사각형이 정확히 하나의 칸을 포함하도록 놓아야 하며, 회전이나 대칭을 시켜도 된다.

입력
첫째 줄에 종이의 세로 크기 N과 가로 크기 M이 주어진다. (4 ≤ N, M ≤ 500)

둘째 줄부터 N개의 줄에 종이에 쓰여 있는 수가 주어진다. i번째 줄의 j번째 수는 위에서부터 i번째 칸, 왼쪽에서부터 j번째 칸에 쓰여 있는 수이다. 입력으로 주어지는 수는 1,000을 넘지 않는 자연수이다.

출력
첫째 줄에 테트로미노가 놓인 칸에 쓰인 수들의 합의 최댓값을 출력한다.
*/

#include <iostream>
#include <vector>
using namespace std;

struct point{
    int x;
    int y;
};

const int MAX = 500;
vector <point> v;
int M,N;
int map[MAX][MAX];
int dx[4] = {-1,0,1,0}; //순서  죄상우하 (시계방향)
int dy[4] = {0,-1,0,1}; //순서  죄상우하 (시계방향)
int visited[MAX][MAX];
point start;
int sum=0;
int ans=0;
bool in_range(struct point pos){
    if(pos.x >=0 && pos.x<M && pos.y >=0 && pos.y<N) return true;
    else return false; 
}
void dfs(struct point pos,int idx,int sum){

    if(idx == 4){
         //cout <<"y:"<< v[i].y <<" x:"<< v[i].x<<'\n';
         //cout <<'\n';
        //cout <<"sum: "<<sum<<'\n';
        if(sum>ans) ans = sum;
        return ;
    }

    for(int i=0; i<4; i++){
        point temp;
        temp.x = pos.x+dx[i];
        temp.y = pos.y+dy[i];
        if(!in_range(temp)) continue; //범위를 벗어 난다면
        //cout <<"s\n";
        if(visited[temp.y][temp.x]==0){
            //cout <<"v\n";
            visited[temp.y][temp.x]=1;
            //cout <<"y:"<< temp.y<<" x:"<< temp.x<<'\n';
            dfs(temp,idx+1,sum+map[temp.y][temp.x]);
            visited[temp.y][temp.x]=0;
        } 


    }
}

void calFuckFigure(struct point pos){
        //현재위치에서 상하좌우 중에 3개만 골라서 탐색

    for(int i=0; i<4; i++){  
        int total = map[pos.y][pos.x]; //자기자신
        int flag=0;

        for(int j=0; j<3; j++){ //나머지 세방향
            point fuck;
            fuck.x = pos.x +dx[(i+j)%4];
            fuck.y = pos.y +dy[(i+j)%4];
            
            if(in_range(fuck)){
                total+=map[fuck.y][fuck.x];
            }
            else{ //범위를 벗어난 경우에는 계산할 필요가 없음
                flag=1;
                break;
            }
        }

        if(!flag) {
            if(ans<total) ans = total;
        }

    }

}
int main(void){

    scanf("%d %d",&N,&M);
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            scanf("%d",&map[i][j]);

        }
    } 

     for(int i=0; i<N; i++){  
         for(int j=0; j<M; j++){
             start.x = j;
             start.y = i;
             visited[i][j]=1;
             dfs(start,1,map[start.y][start.x]);
             calFuckFigure(start);
             visited[i][j]=0; // 방문했던 곳은 방문 체크
         }
     }

     cout <<ans;
     return 0;

}

/*
예제 입력 1 
5 5
1 2 3 4 5
5 4 3 2 1
2 3 4 5 6
6 5 4 3 2
1 2 1 2 1
예제 출력 1 
19
예제 입력 2 
4 5
1 2 3 4 5
1 2 3 4 5
1 2 3 4 5
1 2 3 4 5
예제 출력 2 
20
예제 입력 3 
4 10
1 2 1 2 1 2 1 2 1 2
2 1 2 1 2 1 2 1 2 1
1 2 1 2 1 2 1 2 1 2
2 1 2 1 2 1 2 1 2 1
예제 출력 3 
7
출처
문제를 만든 사람: baekjoon
데이터를 추가한 사람: stack vjerksen
알고리즘 분류
브루트 포스
메모

*/