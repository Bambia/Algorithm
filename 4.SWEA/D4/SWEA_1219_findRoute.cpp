#include <iostream>
#include <list>
#include <queue>
#include <vector>

using namespace std;

int N,M,A,B,ans;
vector <int> adj[100];
void dfs_solve(int pos){
    if(pos == 99) {
        ans = 1;
        return;
    }

    for(int i=0; i<adj[pos].size(); i++){
        dfs_solve(adj[pos][i]);
    }
}

void bfs_solve(int pos){
    queue <int> q;
    q.push(pos);

    while(!q.empty()){
        int cur = q.front();
        q.pop();
        if (cur == 99) {
            ans = 1;
            break;
        }

        for(int i=0; i<adj[cur].size(); i++){
            q.push(adj[cur][i]);
        }
        
    }
}

int main(){
    int test_case =10;

    for(int tc =1; tc<=test_case; tc++){
        
        ans = 0;
        for(int i=0; i<99; i++) adj[i].clear();

        cin >> N >> M;
        for(int i=0; i<M; i++){
            cin >> A >> B;
            adj[A].push_back(B);
        }
        //dfs_solve(0);
        bfs_solve(0);
        cout << "#" <<N <<" "<< ans <<'\n';
    }
    return 0;
}