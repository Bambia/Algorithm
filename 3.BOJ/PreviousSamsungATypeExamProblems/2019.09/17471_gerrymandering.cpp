#include <iostream>
#include <queue>
#include <vector>
#include <cmath>
#include <cstring>

using namespace std;
const int MAX = 10+1;
const int INF = 987654321;
int N,ans = INF;
int map[MAX];
// vector <int> v[MAX];
bool connect[MAX][MAX];
bool Select[MAX];
bool visited[MAX];

bool bfs(vector <int> vt,bool T){ //연결이 됬는지 확인
    memset(visited,false,sizeof(visited));
    queue <int > q;
    q.push(vt[0]);
    visited[vt[0]] = true;
    int cnt = 1;
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        for(int i =1; i<=N; i++){
            if( connect[cur][i] && Select[i] == T && visited[i] == false){
                visited[i] = true;
                q.push(i);
                cnt++;
            }
        }

    }
    if(vt.size() == cnt ) return true; //check 한 cnt의 값이 벡터 구역설정한 것과 같으면 
    else return false;

}

bool check(){
    vector <int> a,b;
    for(int i =1; i<=N; i++) {
        if(Select[i] == true ) a.push_back(i);
        else b.push_back(i);
    }
    //cout <<"check";
    if(a.size()==0 || b.size() == 0) return false;

    if( !bfs(a,true) ) return false;
    if( !bfs(b,false) ) return false;

    return true;
}
void cal(){
    int ret =0;
    int a=0,b=0;
    for(int i =1; i<= N; i++) {
        if(Select[i] == true) a += map[i];
        else b += map[i];
    }
    //cout <<"cal\n";
    ret = abs(a-b);
    if(ans > ret) ans = ret;
    
}
void dfs(int idx,int cnt){ // 구역 나누기
    if(cnt >=1 ){
        if(check()){
            cal();
        }
        //return;
    }

    for(int i=idx; i<=N; i++){
        if(Select[i]) continue;
        Select[i] = true;
        dfs(i,cnt+1);
        Select[i] = false;
    }

}
int main(void){

    cin >> N;
    for(int i =1; i<=N; i++) cin >> map[i];

    for(int i= 1; i<=N; i++){
        int M=0;
        cin >> M;
        for(int j=0; j<M; j++){
            int temp=0;
            cin >> temp;
            connect[i][temp] = true;
            connect[temp][i] = true;
        }
    }
    dfs(1,0);

    if(ans == INF) cout <<"-1\n";
    else cout <<ans<<"\n";



    return 0;
}
    // for(int i=1; i<=N; i++) {
    //     for(int j=1; j<=N; j++){
    //         cout << connect[i][j] << ' ';
    //     }
    //     cout <<'\n';
    // }
    // for(int i=0; i<N; i++) {
    //     cout << "["<<i<<"] ";
    //     for(int j=0; j<v[i].size(); j++){
    //         cout << v[i][j] << ' ';
    //     }
    //     cout <<'\n';
    // }