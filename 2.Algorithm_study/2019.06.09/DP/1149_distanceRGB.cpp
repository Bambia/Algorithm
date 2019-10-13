#include <iostream>
using namespace std;

int N;
int dp[1001][3]; 
int data[1001][3];

int min(int a,int b){
    if(a>b) return b;
    else return a;
}

int func(int n){
    int ans=0;

    for(int i=2; i<=n; i++){
        dp[i][0] += min(dp[i-1][1] , dp[i-1][2]);

        dp[i][1] += min(dp[i-1][0] , dp[i-1][2]);

        dp[i][2] += min(dp[i-1][0] , dp[i-1][1]);
    }
    return ans = min(dp[n][0], min(dp[n][1],dp[n][2]) );
}
int main(){
    cin >> N;
    for(int i =1; i<=N; i++) {
        for(int j =0; j<3; j++){
            cin >> dp[i][j];
        }
    }
        
    cout <<func(N)<<'\n';
    return 0;
}