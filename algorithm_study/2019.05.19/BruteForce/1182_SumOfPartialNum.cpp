#include <iostream>

using namespace std;
int v[21];
int cnt;
int N,S;
void func(int pos, int sum){
    if(pos == N){
        if(sum == S) cnt++;
    
        return;
    }

    func(pos+1,sum+v[pos]);
    func(pos+1,sum);
    
}
int main(void){
    
    cin >> N >> S;

    for(int i=0; i<N; i++ ){
        cin >> v[i];
    }
    func(0,0);
    if(S == 0) cnt--;

    cout << cnt;

    return 0;
}