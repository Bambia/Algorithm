#include <iostream>
using namespace std;

int p[1001],dp[1001],n;
int max(int a,int b){
    if(a>b) return a;
    else return b;

}
int main(){
    cin >> n;
    for(int i=1; i<=n; i++) cin >> p[i];
    
    dp[0] = 0;
    dp[1] = p[1];

    for(int i=2; i<=n; i++){
        for(int j =1; j<=i; j++ ){
            dp[i] = max(dp[i],dp[i-j]+p[j]);
        }
    }
    cout <<dp[n] <<' ';
    return 0;
}