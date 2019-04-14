#include <iostream>
#include <vector>
#include <queue>
#include <math.h>

struct point{
    int x,y;
    int dist;
};

point castle[16]; 

using namespace std;

int N,M,D;
vector <int> Archer; 
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

void dfs(int idx){

    if( Archer.size() == 3){  

        for(int i=0; i<Archer.size(); i++){
            cout<<" Position of archer: " << Archer[i]<<' ';
        }
        cout <<'\n'; 

        for(int i=0; i<N; i++){
            for(int j=0; j<M; j++){
                cmap[i][j]=map[i][j]; 
            }
        }

        int isupdate =1;

        while( isupdate ) {

            isupdate=0;
            for(int i=0; i<3; i++){ 
                    point arc,a;
                    int end=0;
                    arc.x = castle[Archer[i]].x;
                    arc.y = castle[Archer[i]].y;
                    a.x = 100;
                    a.y = -1;
                    //arc.dist = 0;
                    cout << "archer start search x:"<<arc.x<<" y:"<<arc.y<<'\n';
                    for(int j=N-1; j>=0; j--){ //1명의 궁수가 적을 찾는 탐색 
                        
                        for(int k=0; k<M; k++){

                            //cout <<"finding! x:"<<k<<" y:"<<j<<'\n';

                            if(cmap[j][k] ==1 && ( abs(arc.x - k)+ abs(arc.y-j) <=D ) ){ //적이 있으면
                                cout <<"find anenmy! x:"<<k<<" y:"<<j<<'\n';
                                if(a.x > k ){
                                    a.x = k;
                                    a.y = j;
                                    end=1;
                                }
                            }


                            //궁수가 거리 D 이상 탐색하면 종료
                        }
                        
                    }
                    if(end) enemy.push_back(a); 

            }
            int size = (enemy.size()-1);
            
            for(int i=size; i>=0; i--){
                
                if(cmap[enemy[i].y][enemy[i].x]==1) {
                    killcnt++;
                    cout <<"kill anenmy! x:"<<enemy[i].x<<" y:"<<enemy[i].y<<'\n';
                } 
                cmap[enemy[i].y][enemy[i].x] =0; 
                
                enemy.pop_back();
                
            }
            total += killcnt;
            killcnt=0;

        for(int i=0; i<N; i++){ // 1명의 궁수가 죽이고 나면
            for(int j=0; j<M; j++){
                cout << cmap[i][j]<<' ';
            }
            cout <<'\n';
        }

            if(!updateMap()) isupdate = 0; 
            else isupdate =1;     
        }
        if (total> max_kill) max_kill = total;


        cout <<"the combination of archer finish. total kill num :"<<total <<'\n';
        cout <<"max_kill num :"<<max_kill <<'\n';

        total =0;
        return;
    }

    for(int i=idx; i<M; i++){
        
        Archer.push_back(i);
        dfs(i+1);
        Archer.pop_back();
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

    dfs(0);
    cout <<max_kill;

    return 0;
}

  

  /*

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
  */