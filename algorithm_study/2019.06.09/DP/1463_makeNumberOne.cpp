#include <iostream>
#include <cstring>
using namespace std;
#define INF 1e9

int N;
int dp[1000001];
int min(int a,int b){
    if(a>b) return b;
    else return a;
}
int fill(int arr[], int num, int size ){
    for(int i=0; i<size; i++) arr[i] = num;
}
int func(int n){
    fill(dp,INF,sizeof(dp)/4);
    dp[n] =0;
    for(int i =n; i>1; i--){
        if(!(i%3)) dp[i/3] = min(dp[i]+1 ,dp[i/3]);
        if(!(i%2)) dp[i/2] = min(dp[i]+1 ,dp[i/2]);
        
        dp[i-1] = min(dp[i]+1 ,dp[i-1]);
        cout<<"dp["<<i<< "] "<< dp[i] <<'\n';
    }

    return dp[1];
}
int main(){
    cin >> N;
    cout <<func(N)<<'\n';
    return 0;
}