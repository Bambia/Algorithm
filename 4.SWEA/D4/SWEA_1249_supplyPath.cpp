#include <iostream>
#include <queue>
using namespace std;

struct P{
    int x,y,time;

};

bool operator < (P l,P r){
    return l.time > r.time;
}
int dx[4] = {1,0,-1,0};
int dy[4] = {0,-1,0,1};

int N;
int map[100][100],visited[100][100];

void init(int N){
    for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                visited[i][j] = 0;
                map[i][j] =0;
            }
    }
}
int solve(P start){
    priority_queue <P> pq;
    int ans =1e9;
    start.time = 0;
    visited[start.y][start.x] = 1;

    pq.push({0,0,0});
    
    while(!pq.empty()){
        P cur =pq.top();
        if( cur.x == (N-1) && cur.y ==(N-1))  {
            break;
        }
        pq.pop();
        for(int i=0; i<4; i++){
            P next;
            next.x = cur.x + dx[i];
            next.y = cur.y + dy[i];
            next.time = cur.time + map[next.y][next.x];

            if(next.x >= N || next.y >= N || next.x < 0 || next.y < 0) continue;
            
            if(!visited[next.y][next.x]) {
                visited[next.y][next.x] = 1;
                map[next.y][next.x] =0; 
                pq.push(next); 
            }
        }   
    }
    ans = pq.top().time;
    return ans;
}
int main(){


    int test_case;
    cin >> test_case;

    for(int tc=1; tc <= test_case; tc++){
        cin >> N;
        
        for(int i=0; i<N; i++){ 
            for(int j=0; j<N; j++){
                scanf("%1d",&map[i][j]);
            }
        }
        cout << "#"<<tc<<' '<<solve({0,0,0}) <<'\n';

        init(N);
    }
    return 0;
} 