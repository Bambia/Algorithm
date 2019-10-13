#include <iostream>
#include <limits.h>
#include <algorithm>
using namespace std;
typedef long long ll;

int N,M,scan;
int A[100001];
bool check(int idx, int num ){
    if(A[idx] >= num) return true;
    else return false;
}

bool binary_sarch(int num){
    int l = 0, r=N-1;
    while(l < r){
        int mid = (l+r+1)/2;
        if(check(mid,num)) l = mid;
        else r = mid-1;
    }
    //cout <<"searcj index:" <<l<<" value : " <<A[l] <<"num = "<< num <<'\n';
    if(A[l] == num) return true;
    else return false;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N ;
    
    for(int i=0; i<N; i++) cin >> A[i];
    sort(A,A+N, [](const int &l,const int &r){
        return l>r;
        

    } );

    //for(int i=0; i<N; i++) cout << A[i]<<".";
    //cout <<'\n';
    cin >> M;
    for(int i=0; i < M; i++) {
        cin >> scan;
        cout << binary_sarch(scan) <<'\n';
    }
    return 0;
}