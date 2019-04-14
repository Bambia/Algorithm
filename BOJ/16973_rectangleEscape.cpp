#include <iostream>
#include <queue>

using namespace std;
const int MAX = 1001;
struct point{
    int x;
    int y;
};

int N,M,H,W,Sr,Sc,Fr,Fc;

int map[MAX][MAX];
point S,A;
int depth=0;
int move_x[5]={-1,1,0,0}; // 왼 오 상 하
int move_y[5]={0,0,-1,1}; // 왼 오 상 하
int blockU=0,blockD=0,blockL=0,blockR=0; //블럭이 있어서 못가는 경우 1
int size=0;
int visited[MAX][MAX]={0,};
void bfs(struct point pos){
    queue <point> q;
    q.push(pos);

    while(!q.empty()){

        size = q.size();
        S=q.front();
        q.pop();
        cout <<S.y <<' '<<S.x <<'\n';

        if(S.y==Fr && S.x==Fc){
            cout <<"find !\n";
            queue <point> empty;
            q=empty;
            break;
        }

        for(int i=0; i<size+1; i++){
            //cout <<"c ";
            
            //blockU=0;
            //blockD=0;
            //blockL=0;
            //blockR=0;
            
            //상
            //blockU=0;
            for(int j=0; j<W; j++){
                if(((S.y-1<1)||map[S.y-1][S.x+j]==1) && (visited[S.y-1][S.x]==1)){ //y의 값이 1보다 작아지면 안됨
                    blockU=1;
                    //cout <<"BlockU"<<'\n';
                }

            }
            if(!blockU){
                visited[S.y-1][S.x]=1;
                cout <<"U";
                S.y=S.y-1;
                S.x=S.x;
                q.push(S);
            }
            //하
            for(int j=0; j<W; j++){
                if((((S.y+(H-1)+1)>N)|| map[(S.y+(H-1))+1][(S.x+j)]==1) && (visited[S.y+1][S.x]==1)){ //y+1의 값이 N보다 크면 안됨
                    blockD=1;
                    //cout <<"BlockD"<<'\n';
                }

            }
            if(!blockD){
                visited[S.y+1][S.x]=1;
                cout <<"D";
                S.y=S.y+1;
                S.x=S.x;
                q.push(S);
            }
            //좌
            for(int j=0; j<H; j++){
                if((((S.x-1)<=1)|| map[(S.y)+j][(S.x-1)]==1)&& (visited[S.y][S.x-1]==1) ){ //x의 값이 1보다 작아지면 안됨
                    blockL=1;
                    //cout <<"BlockL"<<'\n';
                }

            }
            if(!blockL){
                visited[S.y][S.x-1]=1;
                cout <<"L";
                S.y=S.y;
                S.x=S.x-1;
                q.push(S);
            }
            //우
            //blockR=0;
            for(int j=0; j<H; j++){
                if((((S.x+(W-1)+1)>=M)|| map[(S.y)+j][(S.x+(W-1))+1]==1)&& (visited[S.y][S.x+1]==1) ){ //x의 값이 M보다 크면 안됨
                    blockR=1;
                    //cout <<"BlockR"<<'\n';
                }

            }
            if(!blockR){
                visited[S.y][S.x+1]=1;
                cout <<"R";
                S.y=S.y;
                S.x=S.x+1;
                q.push(S);
            }

        }
        depth++;
    }
    cout <<"\nerror!! queue is empty\n";
    
}
int main(void){
    
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> N >>M;
    for(int i=1; i<N+1; i++){
        for(int j=1; j<M+1; j++){
            cin >> map[i][j];
       }
    }
    cin >> H >> W >> Sr >> Sc >> Fr >> Fc;
    
    A.y=Sr;
    A.x=Sc;

    bfs(A);
    cout <<"Depth: "<<depth;

    /*
    cout<<'\n';
    for(int i=1; i<N+1; i++){
        for(int j=1; j<M+1; j++){
            cout << map[i][j]<<' ';

       }
       cout <<'\n';
    }
    */


    return 0;
}