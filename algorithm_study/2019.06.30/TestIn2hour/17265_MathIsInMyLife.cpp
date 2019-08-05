#include <iostream>
#include <string>
#include <queue>
using namespace std;
struct POS{
    int x,y,sum;
};
int dx[2] ={1,0}; 
int dy[2] ={0,1};
const int MAX_SIZE = 6;
char map[MAX_SIZE][MAX_SIZE];
queue <POS> q;
int MAX=-1e9,MIN=1e9,N;

bool in_range(POS pos){
    if(pos.x < 0 || pos.y < 0 || pos.x >=N || pos.y >=N) return false; 
    return true;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N; 
    
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin >> map[i][j];
        }
    }  
    
    q.push({0,0,(map[0][0]-'0')});
    
    while(!q.empty()){
        POS cur = q.front();
        q.pop();
        //cout <<cur.y<<' '<<cur.x<<"sum: "<<cur.sum <<'\n';
        
        if(cur.x == N-1 && cur.y == N-1 ) {
            if(cur.sum > MAX) MAX = cur.sum; 
            if(cur.sum < MIN) MIN = cur.sum;

        }

        for(int i=0; i<2; i++){
            POS next;
            next.x = cur.x + dx[i];
            next.y = cur.y + dy[i];
            next.sum = cur.sum;
            if(!in_range(next)) continue;
            if(map[next.y][next.x] == '+' ){
                POS cal[2];
                for(int j=0; j<2; j++){
                    cal[j].x = next.x + dx[j];
                    cal[j].y = next.y + dy[j];
                    cal[j].sum = next.sum;
                    if(!in_range(cal[j])) continue;
                    cal[j].sum += (map[cal[j].y][cal[j].x]-'0');
                    q.push(cal[j]);
                }

            }
            else if(map[next.y][next.x] == '-' ){
                POS cal[2];
                for(int j=0; j<2; j++){
                    cal[j].x = next.x + dx[j];
                    cal[j].y = next.y + dy[j];
                    cal[j].sum = next.sum;
                    if(!in_range(cal[j])) continue;
                    cal[j].sum -= (map[cal[j].y][cal[j].x]-'0');
                    q.push(cal[j]);
                }
            }
            else if(map[next.y][next.x] == '*' ){
                POS cal[2];
                for(int j=0; j<2; j++){
                    cal[j].x = next.x + dx[j];
                    cal[j].y = next.y + dy[j];
                    cal[j].sum = next.sum;
                    if(!in_range(cal[j])) continue;
                    cal[j].sum *= (map[cal[j].y][cal[j].x]-'0');
                    q.push(cal[j]);
                }
            }
        }
        
    }
    cout <<MAX <<' '<< MIN <<'\n';
    


    return 0;
}
/*

 */