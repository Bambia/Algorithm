#include <iostream>
#include <vector>
using namespace std;
int N,M;

vector <int > adj[1001];
int visited[1001];
int cnt;

void dfs(int pos){
    if(visited[pos]) return ;
    visited[pos] =1;
    //cout <<pos <<' ';
    for(int i =0; i<adj[pos].size(); i++){
        dfs(adj[pos][i]);
    }
}
int main(){
    cin >> N >> M;
    for(int i =0; i<M; i++){
        int x,y;
        cin >> x >> y;

        adj[x].push_back(y);
        adj[y].push_back(x);  
    }

    for(int i =1; i<=N; i++){
        if(!visited[i]){
            dfs(i);
            //cout <<'\n';
            cnt ++;
        }
    }

    cout << cnt<<'\n';
    return 0;
}