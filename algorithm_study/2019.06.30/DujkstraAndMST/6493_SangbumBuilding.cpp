#include <cstdio>
#include <queue>


using namespace std;
struct CUBE {
    int level,row,col,time;
};
const int MAX_SIZE = 31;
int L,R,C,ans;
int dx[6] = {1,0,-1,0,0,0};
int dy[6] = {0,1,0,-1,0,0};
int dz[6] = {0,0,0,0,1,-1};
char b[31][31][31],visited[31][31][31];

CUBE S,E;
void init(){
    for(int i=0; i<L; i++){
            for(int j=0; j<R; j++){
                    for(int k=0; k<C; k++){
                        visited[i][j][k] =0;
                    }
            }
    }
}
int BFS(CUBE S){
    queue <CUBE> q;
    q.push(S);
    visited[S.level][S.row][S.col] =1;
    while(!q.empty()){
        CUBE cur;
        cur.level = q.front().level;
        cur.col = q.front().col;
        cur.row = q.front().row;
        cur.time = q.front().time;
        q.pop();
        //printf("cur point : %d %d %d\n",cur.level,cur.row,cur.col);
        if(cur.level == E.level && cur.row == E.row && cur.col == E.col ) return cur.time;
        
        for(int i=0; i<6; i++){
            CUBE next;
            next.row = cur.row + dy[i];
            next.col = cur.col + dx[i];
            next.level = cur.level + dz[i];
            next.time = cur.time +1;
            //printf("next point : %d %d %d\n",next.level,next.row,next.col);
            if(next.row < 0 || next.row >=R || next.col <0 || next.col >= C || next.level < 0 || next.level >= L) continue;
            if(b[next.level][next.row][next.col] != '#' && !visited[next.level][next.row][next.col]) {
                    q.push(next);
                    visited[next.level][next.row][next.col] =1;
            }
        }
    }

    return -1;
}

int main(){

    while(1){
        scanf("%d %d %d",&L,&R,&C);

        if(L == 0 && R == 0 && C == 0) break;
        
        for(int i=0; i<L; i++){
            for(int j=0; j<R; j++){
                    scanf("%s",&b[i][j]); 
            }

        }     

        for(int i=0; i<L; i++){
            for(int j=0; j<R; j++){
                    for(int k=0; k<C; k++){
                        if(b[i][j][k] == 'S') {
                            S.level = i;
                            S.row = j;
                            S.col = k;
                            S.time = 0;
                        }
                        if(b[i][j][k] == 'E') {
                            E.level = i;
                            E.row = j;
                            E.col = k;
                        }  
                    }
            }

        }
        //printf("Start point : %d %d %d\n",S.level,S.row,S.col);
        //printf("End point : %d %d %d\n",E.level,E.row,E.col);
        init();
        ans = BFS(S);
        if(ans != -1)printf("Escaped in %d minute(s).\n", ans );
        else printf("Trapped!\n");



    }
    
    return 0;
}
