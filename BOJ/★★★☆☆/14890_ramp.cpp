#include <iostream>

using namespace std;

const int MAX = 101;


int X[MAX][MAX];
int Y[MAX][MAX];

int N,L;
int cnt=0;

void check(int row,int a[101][101]){
    int temp = a[row][0];
    int c[101]={0,};
        for(int i=0; i<N; i++){ //한줄 검사
            if(a[row][i]!=temp){
                //cout <<"find another value\n";
                if(a[row][i]-temp>1 || a[row][i]-temp< -1) return; // 1이상 차이날 때
                if(a[row][i]<temp){ //내려가는 겨우
                //cout <<"down\n";
                    int cmp=-1; //cmp는 경사 밑의 값들이 동일한지 비교하는 변수
                    for(int j=i; j<=i+L-1; j++){ //나를 포함하고 경사로를 오른쪽으로
                        if(j>=N||c[j]==1) return; //경사로의 길이가 N을 넘어 가거나 c[i]가 이미 방문 했을 때 종료
                        c[j]=1;
                        if(cmp==-1){
                            cmp=a[row][j]; //처음 cmp 
                            //continue;
                        }
                        if(cmp!=-1 && cmp!=a[row][j]) return; // 처음 값이 저장 되었고 그 이후의 값이 처음 값과 다르면
                    }
                    i = i+L-1; //경사로 뒤로 탐색 범위 점프
                    //if(i>=N) break;

                }
                else{ // 올라가는경우
                //cout <<"up\n";
                    int cmp=-1; //cmp는 경사 밑의 값들이 동일한지 비교하는 변수
                    for(int j=i-1; j>=i-L; j--){ //나를 포함하지 않고 경사로를 왼쪽으로 
                        if(j<0||c[j]==1) return; //경사로의 길이가 N을 넘어 가거나 c[i]가 이미 방문 했을 때 종료
                        c[j]=1;
                        if(cmp==-1){
                            cmp=a[row][j]; //처음 cmp
                            //continue; 
                        }
                        if(cmp!=-1 && cmp!=a[row][j]) return; // 처음 값이 저장 되었고 그 이후의 값이 처음 값과 다르면
                    }
                    //i=i; //탐색 점프 없음 뒤에 값을 비교했기 때문에

                    //if(i>=N) break;
                }
               temp = a[row][i]; //temp 사용했기 떄문에 새로운 값으로 교체  
            }
             
        }
        cnt++;    
}
int main(void){
    
    cin >> N >> L;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin >> X[i][j]; //가로 저장
            Y[j][i] = X[i][j]; //세로 저장
        }
    }

    for(int j=0; j<N; j++){
        check(j,X); //가로 탐색
        check(j,Y); //세로 탐색
    }

    cout <<cnt;      
    
    return 0;
}