#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int factorial(int n){
    if(n==0) return 1;
    return n*factorial(n-1);
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    vector<int> V;
    cin >> n;
    for(int i=0; i<n; i++){
       V.push_back(i+1);
    }
   // cout << factorial(n);
    
    for(int i=0; i<factorial(n); i++){
        for(auto i:V) cout <<i<<' ';
        next_permutation(V.begin(), V.end());
        cout <<'\n';
    }
    
 return 0;
}

