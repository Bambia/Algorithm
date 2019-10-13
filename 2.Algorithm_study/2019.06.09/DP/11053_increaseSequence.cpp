#include <iostream>
using namespace std;

long long dp[1001],data[1001],N,ans;

long long max(long long a,long long b){
    if(a>b) return a;
    else return b;
}
int main(){
    cin >> N;
    for(int i=1; i<=N; i++) cin >> data[i];
    for(int i=1; i<=N; i++) dp[i] = 1;
    

    for(int i=2; i<=N; i++) {
        for(int j=1; j<i; j++ ){ 
            if(data[i]>data[j]) {

                dp[i] = max(dp[i],dp[j]+1);
                //cout <<"data i:"<<i <<" data j:"<<j <<" dp[i]:"<<dp[i]<<'\n';
            } 
        }
    
    }
    for(int i =1; i<=N; i++) ans= max(ans,dp[i]);
    cout <<ans<<'\n';

}