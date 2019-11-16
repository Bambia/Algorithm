#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

struct point{
    int r;
    int c;

};
point start_size;
point end_size;
const int MAX = 11;

int R,C;
char map[MAX][MAX];
char newMap[MAX][MAX];
int dr[4]={0,0,-1,1};
int dc[4]={-1,1,0,0};
int visited[MAX][MAX];
int flag=0;
int flag1=0,flag2=0,flag3=0,flag4=0;
bool in_range(struct point a){
    if( (a.c>=0) && (a.c<=(C+1)) && (a.r>=0) && (a.r<(R+1)) ) return true;
    else return false;
}
void bfs(struct point pos){
    queue <point> q;
    q.push(pos);
    //cout <<"bfs start"<<'\n';

    while(!q.empty()){
        //cout <<"while start"<<'\n';
        point start;
        start = q.front();
        q.pop();
        //cout <<start.r <<' '<<start.c<<'\n';
        int cnt=0;
        if(visited[start.r][start.c]==0&&map[start.r][start.c]=='X'){ //땅이고 방문하지 않았을 때

            visited[start.r][start.c] =1; //방문 표시
            
            //cout <<"find land"<<'\n';
            for(int i=0; i<4; i++){ //4방향 탐색
                point New;
                 New.r= start.r+dr[i];
                 New.c= start.c+dc[i];
                //if(!( New.r>=0 && New.r <=(R+1) && New.c>=0 && New.c <=(C+1) )) continue; //맵안+1칸의 범위일 때 맵이 안보여도 밖에는 다 바다 이므로 한칸씩 더 봐야 된다.
                 if(!in_range) continue;

                 //cout <<"search see:"<<New.r<<' '<<New.c<<'\n';   
                if(map[New.r][New.c] !='X') {//땅이 아니면 (바다이면)
                     cnt ++;
                     //cout <<"find see cnt:"<<cnt<<'\n';
                }
                
                if(map[New.r][New.c] =='X' &&visited[New.r][New.c]==0){// 땅이고 방문한 곳이 아니면 q에 넣고 다음 탐색
                    point a;
                    a.c = New.c;
                    a.r = New.r;
                    q.push(a);
                    //cout <<"find another land"<<'\n';
                 }
            }
            if(cnt>=3) {
                newMap[start.r][start.c] = '.';
                //cout <<"removed land"<<'\n';
                
            }
        }
        
    }

}

int main(void){
    cin >> R >> C;
    for(int i=1; i<R+1; i++){
        for(int j=1; j<C+1; j++){
            cin >>map[i][j]; 
            newMap[i][j] = map[i][j];

        }
    }
    
    start_size.r= 1;
    start_size.c= 1;

    end_size.r= R+1;
    end_size.c= C+1;
    //cout << start_size.c <<" "<<end_size.c<<'\n';
    //cout << start_size.r <<" "<<end_size.r<<'\n';


    /*
    cout <<"****map***\n";
    for(int i=0; i<R+1; i++){
        for(int j=0; j<C+1; j++){
            cout <<map[i][j]<<' ';
        }
        cout <<'\n';
    }*/
    for(int i=1; i<R+1; i++){
        for(int j=1; j<C+1; j++){
            point b;
            b.r=i;
            b.c=j;
            //cout <<"bfs start"<<'\n';
            bfs(b);
            //cout <<"bfs end\n";
        }
    }

    for(int i=0; i<R+1; i++){
        for(int j=0; j<C+1; j++){
            if(newMap[i][j]=='X') flag=1;
        }
        
    }
    if(flag){
    while(!((flag1&&flag2&&flag3&&flag4) )){
    
        for(int i=start_size.c; i<=end_size.c; i++){   //위쪽 없애기
             if(newMap[start_size.r][i]=='X') flag1=1;  //다검사했는데 X가 없으면  
        }
         if(!flag1) {
             start_size.r++;
            //cout <<"flag1\n";
        }

    
        for(int i=start_size.c; i<=end_size.c; i++){   //아래쪽 없애기
             if(newMap[end_size.r][i]=='X') flag2=1;   //다 검사했는데 X가 없으면
        }
        if(!flag2) {
            end_size.r--;
            //cout <<"flag2\n";
            }
    
    for(int i=start_size.r; i<=end_size.r; i++){   //오른쪽 없애기
        if(newMap[i][end_size.c]=='X') flag3=1;   
    }
    if(!flag3) {
        end_size.c--;
    //cout <<"flag3\n";
    }
    
    for(int i=start_size.r; i<=end_size.r; i++){   //왼쪽 없애기
        if(newMap[i][start_size.c]=='X') flag4=1;   
    }
    if(!flag4) {
        start_size.c++;
    }
    //if(start_size.r <0 || end_size.r>=R || start_size.c<0 || end_size.c>=C ) flag=1; 
        
    //cout <<"flag4\n";
    }

      //cout <<'\n';
    
    /*
    cout << start_size.c <<" "<<end_size.c<<'\n';
    cout << start_size.r <<" "<<end_size.r<<'\n';
    //cout <<'\n';
    cout <<"original newMap:\n";
    for(int i=1; i<=R+1; i++){
        for(int j=1; j<=C+1; j++){
            cout <<newMap[i][j];
        }
        cout <<'\n';
    }
    cout <<"after newMap:\n";
    */
    for(int i=start_size.r; i<=end_size.r; i++){
        for(int j=start_size.c; j<=end_size.c; j++){
            cout <<newMap[i][j];
        }
        cout <<'\n';
    }
    }
    else 

    return 0;
}