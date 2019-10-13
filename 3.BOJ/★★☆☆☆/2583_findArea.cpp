/*
영역 구하기
시간 제한	메모리 제한	제출	정답	맞은 사람	정답 비율
1 초	128 MB	11382	6083	4827	54.809%
문제
눈금의 간격이 1인 M×N(M,N≤100)크기의 모눈종이가 있다. 이 모눈종이 위에 눈금에 맞추어 K개의 직사각형을 그릴 때, 이들 K개의 직사각형의 내부를 제외한 나머지 부분이 몇 개의 분리된 영역으로 나누어진다.

예를 들어 M=5, N=7 인 모눈종이 위에 <그림 1>과 같이 직사각형 3개를 그렸다면, 그 나머지 영역은 <그림 2>와 같이 3개의 분리된 영역으로 나누어지게 된다.



<그림 2>와 같이 분리된 세 영역의 넓이는 각각 1, 7, 13이 된다.

M, N과 K 그리고 K개의 직사각형의 좌표가 주어질 때, K개의 직사각형 내부를 제외한 나머지 부분이 몇 개의 분리된 영역으로 나누어지는지, 그리고 분리된 각 영역의 넓이가 얼마인지를 구하여 이를 출력하는 프로그램을 작성하시오.

입력
첫째 줄에 M과 N, 그리고 K가 빈칸을 사이에 두고 차례로 주어진다. M, N, K는 모두 100 이하의 자연수이다. 둘째 줄부터 K개의 줄에는 한 줄에 하나씩 직사각형의 왼쪽 아래 꼭짓점의 x, y좌표값과 오른쪽 위 꼭짓점의 x, y좌표값이 빈칸을 사이에 두고 차례로 주어진다. 모눈종이의 왼쪽 아래 꼭짓점의 좌표는 (0,0)이고, 오른쪽 위 꼭짓점의 좌표는(N,M)이다. 입력되는 K개의 직사각형들이 모눈종이 전체를 채우는 경우는 없다.

출력
첫째 줄에 분리되어 나누어지는 영역의 개수를 출력한다. 둘째 줄에는 각 영역의 넓이를 오름차순으로 정렬하여 빈칸을 사이에 두고 출력한다.
*/
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;
struct point{
    int x;
    int y;
    int area;
};
const int MAX = 100;

point A;
point B;
point S;
int map[MAX][MAX];
int M=0,N=0,K=0;
int visited[MAX][MAX]={0,};
int dx[4]={0,0,-1,1};
int dy[4]={-1,1,0,0};
vector <int> v;

bool in_range(struct point a){
    if(a.x>=0 && a.x<N && a.y>=0 && a.y<M){
        return true;
    }
    else return false;
}
void bfs(struct point pos){
    
    queue <point> q;
    
    visited[pos.y][pos.x]=1;
    pos.area=1;
    q.push(pos);

    while(!q.empty()){
        point Start;
        Start=q.front();
        q.pop();
        for(int i=0; i<4; i++){
            point N;
            N.x=Start.x+dx[i];
            N.y=Start.y+dy[i];
            if(!in_range(N)) continue; //범위 안에 안들면 걸러라
            
            
            if(map[N.y][N.x]==0 && visited[N.y][N.x]==0){ // 맵이 연결되어 있고 방문하지 않았으면
                pos.area++;
                //cout <<"X="<<N.x<<" Y="<<N.y <<" Area="<<pos.area<<'\n';
                visited[N.y][N.x]=1;
                q.push(N);
            }


        }
    }
    v.push_back(pos.area);

   
}
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> M >> N >> K; 

    for(int i=0; i<K; i++){
        cin >>A.x >>A.y >> B.x >> B.y ;

        for(int j=A.y; j<B.y; j++){ 
            for(int l=A.x; l<B.x; l++){
                map[j][l]=1;
            }
        }
    }

    /*
    cout <<"***map***\n";
    for(int j=0; j<(M); j++){ //
        for(int l=0; l<(N); l++){
                cout << map[j][l]<<' ';
            }
            cout <<'\n';
    }
    */
    for(int i=0; i<M; i++){
        for(int j=0; j<N; j++){
            if(map[i][j]==0 && visited[i][j]==0){
                    S.x=j;
                    S.y=i;
                    S.area=0;
                    //cout <<"Sx= "<<S.x<<" Sy= "<<S.y<<'\n';
                    bfs(S);
                /*  
                cout <<"***visited***\n";
                for(int j=0; j<(M); j++){ //
                    for(int l=0; l<(N); l++){
                        cout << visited[j][l]<<' ';
                    
                    }
                cout <<'\n';
                }*/

            } // map ==0이고 방문하지 않았으면 거기서부터 bfs 탐색
        }
    }
    sort(v.begin(),v.end());
    cout << v.size()<<'\n';
    for(auto i:v) cout <<i<<' ';

    /*
    cout <<"***map***\n";
    for(int j=0; j<(M); j++){ //
        for(int l=0; l<(N); l++){
                cout << map[j][l]<<' ';
            }
            cout <<'\n';
    }
    cout <<"***visited***\n";
    for(int j=0; j<(M); j++){ //
        for(int l=0; l<(N); l++){
                cout << visited[j][l]<<' ';
            }
            cout <<'\n';
    }
    */

    return 0;
}


/*
예제 입력 1 
5 7 3
0 2 4 4
1 1 2 5
4 0 6 2
예제 출력 1 
3
1 7 13
출처
Olympiad > 한국정보올림피아드 > 한국정보올림피아드시․도지역본선 > 지역본선 2006 > 고등부 2번

문제의 오타를 찾은 사람: alphago92
잘못된 데이터를 찾은 사람: kookmin20103324
알고리즘 분류
BFS
DFS
메모

*/