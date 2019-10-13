#include <iostream>
using namespace std;

int arr[100001],n,sum,max1=-1e9;

int main(){
    cin >> n;
    for(int i=1; i<=n; i++) cin >>arr[i]; 

    for(int i=1; i<=n; i++) {
        sum += arr[i];
        if(max1 <sum) max1 = sum;
        if(sum<0) sum = 0;
    }
    cout <<max1 <<'\n';
    return 0;
}