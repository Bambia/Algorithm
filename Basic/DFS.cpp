
#include <iostream>
#include <algorithm>

using namespace std;

const int MAX = 100001;


int N,M;

int check[10];
int arr[10];
int input[10];
int temp=0;

void dfs(int depth,int pos){
    
    depth++;
    cout <<"call dfs "<<'\n';

    temp=0;
    for(int i=0; i<N; i++){
        cout <<"call for loop i="<<i<<" depth:"<< depth<<'\n';
        //if((check[i]==0) && (temp!=input[i])){  
        if(check[i]==0){
            cout <<"find check=0 vertex: ";
            arr[pos]=input[i];
            cout << input[i]<<'\n';
            check[i]=1;
            temp=input[i];
            dfs(depth,pos+1);
            check[i]=0;
        }
        else{
            cout << "here is already checked vertex: "<< input[i]<<'\n';
        }
    }
}



int main(void){

    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;

    for(int i=0; i<N; i++){
        cin >> input[i];
    }
    sort(input,input+N);
    dfs(0,0);

    return 0;
}
