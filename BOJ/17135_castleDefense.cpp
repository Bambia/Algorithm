#include <iostream>
#include <vector>
#include <queue>

struct point{
    int x,y;
    int dist;
};

point castle[16]; 

using namespace std;

int N,M,D;
int Archer[3]; 
int map[16][16],cmap[16][16];
vector <point> enemy;

point position;

int killcnt=0,max_kill;
int total;
int dx[3]={-1,0,1}; 
int dy[3]={0,-1,0}; 


bool in_range(struct point pos){
    if(pos.x >=0 &&pos.x <M && pos.y >=0 &&pos.y<N) return true;
    else return false;    
}
bool updateMap(){
        int flag =0;

        for(int i=N-2; i>=0; i--){
            for(int j=0; j<M; j++){
                
                cmap[i+1][j]=cmap[i][j]; 
                
                if(cmap[i][j]==1) flag=1; 
            }

        }
        for(int i=0; i<N; i++) cmap[0][i] =0;

        if(flag) return true;
        else return false;
    
}
void bfs(struct point pos){ 
    queue <point> q;
    
    q.push(pos); 

    while(!q.empty()){ 
        point cur;
        
        cur = q.front();   
        q.pop();
        
        
        if(cur.dist > D) {
            queue <point> temp;
            q = temp; 
            break;
        }

        for(int i=0; i<3; i++){ 
            point next;
            next.x = dx[i]+cur.x;
            next.y = dy[i]+cur.y;
            next.dist = cur.dist+1; 

            if(!in_range(next)) continue; 
            
            if( (cmap[next.y][next.x]==1) && (next.dist <=D) ){  
                
                enemy.push_back(next); 
                queue <point> temp;
                q = temp; 
                break;
            }
            q.push(next); 

        }
    }
}
void dfs(int idx){
    
    for (int i=0; i<M; i++) {
        for (int j=i+1; j<M; j++) {
            for (int k=j+1; k<M; k++) {
                Archer[0] = i, Archer[1] = j, Archer[2] = k;

                for(int i=0; i<N; i++){
                    for(int j=0; j<M; j++){
                        cmap[i][j]=map[i][j]; 
                    }
                }
                int isupdate =1;

                while( isupdate ) {

                    isupdate=0;
                    for(int i=0; i<3; i++){ 
                            castle[Archer[i]].dist =0; 
                                
                            bfs(castle[Archer[i]]); 
                    }
                    int size = (enemy.size()-1);
                        
                    for(int i=size; i>=0; i--){
                            
                        if(cmap[enemy[i].y][enemy[i].x]==1) killcnt++; 
                            cmap[enemy[i].y][enemy[i].x] =0; 
                            
                            enemy.pop_back();    
                        }
                        total += killcnt;
                        killcnt=0;

                        if(!updateMap()) isupdate = 0; 
                        else isupdate =1;     
                    }
                if (total> max_kill) max_kill = total;

                total =0;
            }
        }
    }

    

}

int main(void){
    
    cin >> N >> M >> D;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin >> map[i][j];
            castle[j].x = j; 
            castle[j].y = N; 
        }
    }

    


    cout <<max_kill;

    return 0;
}

  