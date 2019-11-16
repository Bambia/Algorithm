/*
하얀 칸
시간 제한	메모리 제한	제출	정답	맞은 사람	정답 비율
2 초	128 MB	8236	5285	4643	66.979%
문제
체스판은 8*8크기이고, 검정 칸과 하얀 칸이 번갈아가면서 색칠되어 있다. 가장 왼쪽 위칸 (0,0)은 하얀색이다. 체스판의 상태가 주어졌을 때, 하얀 칸 위에 말이 몇 개 있는지 출력하는 프로그램을 작성하시오.

입력
첫째 줄부터 8개의 줄에 체스판의 상태가 주어진다. ‘.’은 빈 칸이고, ‘F’는 위에 말이 있는 칸이다.

출력
첫째 줄에 문제의 정답을 출력한다.

*/


#include <iostream>


using namespace std;

int map[9][9];
char ch[9][9];
int visited[9];
int depth=0;

void dfs(int cnt){
    if(visited[cnt]==1) return;
    visited[cnt]=1;
    /*
    if(cnt==7) {
        return;
    }*/
    for(int i=0; i<8; i++){
        
        if(map[cnt][i]==1){
            
            cout <<cnt <<' '<<i<<'\n';           
            
            if(ch[cnt][i]=='F') {
                depth++;
            }
            dfs(cnt+1);

        }
    }
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    for(int i=0; i<8; i++){
        for(int j=0; j<8; j++){
            cin >>ch[i][j];       
        }
    }
    cout <<'\n';
    for(int i=0; i<8; i++){
        for(int j=0; j<8; j++){
            cout <<ch[i][j];       
        }
        cout <<'\n';
    }
    
    for(int i=0; i<8; i++){
        for(int j=0; j<8; j++){
            if(i%2==0&&j%2==0){
                map[i][j] = 1;
            }
            else if(i%2!=0&&j%2!=0){
                map[i][j] = 1;
            }
            else{
                map[i][j] = 0;
            }
                  
        }
    }

    dfs(0);
    ///출력
    cout <<'\n';
    for(int i=0; i<8; i++){
        for(int j=0; j<8; j++){
            cout << map[i][j]<<' ';       
        }
        cout <<'\n';

    }
    cout <<"depth: "<<depth;
    
    

    return 0;
}

/*
예제 입력 1 
.F.F...F
F...F.F.
...F.F.F
F.F...F.
.F...F..
F...F.F.
.F.F.F.F
..FF..F.
예제 출력 1 
1
*/