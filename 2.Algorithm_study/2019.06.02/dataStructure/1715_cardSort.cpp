#include <iostream>
#include <algorithm>
using namespace std;
long long N,sum,res;
long long arr[1000001];
int main(){
    cin >> N;
    for(int i=0; i<N; i++){
        cin >> arr[i];
    }
    sort(arr,arr+N);
    
    if(N==1) res = 0;
    else sum =arr[0]; 
    for(int i=1; i<N; i++){
        sum += arr[i];
        res += sum;
    }
    cout << res<<'\n';
    return 0;

}