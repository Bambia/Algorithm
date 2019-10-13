#include <iostream>
#include <queue>

using namespace std;
struct POS{
    int x,y;
    int dir;
};

char map[21][21];
int reg;
int R,C;
int visited[21][21][4][16];
enum dir{
    Right = 0,
    Down,
    Left,
    Up
};
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
void init(){
    reg = 0;
    for(int i=0; i<=R; i++){
        for(int j=0; j<=C; j++){
            for(int k=0; k<=4; k++){
                for(int l=0; l<=15; l++){
                    visited[i][j][k][l] =0;
                }
            }
        }
    }

    for(int i =0; i<R; i++){
        for(int j =0; j<C; j++){
            map[i][j] = 0;
        }
    }
    C =0; R=0;
}
bool solve(POS pos){
    queue <POS> q;
    q.push(pos);
    visited[pos.y][pos.x][pos.dir][reg] =1;
    
    while(!q.empty()){
        POS next,cur = q.front();
        q.pop();
        next.dir = cur.dir;

        if(map[cur.y][cur.x] == '<') next.dir = Left;
        else if(map[cur.y][cur.x] == '>') next.dir = Right;
        else if(map[cur.y][cur.x] == '^') next.dir = Up;
        else if(map[cur.y][cur.x] == 'v') next.dir = Down;
        else if(map[cur.y][cur.x] == '_') {
            if(reg == 0) next.dir = Right; 
            else next.dir = Left;
        }
        else if(map[cur.y][cur.x] == '|'){
            if(reg == 0) next.dir = Down; 
            else next.dir = Up;            
        }
        else if(map[cur.y][cur.x] == '?'){
            for(int i=0; i<4; i++){
                next.x = cur.x + dx[i];
                next.y = cur.y + dy[i];
                next.dir = i;

                if(next.x < 0) next.x = C-1;
                else if(next.y <0 ) next.y = R-1; 
                else if (next.x >= C) next.x = 0;
                else if(next.y >= R) next.y = 0;
                
                //cout <<"next: "<<next.y <<' '<<next.x <<" dir: "<<next.dir<<'\n';
                if(visited[next.y][next.x][next.dir][reg] == 1) continue;
                visited[next.y][next.x][next.dir][reg] =1;
    
                q.push(next);
            }

            continue;
        }
        else if(map[cur.y][cur.x] == '@') {
            //cout <<"find\n";
            return true;
        }
        else if(map[cur.y][cur.x] == '+'){
            if(reg == 15) reg = 0;
            else reg++;
        }
        else if(map[cur.y][cur.x] == '-'){
            if(reg == 0) reg = 15;
            else reg--;
        }
        else if(map[cur.y][cur.x] >= '0' && map[cur.y][cur.x] <= '9') reg = map[cur.y][cur.x]-'0';

        next.x = cur.x + dx[next.dir];
        next.y = cur.y + dy[next.dir];

        if(next.x < 0) next.x = C-1;
        else if(next.y <0 ) next.y = R-1; 
        else if (next.x >= C) next.x = 0;
        else if(next.y >= R) next.y = 0;

        //cout <<"next: "<<next.y <<' '<<next.x <<" dir: "<<next.dir <<'\n';
        //cout <<"visited: "<< visited[next.y][next.x][next.dir][reg] <<'\n';
        if(visited[next.y][next.x][next.dir][reg] == 1) continue;
        visited[next.y][next.x][next.dir][reg] =1;
        q.push(next);
        //cout <<"next\n";
    }
    //cout <<"can't find\n";
    return false;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int Test_Case;

    cin >> Test_Case;
    for(int tc =0; tc< Test_Case; tc++){
        
        
        cin >> R >> C;
        for(int i =0; i<R; i++){
            for(int j =0; j<C; j++){
                cin >> map[i][j];
            }
        }
        POS start;
        start.x = 0; start.y = 0;
        start.dir = Right;

        cout <<"#"<<tc+1<<' ';
        if(solve(start)) cout <<"YES\n";
        else cout <<"NO\n";
        
        init();

    }
    return 0;
}
// 2
// 11 4
// ->??
// <7@1
// 3205
// 94^4
// 0_92
// 821?
// v6-^
// 2@29
// 9._?
// 12-2
// 1+-77 4
// 7 4
// -@.+
// ?831
// >32?
// >8v0
// 84>>
// .32>
// @8@5