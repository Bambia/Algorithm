#include <iostream>
using namespace std;

long long n,m,tc,ans,c[31][31];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> tc;

    while(tc--){
        cin >> n >> m;
        for(int i=1; i<30; i++)c[i][1] =i;
        
        for(int i =2; i<=m; i++){
            for(int j=2; j<=n; j++){
                c[i][j] = c[i-1][j] + c[i-1][j-1]; 
            }
        }
        cout <<c[m][n]<<'\n';
    }
    
    return 0;
}