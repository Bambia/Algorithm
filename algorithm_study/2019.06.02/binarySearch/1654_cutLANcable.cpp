#include <iostream>
#include <limits.h>
using namespace std;
int k,n;
int cable[10001];
bool check(int num){
    long long sum =0; 
    for(int i = 0; i<k; i++){
            sum += cable[i]/num;
    }
    if(sum >= n) return true;
    else return false;

}
int binary_search(int val){
    long long l =1,r = INT_MAX;
    while(l<r){
        int mid = (l+r+1)/2;
        if(check(mid)) l = mid;
        else r = mid-1;
        //cout << "mid :"<< mid <<'\n';
    }

    return l;
}
int main(){
    cin >> k >> n;
    for(int i=0; i<k; i++){
        cin >> cable[i];
    }

    cout << binary_search(n)<<'\n';
    return 0;
}