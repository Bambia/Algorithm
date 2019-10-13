#include <iostream>
using namespace std;
const int MX = 1e6+1;
int N,B,C;
int A[MX];
long long ans;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    for(int i=0; i<N; i++) cin >> A[i];

    cin >> B >> C;
    for(int i=0; i<N; i++){
        A[i] -= B;
        ans++;
        
        if(A[i]>0){
            ans += (A[i] / C) ;
            if ((A[i] % C) != 0) ans += 1;
        }
    }

    cout <<ans<<'\n';

    return 0;
}