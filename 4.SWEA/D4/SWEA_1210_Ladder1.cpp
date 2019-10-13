#include <iostream>
#include <queue>
using namespace std;

struct POS{
    int x,y;
};
int dx[3] = {1,-1,0}; 
int dy[3] = {0,0,-1}; //우 좌 상 
int N,dst;
int map[100][100],visited[100][100];
void init(){
    for(int i=0; i<100; i++){
            for(int j=0; j<100; j++){
                visited[i][j] = 0;
                map[i][j] =0;
            }
    }
}
int solve(int start){
    int ans= 0;
    queue <POS> q;
    q.push({start,99});
    
    while(!q.empty()){
        POS cur =q.front();
        q.pop();
        if(cur.y == 0) ans = cur.x;

        for(int i=0; i<3; i++){
            POS next;
            next.x = cur.x + dx[i];
            next.y = cur.y + dy[i];

            if(next.x >= 100 || next.x < 0 || next.y < 0) continue;
            
            if(map[next.y][next.x] == 1 && !visited[next.y][next.x]) {
                visited[next.y][next.x] =1;
                q.push(next);  
                if(i == 0 || i == 1) break; // 위로 올라갈 필요 없음
            }
        }
    }
    return ans;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int test_case = 10;

    for(int tc=0; tc < test_case; tc++){
        init();
        cin >> N;
        for(int i=0; i<100; i++){
            for(int j=0; j<100; j++){
                cin >> map[i][j];
                if(map[i][j] == 2) dst = j;   
            }
        }
        cout << "#"<<N<<' '<<solve(dst) <<'\n';
    }
    return 0; 
}