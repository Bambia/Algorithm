#include <iostream>
using namespace std;
int n,wine[10001],dp[10001];
int max(int a,int b){
    if(a>b) return a;
    else return b;

}
int main(){
    cin >> n;
    for(int i=1; i<=n; i++) cin >>wine[i]; 

    dp[1] = wine [1] ;
    dp[2] = wine [1]+ wine[2];

    for(int i=3; i<=n; i++) {
            dp[i] = max(wine[i]+dp[i-2], max(wine[i]+wine[i-1]+dp[i-3], dp[i-1] ) );
           //cout <<"i:"<<i<<"//"<< dp[i] <<"\n"; 
    }

    cout << dp[n] <<'\n';
    return 0;
}