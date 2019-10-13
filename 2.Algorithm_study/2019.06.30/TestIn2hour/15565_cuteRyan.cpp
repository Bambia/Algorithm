#include <iostream>
using namespace std;
const int MAX_SIZE = 1e6+1;

int N,K,arr[MAX_SIZE],ok,ans;
bool check(int size){
    int cnt=0;
    for(int i=0; i<size; i++) {
        if(arr[i] == 1) cnt++; 
        
        if(cnt == K) {
            ok =1;
            ans = size;
            return true;
        }   
    }
    //cout <<cnt <<'\n';
    for(int i=size; i<N; i++) {
        if(arr[i]== 1) cnt += 1;
        if(arr[i-size] == 1) cnt -=1;
        //cout <<"cnt : "<< cnt <<'\n';
        if(cnt == K) {
            ok =1;
            ans = size;
            return true;
        }
    }
    return false;
    
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> K;
    for(int i=0; i<N; i++) cin >> arr[i];
    int l=1,r = N;
    
    while(l<r){
        int mid = (l+r+1)/2;
        //cout <<mid<<'\n';
        if(!check(mid)) l = mid;
        else r = mid -1; 
    }

    if(ok) cout <<ans;
    else cout <<"-1";
    return 0; 
}