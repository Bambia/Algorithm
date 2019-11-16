#include <iostream>
#include <string.h>
using namespace std;

int tc,n;
int dpZ[41],dpO[41];

int findZero(int n){
    int ret = dpZ[n];
    if( n== 0) return 1; 
    else if(n ==1) return 0;
    if(dpZ[n] != -1) return ret;

    dpZ[n] = findZero(n-1) + findZero(n-2);
    return dpZ[n];   
}
int findOne(int n){
    int ret = dpO[n];
    if( n== 0) return 0; 
    else if(n ==1) return 1;
    if(dpO[n] != -1) return ret;

    dpO[n] = findOne(n-1) + findOne(n-2);
    return dpO[n];

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> tc;
    memset(dpZ,-1,sizeof(dpZ));
    memset(dpO,-1,sizeof(dpO));

    while(tc--){
        cin >> n;

        cout <<findZero(n)<<' '<<findOne(n)<<'\n';

    }

    return 0;
}