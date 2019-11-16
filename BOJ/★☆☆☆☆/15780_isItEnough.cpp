#include <iostream>

using namespace std;

int N,K;

int arr[101]={0,};
int sum;
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> K;
    for(int i=0; i<K;i++){
        cin >> arr[i];
    }

    for(int i=0; i<K;i++){
        if(arr[i]==3 ||arr[i]==4){
            sum+=2;
        }
        else if(arr[i]==5 ||arr[i]==6){
            sum+=3;
        }
        else if(arr[i]==7 ||arr[i]==8){
            sum+=4;
        }
    }
    if(N<=sum) cout <<"YES";
    else cout <<"NO";

    return 0;
}
