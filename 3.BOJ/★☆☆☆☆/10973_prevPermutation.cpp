#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,cnt=0,a;
    vector<int> V;
    cin >> n;

    for(int i=0; i<n; i++){
       cin >> a;
       V.push_back(a);
    }


    if(!prev_permutation(V.begin(), V.end())) cout << -1;
    else {
        for(auto i:V) cout <<i<<' ';
    }
        return 0;
}