#include <iostream>
using namespace std;

long long n,m;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n >> m;
    if(n > m)  {
        int temp = n;
        n = m;
        m = temp;
    }

    cout << (n-1)*m + (m-1) <<'\n';

    
    
    return 0;
}