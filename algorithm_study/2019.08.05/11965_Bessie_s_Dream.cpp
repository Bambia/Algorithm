#include <iostream>
#include <queue>
using namespace std;

struct POS{
    int x,y;
    int pDir;
    int count,smell; // smell -> 1 orange, 0 no smell  
};

const int MX = 1001;
int N,M,ans;
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
int map[MX][MX],visited[MX][MX];
// statement 
/*
    0 can't go through
    1 go to any direction
    2 go to any direction and get orange smell
    3 if you have orange small, go through 
    4 slide to that direction until land on another tile. number 4 tiles will remove any smell.
 */

int passProcessing(POS pos){
    queue <POS> q;
    q.push(pos);
    //visited[pos.y][pos.x] =1;
    //0 exception precess

    // 1 find next dircetion 

    //2 change smell to orenge and find

    //3 check smell and decide whather should go or not.

    //4 The most difficult one ...3 memorize before dirction and color 
    
    while(!q.empty()){
        POS cur = q.front();
        q.pop();

        if(cur.y== (M-1) && cur.x == (N-1)) {
            ans = cur.count;
            cout <<"find ans \n";
            queue<POS> temp;
            q.swap(temp);
            break;
        }

        if(map[cur.y][cur.x] == 4){
            cout <<"find purple tile "<<cur.y<<' '<<cur.x<<' '<<"dir: "<<cur.pDir<<'\n';
            POS next; 
            next.x = cur.x + dx[cur.pDir];
            next.y = cur.y + dy[cur.pDir];
            next.pDir = cur.pDir;
            next.count = cur.count +1;
            next.smell = 0;
            if(next.x < 0 || next.y < 0 || next.x >= N || next.y >= M ) continue; // out of map 
            q.push(next);
        }
        else if(map[cur.y][cur.x] == 0) continue;
        else {
            for(int i =0; i<4; i++){
                POS next;
                next.x = cur.x + dx[i];
                next.y = cur.y + dy[i];
                next.pDir = i;
                next.count = cur.count +1;
                next.smell = cur.smell;
                //cout <<"finding...."<<next.y<<' '<<next.x<<'\n';
                if(next.x < 0 || next.y < 0 || next.x >= N || next.y >= M ) continue; // out of map 
                if(map[next.y][next.x] == 0) continue;
                else if(map[next.y][next.x] == 2) next.smell = 1;
                else if(map[next.y][next.x] == 3){
                    if(cur.smell != 1) {
                        cout << "smell is not orange \n";    
                        continue;
                    } 
                }
                
                if(!visited[next.y][next.x]) {
                    cout << "put other land to queue "<<next.y<<' '<<next.x<<'\n';
                   if(map[next.y][next.x]!= 4) visited[next.y][next.x] = 1;     
                   q.push(next);
                }
            }
        }
  
    }
}
int main(){
    POS start;
    cin >> N >> M;
    for(int i =0; i<M; i++){
        for(int j=0; j<N; j++){
            cin >> map[i][j];
        }
    }
    start.x = 0; start.y = 0;
    start.pDir = 0;
    start.smell = 0; start.count = 0;

    passProcessing(start);
    if(ans == 0) ans = -1;
    cout << ans <<'\n';

    return 0;
}