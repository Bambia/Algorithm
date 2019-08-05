#include <iostream>

using namespace std;

int num[31];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    for(int i=0; i<28; i++){
        int n=0;
        cin >> n;
        num[n] =1;
    }
    for(int i=1; i<=30; i++){
        if(num[i] == 0) cout <<i <<'\n';
    }
    return 0;
}