#include <iostream>
#include <vector>
using namespace std;
int A[12];
int check[12];
int cal[4]; //0 덧셈 1 뺄셈 2 곱셈 3 나눗셈의 갯수
int cal_size;
int N;
int MAX= -1000000000;
int MIN= 1000000000;
vector <int> oper;
void bfs(int idx,int ans){
    if(idx == (N-1)){
        if(ans<MIN) MIN = ans;
        if(ans>MAX) MAX = ans; 
        return;
    }
    for(int i =0; i<(N-1); i++){
        if(check[i]==0){
            int temp;
            check[i]=1;
            if(oper[i] == 0) temp = ans+A[idx+1];
            else if(oper[i] == 1)  temp = ans-A[idx+1];
            else if (oper[i] == 2) temp = ans*A[idx+1]; 
            else if(oper[i] == 3) temp = ans/A[idx+1];
            bfs(idx+1,temp);
            check[i]=0;
        }
    }
}
int main(void){
    cin >> N;
    for(int i=0; i<N; i++) cin >> A[i];

    for(int i =0; i<4; i++){
        cin >> cal[i];
    }
    for(int i=0; i<4; i++){
        for(int j=0; j<cal[i]; j++){
            oper.push_back(i);
        }
    }
    bfs(0,A[0]);
    cout << MAX<<'\n';
    cout << MIN<<'\n';
    return 0;
}

/*
if(oper[i] == 0) bfs(idx+1,ans+A[idx+1]);
            else if(oper[i] == 1)  bfs(idx+1,ans-A[idx+1]);
            else if (oper[i] == 2) bfs(idx+1,ans*A[idx+1]); 
            else if(oper[i] == 3) bfs(idx+1,ans/A[idx+1]);
*/