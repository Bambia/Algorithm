#include <iostream>
#include <queue>
using namespace std;

struct POS{
    int x,y;
};
POS Start,End;

int map[16][16];
int visited[16][16];
int N;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

void init(){
    N =0;
    Start.x = 0; Start.y =0;
    End.x = 0; End.y = 0;
    for(int i=0; i<16; i++){
            for(int j =0; j<16; j++){
                map[i][j] = 0; visited[i][j] =0;
            }
    }
    
}
bool solve(POS pos){
    queue <POS> q;
    visited[pos.y][pos.x] = 1;
    q.push(pos);

    while(!q.empty()){
        POS cur;
        cur.x = q.front().x;
        cur.y = q.front().y;
        q.pop();

        
        for(int i=0; i<4; i++){
            POS next;    
            next.x = cur.x + dx[i];
            next.y = cur.y + dy[i];

            if(next.x <0 || next.y <0 || next.x >=16 || next.y >=16 ) continue;

            if(map[next.y][next.x] != 1 && !visited[next.y][next.x]){
                visited[next.y][next.x] = 1;
                q.push(next);
            }
            if( (next.x == End.x) && (next.y == End.y) ) return true;
        }
    }

    return false;
}

int main(){

    int test_case = 10;
    
    for(int tc =0; tc<test_case; tc++){
       init();  
        scanf("%d",&N);
        for(int i=0; i<16; i++){
            for(int j =0; j<16; j++){
                scanf("%1d",&map[i][j]);
                if(map[i][j] == 2) {
                    Start.x = j; Start.y = i; 
                }
                else if(map[i][j] ==3) {
                    End.x = j; End.y = i; 
                }
            }

        }

       printf("#%d %d\n",N,solve(Start));
    }
    
    return 0;
}