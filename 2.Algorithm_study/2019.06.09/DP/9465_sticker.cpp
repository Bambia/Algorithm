#include <iostream>
using namespace std;

int n,tc,ans,s[3][100001];
int dp[3][100001]; //2번째인자는 방향

int max(int a,int b){
    if(a>b) return a;
    else return b;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> tc;

    while(tc--){
        cin >> n;


        for(int i=0; i<2; i++){
            for(int j=1; j<=n; j++) cin >> s[i][j];
        }
        dp[0][1] = s[0][1];
        dp[1][1] = s[1][1];
        dp[0][2] = s[1][1]+ s[0][2];
        dp[1][2] = s[0][1]+ s[1][2];

        for(int i=3; i<=n; i++) {
            dp[0][i] = max(dp[1][i-1],dp[1][i-2]) + s[0][i];
            dp[1][i] = max(dp[0][i-1],dp[0][i-2]) + s[1][i];
        }
        ans = max(dp[0][n],dp[1][n]);
        cout <<ans <<'\n';
        
    }

    
    
    return 0;
}