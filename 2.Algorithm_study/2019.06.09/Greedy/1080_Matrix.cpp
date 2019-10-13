#include <iostream>
using namespace std;
int N,M,ans,no;
char A[51][51],B[51][51];
int main(){
    cin >> N >> M;
    for(int i=0; i<N; i++){
        for(int j =0; j<M; j++) cin >> A[i][j];
    }
    for(int i=0; i<N; i++){
        for(int j =0; j<M; j++) cin >> B[i][j];
    }

    for(int i=0; i<N-2; i++){
        for(int j=0; j<M-2; j++){
            
            if(A[i][j] != B[i][j]) {
                ans++;
                for(int k=i; k<i+3; k++){
                    for(int l=j; l<j+3; l++){
                        if(A[k][l] =='1') A[k][l]= '0';
                        else A[k][l]= '1';
                    }
                }
            }

        }
    }
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(A[i][j]!=B[i][j]) no =1;
        }
    }

    if(no) cout <<"-1";
    else cout << ans;
    return 0;
}