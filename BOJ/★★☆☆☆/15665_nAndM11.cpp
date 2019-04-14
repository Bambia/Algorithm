#include <iostream>
#include <algorithm>

using namespace std;

int N,M;
int input[8];
int arr[8];
int check[8];

void dfs(int pos){
    if(pos ==M){
        for(int i=0; i<M; i++){
            cout << arr[i]<<' ';
        }
        cout <<'\n';

        return;
    }

    int temp =0;

    for(int i=0; i<N; i++){
        if(temp!=input[i]){
            
            arr[pos]=input[i];
            temp =input[i];

            dfs(pos+1);

        }
    }
}
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    for(int i=0; i<N; i++){
        cin>> input[i];
    }
    sort(input,input+N);
    dfs(0);


    return 0;
}