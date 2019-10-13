#include <iostream>
using namespace std;
long long p[101];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int tc,n;
    p[1] = 1;
    p[2] = 1;
    p[3] = 1;
    p[4] = 2;
    p[5] = 2;
    for(int i =6; i<101; i++){
        p[i] = p[i-1] + p[i-5];
    }
    cin >> tc;
    
    while(tc--){
        cin >>n;
        cout << p[n]<<'\n';

    }

    return 0;
}