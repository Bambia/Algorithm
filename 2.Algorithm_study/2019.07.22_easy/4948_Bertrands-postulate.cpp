#include <iostream>

using namespace std;
const int MAX = 123456*2 + 1;

int arr[MAX];
void init(){
    for(int i=2; i<=MAX; i++){
        arr[i] = i;
    }
    for(int i=2; i<=MAX; i++){
        if(arr[i]==0) continue;
        for(int j=i*2; j<MAX; j+=i){
            arr[j] = 0;
        }
    }
}
int func(int n){
    int cnt=0;
    for(int i=n+1; i<=2*n; i++) {
        if(arr[i] !=0 )cnt++;
    }
    return cnt;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    init();
    int n=0;
    while(1){
        cin >> n;
        if(n == 0) break;
        cout<< func(n)<<'\n';
    }
   

    return 0;
}
