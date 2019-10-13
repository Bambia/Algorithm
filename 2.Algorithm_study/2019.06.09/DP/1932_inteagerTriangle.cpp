#include <iostream>
using namespace std;
int max(int a, int b){
    if (a>b) return a;
    else return b;
}

int dp[501][501];
int n,res;
int main(){
    cin >> n;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=i; j++ ){
            cin >> dp[i][j];
        }
    }

    for(int i=1; i<=n; i++){
        for(int j=1; j<=i; j++ ){
            if(j==1) dp[i][j] += dp[i-1][j];
            else if(j == n) dp[i][j] += dp[i-1][j-1];
            else dp[i][j] += max(dp[i-1][j-1], dp[i-1][j]);
        }
    }
    for(int i=1; i<=n; i++){
        res = max(dp[n][i], res);
    }
    cout <<res<<'\n';
    
    return 0;
}