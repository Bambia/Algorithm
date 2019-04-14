#include <stdio.h>

using namespace std;
struct POINT{
    int x,y;
};

int ret=4;

int M,N,H;
int map[31][31];

bool check(){
    for(int i=1; i<=N; i++){
        int pos =i;
        for(int j=1; j<=H; j++){
            if(map[j][pos]== 1){ //오른쪽에 사다리가 있으면
                pos++;
            }
            else if(map[j][pos-1]== 1){ //왼쪽에 사다리가 있으면
                pos--;
            }   
        }
       if(pos!=i){
               // printf("check fail\n");
                return false;
       }
        
    }
    //printf("check success\n"); 
    return true;
    
}
void dfs(int idx, int x, int y){
    
    if(idx >=ret) return ;
    if(check()){
        //printf("check success return current idx \n");
        ret = idx;
        return;
    }
    if (idx == 3) return;

    for(int i =y; i<=H; i++){
        for(int j=x; j<N; j++){
            if(map[i][j] ==0 && map[i][j-1] ==0 && map[i][j+1] ==0){
                //printf("make ladder\n");
                map[i][j] = 1;
                dfs(idx+1,j,i);
                map[i][j] = 0;  
            } 
        }
        x=1;
    }
    
}

int main(void){

    scanf("%d %d %d",&N,&M,&H);
    int a,b;
    for(int i=0; i<M; i++){
        scanf("%d %d",&a,&b);
        map[a][b]=1;
    }

    ret = 4;
    dfs(0,1,1);
    if(ret >3) ret = -1;

    printf("%d",ret);
    return 0;
}
