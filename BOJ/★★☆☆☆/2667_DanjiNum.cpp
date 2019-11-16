#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;

struct point{
    int x;
    int y;
};
point start;
int N;
char map[26][26];
int area=0;
int visited[25][25]={0,};
int dx[4] = {0,0,-1,1};
int dy[4] = {-1,1,0,0};
vector <int> v;

void dfs(int pos){

    if(pos==N) return;
    //visited[pos]=1;

    for(int i=0; i<N; i++){
        if((!visited[pos][i])&&( map[pos][i]=='1') ){
            visited[pos][i]=1;
            area++;
            dfs(pos+1);
            //visited[i]=0;
        }
    }
}

void bfs(struct point pos){
    
    queue <point> q;
    visited[pos.y][pos.x]=1;
    
    q.push(pos);
    area=1;
    

    while(!q.empty()){
        //cout <<"start bfs\n";

        point s= q.front();
        int size =q.size();

        q.pop();
        
        for(int i=0; i<4; i++){ //상하좌우
            point n;
            n.x = dx[i]+s.x;
            n.y = dy[i]+s.y;

            if(!(n.x>=0&&n.x<N&&n.y>=0&&n.y<N)) continue; //범위지정

            if(!visited[n.y][n.x] && map[n.y][n.x]=='1'){
                visited[n.y][n.x]=1;
                area++;
                q.push(n);
            }
            

            
        }
    }
    //cout <<area<<'\n';
    v.push_back(area);
}
int main(void){
    cin>> N;
    for(int i=0; i<N; i++){
        cin >> map[i];  
    }
    /*
    cout <<"***map***\n";
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cout << map[i][j]<<' ';
        }
        cout <<'\n';
    }
    */
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(map[i][j]=='1' && visited[i][j]==0){
                start.y=i;
                start.x=j;
                bfs(start);
            }
        }
    }

    /*
    cout <<"***visited***\n";
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cout<< visited[i][j]<<' ';
        }
        cout <<'\n';
    }*/
    
    sort(v.begin(),v.end());
    cout<<v.size()<<'\n';

    for(int i=0; i<v.size(); i++){
        cout <<v[i]<<'\n';
    }
    return 0;
}