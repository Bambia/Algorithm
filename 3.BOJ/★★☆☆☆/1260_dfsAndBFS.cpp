#include <iostream>
#include <queue>

using namespace std;

const int MAX = 1001;

int a[MAX][MAX];
int M,N,V;
int visited[MAX],visited2[MAX];

void dfs(int idx){
    cout <<idx<<' ';

    if(visited[idx]==1) return;

    visited[idx] =1;

    for(int i =1; i<N+1; i++){
        if(a[idx][i]==1 && visited[i]==0){
            dfs(i);
            
        }
    }
}
void bfs(int pos){
    queue<int> q;
    q.push(pos);
    visited2[pos] =1;
    while(!q.empty()){
        int cur;
        cur = q.front(); 
        q.pop();
        cout <<cur <<' ';
        for(int i=1; i<N+1; i++){
            if(visited2[i]==0 && a[cur][i]==1){
                visited2[i]=1;
                q.push(i);
            }
        }
    }
}
int main(){

    cin >> N >> M >> V;

    for(int i =0; i<M; i++){
        int x,y;
        cin >> x >> y;
        a[x][y]= 1;
        a[y][x]= 1;
    }
    

    dfs(V);
    cout <<'\n';
    bfs(V);
    //cout <<'\n';
    return 0;
}