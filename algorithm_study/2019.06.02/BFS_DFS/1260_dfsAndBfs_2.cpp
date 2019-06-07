#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector <int> adj_list[1000]; 

//int adj_matrix[1000][1000];

int N,M,V;
int check[10000];
int visited[10000];

void bfs(int pos){
    queue <int> q;
    q.push(pos);
    visited[pos] =1;

    while(!q.empty()){
        int cur;
        cur = q.front();
        cout << cur <<' ';
        q.pop();

        // adjacent matrix ver.
        /*for(int i=1; i<=N; i++){
            if(adj_matrix[cur][i]==1 && visited[i]==0){
                visited[i] = 1;
                q.push(i);
            }
        }
        */
       for(int i =0; i<adj_list[cur].size(); i++){
           if(visited[adj_list[cur][i]]==0) {
               q.push(adj_list[cur][i]);
               visited[adj_list[cur][i]]=1;
           }
       }
    }
}

void dfs(int pos){
    
    if(check[pos] ==1 ) return;
    cout << pos <<' ';
    check[pos] =1;
 
    //adjacent matrix ver.
    /*for(int i=1; i<=N; i++){
        if(adj_matrix[pos][i]==1){
            //cout << "pos :"<<pos <<" i :"<<i<<'\n';
            dfs(i);
        }  
    }*/

    for(int i =0; i<adj_list[pos].size(); i++){
        dfs(adj_list[pos][i]);
    }
    
}

int main(){
    cin >> N >> M >> V;
    for(int i=0; i<M; i++) {
        int a=0,b=0;
        cin >> a >>b;
        //adj_matrix[a][b] =1;
        //adj_matrix[b][a] =1;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a); 
    }
    for(int i =1; i<=N; i++){
        
        sort(adj_list[i].begin(), adj_list[i].end());
    }
    /*
    for(int j=1; j<=N; j++){
         cout <<"j ="<<j<<" // ";
        for(int i=0; i<adj_list[j].size(); i++){
           cout << adj_list[j][i]<<' ';
        }
        cout <<'\n';
    }*/
    
    dfs(V);
    cout <<'\n';
    bfs(V);
    return 0;
}