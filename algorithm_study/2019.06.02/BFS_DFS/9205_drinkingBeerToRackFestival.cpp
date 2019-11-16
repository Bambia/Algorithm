#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <math.h>
using namespace std;

int tc,n,yes;
int visited[103];
vector <int> adj[103];
vector <pair <int,int> >  map;
void init(){
    for(int i =0; i<103; i++){
        visited[i]= 0;
        adj[i].clear();
    }
    map.clear();
    yes =0;
}
void dfs(int pos){
    if(visited[pos]) return;
    visited[pos] =1;
    if(pos == n+1 ) {
        yes =1;
        return ;
    }
    for(int i=0; i<adj[pos].size(); i++){
            dfs(adj[pos][i]);        
    }
}
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >>tc;
    while(tc--){
        cin >>n;
        for(int i=0; i<n+2; i++){
            pair <int ,int> x;
            cin >> x.first >> x.second;
            map.push_back(x);

            // save as an  vector
        }
        for(int i=0; i<map.size(); i++){ // connect component as a graph 
            for(int j=i+1; j<map.size(); j++){
                if( 1000 >= (abs( map[i].first - map[j].first ) + abs( map[i].second - map[j].second )) ){
                    //cout << "i:" << i << " j:"<<j<<'\n';
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        
        /*for(int i=0; i<n+2; i++){
            //cout <<"i ="<<i<<" // ";
            
            for(int j=0; j< adj[i].size(); j++){
               cout << adj[i][j] <<' ';        
            }
            cout <<'\n';
        }*/
        dfs(0);
        if(yes) cout <<"happy\n";
        else cout <<"sad\n";
        init();
    }
    return 0;
}