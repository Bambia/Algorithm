#include <iostream>
using namespace std;
long long dp[10][1001],ans,n; // dp[숫자][자리수];


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n;
    for(int i =0; i<10; i++) dp[i][1] = 1; // 한자리 수 의 각 수는 1개씩 있다.

    for(int i=2; i<=n; i++){
        for(int j=0; j<10; j++){
            for(int k=j; k<10; k++) dp[j][i] = (dp[j][i] + dp[k][i-1])%10007; 
        }
    }
    
    for(int i=0; i<10; i++) ans = (ans + dp[i][n])%10007;
    cout <<ans <<'\n';

    return 0;
}