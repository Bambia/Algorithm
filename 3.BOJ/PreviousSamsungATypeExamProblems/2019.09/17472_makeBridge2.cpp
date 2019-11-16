#include <iostream>
#include <queue>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

struct POS{
    int x,y;
};

int dx[4] = {0,-1,0,1};
int dy[4] = {1,0,-1,0};

int M,N;
int orgMap[11][11],numMap[11][11];
int numCheck[11][11];
int numLandCnt = 0,numLand = 0;
int DistBtwLand[12][12];
int p[11],ans;

struct Edge{
    int u,v,w;
    Edge(){}
    Edge(int u, int v,int w): u(u),v(v),w(w){}
};

vector <Edge> v;

int find(int x){
    if(p[x] == -1) return x;
    else return p[x] = find(p[x]);
}

bool marge(int u , int v){
    v = find(v);
    u = find(u);

    if(v == u) return false;
    p[u] = v;
    return true;
}
bool inRange(POS pos)
{
    if( pos.y >= N || pos.x >= M || pos.x < 0 || pos.y < 0 ) return false;
    return true;
}
void findLandNUm(POS pos)
{   
    numLandCnt++;
    numCheck[pos.y][pos.x] = 1;
    numMap[pos.y][pos.x] = numLandCnt;
    queue <POS> q;

    q.push(pos);
    
    while(!q.empty()){
        POS cur = q.front();
        q.pop();

        for(int i=0; i<4; i++){
            
            POS next;
            next.x = cur.x + dx[i];
            next.y = cur.y + dy[i];

            if(!inRange(next)) continue;

            if(orgMap[next.y][next.x] == 1 && !numCheck[next.y][next.x] )
            {
                numCheck[next.y][next.x] = 1;
                numMap[next.y][next.x] = numLandCnt;
                q.push(next); 
            }

        }        

    }
}
void connectLand(POS pos)
{
    int num = numMap[pos.y][pos.x];
    // cout <<"num:"<<num<<'\n';
    numCheck[pos.y][pos.x] = 1;
    queue <POS> q; 
    q.push(pos);

    while(!q.empty())
    {
        POS cur = q.front();
        q.pop();
        
        for(int j=0; j<4; j++)  //4방향 직선에 다른 섬이 있는지 탐색
        {
            int dist = 0;
            POS move; 
                
            move.x = cur.x + dx[j];
            move.y = cur.y + dy[j];
            dist = dist +1;

            if(numMap[move.y][move.x] == num) continue;

            while(1) 
            {  
                move.x += dx[j];
                move.y += dy[j];
                dist = dist + 1;

                if(!inRange(move)) break; 
                

                if(numMap[move.y][move.x] != 0 ) {
                    dist--;
                    if(numMap[move.y][move.x] == num) break; // 주변에 내 블록이 있으면 탐색 종료
                    
                    if(dist < 2) break;
                    if(DistBtwLand[num][numMap[move.y][move.x]] > dist ) DistBtwLand[num][numMap[move.y][move.x]] = dist;         
                    break;
                }
            }
        }

        for(int i=0; i<4; i++)
        {
            POS next;
            
            next.x = cur.x + dx[i];
            next.y = cur.y + dy[i];

            if( !inRange(next) ) continue;

            if(numMap[next.y][next.x] == num && !numCheck[next.y][next.x] )
            {
                numCheck[next.y][next.x] = 1;
                q.push(next); 
            }
        }
    }
}

int main(void)
{
    cin >> N >> M;

    for(int i=0; i<N; i++)
    {
        for(int j=0; j<M; j++)
        {
                cin >> orgMap[i][j];
                
        }
    }

    for(int i=0; i<N; i++)
    {
        for(int j=0; j<M; j++)
        {
                if(orgMap[i][j] == 1 && !numCheck[i][j]) findLandNUm({j,i});
        }
    }    
    
    numLand = numLandCnt;
    memset(numCheck,0,sizeof(numCheck));
    memset(p,-1,sizeof(p));

    for(int i=1; i<=numLand; i++){
        for(int j=1; j<=numLand; j++){
            DistBtwLand[i][j] = 999; // 모든 섬간의 거리 초기화
        }
    }
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<M; j++)
        {
            if(numMap[i][j] != 0 && !numCheck[i][j]) connectLand({j,i});
        }
    }    
    
    // cout <<"minimun distance\n";

    // for(int i=1; i<=numLand; i++){
    //     for(int j=1; j<=numLand; j++){
    //         cout << DistBtwLand[i][j]<<' '; 
    //     }
    //     cout <<'\n';
    // }    

    for(int i=1; i<=numLand; i++){
        for(int j=i+1; j<=numLand; j++){
            v.push_back(Edge(i,j,DistBtwLand[i][j]));
        }
    }
    sort(v.begin(),v.end(),[](Edge l, Edge r){
        return l.w < r.w;
    });
    // cout <<"sort finished\n";
    // for(int i =0; i<v.size(); i++) cout <<v[i].u <<' '<< v[i].v<<' '<<v[i].w<<'\n';

    for(int i=0; i<(numLand-1); i++){
        if(marge(v[i].u,v[i].v)) {
            if(v[i].w == 999) {
                ans = -1;
                break;
            } 
            ans += v[i].w;
        }
    }

    // cout <<"LandNum: "<<numLand << " \n";

    // for(int i=0; i<N; i++){
    //     for(int j=0; j<M; j++){
    //             cout << numMap[i][j]<<' ';
    //     }
    //     cout <<'\n';
    // }

    cout << ans <<'\n';





    return 0;
}