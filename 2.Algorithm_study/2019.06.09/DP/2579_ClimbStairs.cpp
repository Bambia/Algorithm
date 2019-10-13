#include <iostream>
using namespace std;

int max(int a,int b){
    if (a>b) return a;
    else return b;

}
int N,data[301],dp[301];

int main(){
    cin >> N;
    for(int i=1; i <= N; i++) cin >> data[i];
    dp[1] = data[1];
    dp[2] = data[1] +data[2];

    for(int i=3; i<=N; i++) dp[i] = max(data[i-1]+dp[i-3], dp[i-2]) +data[i];

    cout <<dp[N]<<'\n'; 
    return 0;

}