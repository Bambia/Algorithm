#include <iostream>
using namespace std;
int n,k,cnt,sum;
int c[10];

int main(){
    cin >> n >> k;
    for(int i=0; i<n; i++) cin >> c[i];

    for(int i=(n-1); i>=0; i--){
        while(1){
            if(k >= (sum + c[i]) ) {
                sum +=c[i];
                cnt++;
            }
            else break;
        }
    }

    cout << cnt <<'\n';

}