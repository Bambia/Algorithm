#include <iostream>
#include <queue>

using namespace std;

const int MAX = 100;

int con_info[MAX][MAX];
int M,N;
int visited[MAX];
struct bacon{
    int idx,t;
};

struct bacon dist,min1;

void bfs(bacon pos){
    queue <bacon> q;
    q.push(pos);
    visited[pos.idx] =1;

    while(!q.empty()){
        bacon cur;
        cur = q.front();
        q.pop();

        for(int i=1; i<N+1; i++){
            if(con_info[cur.idx][i]==1 && visited[i]==0){
                bacon next;
                next.idx = i;
                next.t = cur.t+1;
                visited[i]=1;
                q.push(next);
                dist.t += next.t;
            }
        }

    }
    dist.idx = pos.idx;


    if(min1.t > dist.t) {
        min1.idx = dist.idx;
        min1.t = dist.t;
    }

    //cout<<"min1.t:"<<min1.t<<" dist.t :" <<dist.t <<'\n';
    //cout <<"min1.idx: "<< min1.idx<<'\n';

    for(int i=1; i<N+1; i++) visited[i]=0;
}
int main(){
    min1.t = 999999;
    cin >> N >> M;
    for(int i=0; i<M; i++){
        int x,y;
        cin >> y >> x;
        con_info[y][x] =1;
        con_info[x][y] =1;
    }

    for(int i=1; i<N+1; i++) {
        bacon a;
        a.idx = i;
        a.t =0;
        dist.t =0;
        bfs(a);
    }
    cout << min1.idx;
    //cout << res;
    return 0;
}