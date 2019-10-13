#include <iostream>
using namespace std;

int a,b,v;
bool check(long long x){
    long long climb =0;
    climb = (a-b)*(x-1);
    climb += a;
    cout << "climb:" <<climb <<'\n';
    if(climb >= v) return false;
    else return true;
}
int main(){
    cin >> a >> b >> v;
    int l = 1,r = 1e9;
    while(l<r){
        long long mid = (l+r)/2;
        cout <<"mid:"<<mid <<'\n';

        if(check(mid)) l = mid +1;
        else r = mid;
        
    }
    cout << l <<'\n';

    return 0;
}