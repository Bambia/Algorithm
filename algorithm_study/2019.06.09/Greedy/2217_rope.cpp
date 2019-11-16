#include <iostream>
#include <algorithm>

using namespace std;

int rope[100000],n,cur,cnt=1;

int main(){
    cin >>n;
    for(int i=0; i<n; i++) cin >> rope[i];

    sort(rope,rope+n,[](const int &l,const int &r){
        return l>r;

    });

    for(int i =0; i<n; i++){
        int next = rope[i]*cnt;
        if(cur < next ) cur = next; 
        cnt++;
    }

    cout <<cur<<'\n';

    return 0;
}