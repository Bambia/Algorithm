#include <iostream>

using namespace std;

const int MAX = 10000;
int N;
int arr[MAX][MAX]={0,};
long long sum=0;
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin >> arr[i][j];
            sum+=arr[i][j];
        }
    }
    cout <<sum;

    return 0;
}