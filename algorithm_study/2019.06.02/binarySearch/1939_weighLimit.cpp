#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

typedef long long ll;

vector <pair<int, ll> > adj_list[100001];

int N,M;
int s,e;
int visited[100001];
int pass =0;

void init(){
    for(int i=1; i<=N; i++) visited[i] =0;
}

void bfs(int pos, ll weight){
    queue <int> q;
    q.push(pos);
    visited[pos] =1;
    //cout <<"bfs start weight:"<<weight;
    while(!q.empty()){
        int cur;
        cur = q.front();
        //cout<<"cur:" << cur <<'\n';
        if(cur == e) {
            pass =1;
           //cout <<"!!!!!!!!!!!!!pass weight :" <<weight <<'\n';
        }

        q.pop();

       for(int i =0; i<adj_list[cur].size(); i++){
           //cout <<"next : " <<adj_list[cur][i].first <<"visited: "<<visited[adj_list[cur][i].first] <<'\n';
           if(!visited[adj_list[cur][i].first] &&  (weight <= adj_list[cur][i].second ) ) {
               q.push(adj_list[cur][i].first);
               //cout << "push:"<< adj_list[cur][i].first <<'\n';
               visited[adj_list[cur][i].first]=1;
           }
       }

    }

}
bool check(int start, ll weight){
    
    pass =0;
    init();
    bfs(start,weight);
    
    if (pass) return true;
    else return false;
}

ll binary_search(int start){
    ll l= 1, r = 1e9;
    while(l<r){
        ll mid = (l+r+1)/2;
        //cout <<"mid :"<< mid<<" start:"<<start <<'\n';
        if(check(start,mid)) l = mid;
        else r = mid-1;
        
    }

    return l;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    for(int i=0; i<M; i++){
        int x,y;
        ll w;
        cin >> y>> x >> w;
        adj_list[y].push_back({x,w});
        adj_list[x].push_back({y,w});
    }
    for(int i =1; i<=N; i++){
        
        sort(adj_list[i].begin(), adj_list[i].end());
    }
        // for(int i =1; i<=N; i++){
        //     cout <<"i: "<<i<<"//";
        //     for(int j=0; j<adj_list[i].size(); j++){
        //         cout <<adj_list[i][j].first <<"("<< adj_list[i][j].second <<")" <<' ';
        //     }
        //     cout <<'\n';
        // }
    cin >> s >> e ;
    
    cout << binary_search(s);

    return 0;

}