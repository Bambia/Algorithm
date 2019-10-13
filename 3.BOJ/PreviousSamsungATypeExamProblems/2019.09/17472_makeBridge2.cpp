#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

struct POS{
    int x,y;
};

int dx[4] = {0,-1,0,1};
int dy[4] = {1,0,-1,0};

int M,N;
int orgMap[10][10],numMap[10][10];
int numCheck[10][10];
int numLandCnt = 0,numLand = 0;
int DistBtwLand[11][11];
1
bool inRange(POS pos)
{
    if( pos.y >= N || pos.x >= M || pos.x < 0 || pos.y < 0 ) return false;

    return true;

}
void findLandNUm(POS pos)
{   
    numLandCnt++;
    // numCheck[pos.y][pos.x] = 1;
    // numMap[next.y][next.x] = numLandCnt;
    queue <POS> q;

    q.push(pos);
    
    while(!q.empty()){
        POS cur = q.front();
        q.pop();

        for(int i=0; i<4; i++){
            
            POS next;
            next.x = cur.x + dx[i];
            next.y = cur.y + dy[i];

            if(!inRange(next)) continue;

            if(orgMap[next.y][next.x] == 1 && !numCheck[next.y][next.x] )
            {
                numCheck[next.y][next.x] = 1;
                numMap[next.y][next.x] = numLandCnt;
                q.push(next); 
            }

        }        

    }
}

void connectLand(POS pos)
{
    int num = numMap[pos.y][pos.x];
    queue <POS> q; 
    q.push(pos);

    while(!q.empty())
    {
        POS cur = q.front();
        q.pop();

        for(int i=0; i<4; i++)
        {
            POS next;
            
            next.x = cur.x + dx[i];
            next.y = cur.y + dy[i];

            if( !inRange(next) ) continue;

            if(numMap[next.y][next.x] == num && !numCheck[next.y][next.x] )
            {
                numCheck[next.y][next.x] = 1;

                for(int j=0; j<4; j++)  //4방향 직선에 다른 섬이 있는지 탐색
                {
                    int dist = 0;
                    POS move; 
                        
                    move.x = next.x + dx[j];
                    move.y = next.y + dy[j];

                    while(1) 
                    {  
                        move.x += dx[j];
                        move.y += dy[j];
                        dist = dist + 1;

                        if(!inRange(move)) break; 
                        if(numMap[move.y][move.x] == num) break;

                        if(numMap[move.y][move.x] != 0 ) {
                          
                            if(DistBtwLand[num][numMap[move.y][move.x]] > dist ) DistBtwLand[num][numMap[move.y][move.x]] = dist;         
                            //cout <<"next\n";
                            break;
                        }
                        
                    }
                }
                //cout <<"next\n";
                q.push(next); 
            }
        }
    }
}

int main(void)
{
    cin >> N >> M;

    for(int i=0; i<N; i++)
    {
        for(int j=0; j<M; j++)
        {
                cin >> orgMap[i][j];
                
        }
    }

    for(int i=0; i<N; i++)
    {
        for(int j=0; j<M; j++)
        {
                if(orgMap[i][j] == 1 && !numCheck[i][j]) findLandNUm({j,i});
        }
    }    
    
    numLand = numLandCnt;
    memset(numCheck,0,sizeof(numCheck));

    for(int i=1; i<=numLand; i++){
        for(int j=1; j<=numLand; j++){
            DistBtwLand[i][j] = 999; // 모든 섬간의 거리 초기화
        }
    }
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<M; j++)
        {
            if(numMap[i][j] != 0 && !numCheck[i][j]) connectLand({j,i});
        }
    }    
    
    cout <<"minimun distance\n";

    for(int i=1; i<=numLand; i++){
        for(int j=1; j<=numLand; j++){
            cout << DistBtwLand[i][j]<<' '; 
        }
        cout <<'\n';
    }    

    
    cout <<"LandNum: "<<numLand << " \n";

    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
                cout << numMap[i][j]<<' ';
        }
        cout <<'\n';
    }



    return 0;
}