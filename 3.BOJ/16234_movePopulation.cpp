#include <iostream>
#include <queue>
#include <vector>

using namespace std;
struct POINT{
    int x,y;

};

int dx[4] = {0,1,0,-1}; //상우하좌 시계방향
int dy[4] = {-1,0,1,0};

int N,L,R;
int map[51][51];
int visited[51][51];
int sum;
vector <POINT> v;
int Move,cnt;

void bfs(struct POINT pos){
    queue <POINT> q;
    q.push(pos);
    visited[pos.y][pos.x]=1;
    sum = map[pos.y][pos.x];
    v.push_back(pos);

    while(!q.empty()){
        POINT cur;
        cur = q.front();
        q.pop();

        for(int i=0; i<4; i++){ //상하좌우 탐색
            POINT next; 
            next.x = cur.x+dx[i];
            next.y = cur.y+dy[i];

            if(next.x < 0 || next.x >= N || next.y < 0 || next.y >=N ) continue;//범위 초과

            if( visited[next.y][next.x]==0 && (abs(map[cur.y][cur.x]- map[next.y][next.x]) >= L) && (abs(map[cur.y][cur.x]- map[next.y][next.x]) <= R) ){
                //cout <<"cur_x :"<<cur.x <<" cur_y :"<<cur.y <<'\n'<< " next_x :"<<next.x << " next_y:" <<next.y<<'\n';
                //cout <<"store: "<< map[next.y][next.x]<<'\n';
                sum += map[next.y][next.x]; //인구 누적 저장
                //cout <<"&sum: "<<sum<<'\n';
                visited[next.y][next.x]=1;
                v.push_back(next); // 나중에 값 바꿔야 되므로 좌표 저장
                q.push(next); //다음 탐색 으로 이동
                //cout <<"move population\n";
                //for(int a = 0; a <v.size(); a++) cout << v[a];
                Move =1; //인구이동 여부 반영
            }
                
            
 
        }
    }
    //탐색이 다 종료 되면 sum 값으로 벡터의 크기만 큼 나눠서 저장

    if(v.size()>1){ //저장되어있는 값이 없으면 인구이동 할 곳이 없다는 뜻
        int p,size;
        size = v.size();
        p = sum / size;
        //cout <<"p: "<<p<< "size: "<<size <<"sum:"<<sum<<'\n';
        for(int i=0; i<size; i++) map[v[i].y][v[i].x] = p; //인구 이동 결과 반영
        sum=0;
        //cout <<"change population\n";
        //cnt++; //인구이동 횟수 저장
        
    }
    v.clear();
    

}

int main(void){
    cin >> N >> L >> R;

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin >> map[i][j];
        }
    }
    Move =1;
    while(Move){
        Move =0;
        //cout<< "move search\n";
        for(int i=0; i<N; i++){        //전체 맵을 탐색 할때까지 포문 동작
            for(int j=0; j<N; j++){
                if(visited[i][j]==0) {
                    POINT start;
                    start.x = j;
                    start.y = i;
                    //cout <<"bsf start\n";
                    bfs(start);
                    sum = 0;
                }
            }
        }
        for(int i=0; i<N; i++){       
            for(int j=0; j<N; j++){
                visited[i][j]=0;
            }
        }
        /*
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                cout << map[i][j]<<' ';
            }
            cout <<'\n';
        }*/
        cnt++;
    }

    cout <<cnt-1;

    return 0;
}