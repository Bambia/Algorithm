#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;
typedef pair <int,int> pa;

vector <int > adj[101];
int visited[101];
int N,S,E,M,found,ans;

void bfs(pair <int,int> pos){
    queue <pair<int,int> > q;
    q.push(pos);
    visited[pos.first] =1;
    while(!q.empty()){
        pair <int,int> cur;
        cur =q.front();
        q.pop();
        
        for(int i =0; i<adj[cur.first].size(); i++){
            pair<int,int> next;
            next.first = adj[cur.first][i];
            next.second = cur.second +1;

            if(!visited[next.first]){
                visited[next.first] =1;
                //cout<<" finding : " << cur.first << ' ' << next.first<<'\n';

                if(next.first == E) {
                    found = 1;
                    ans = next.second;

                    break;
                }
                q.push(next);
            
            }
        }
    }
}
int main(){
    cin >> N >> E >> S >> M;
    
    for(int i=0; i<M; i++){
        int x,y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    pair <int ,int > p;
    p.first = S;
    p.second = 0;

    bfs(p);

    if(found) cout << ans;
    else cout <<"-1";

    return 0;
}
