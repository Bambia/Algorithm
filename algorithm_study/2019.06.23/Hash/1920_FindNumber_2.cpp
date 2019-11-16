#include <iostream>
#include <math.h>
using namespace std;
const int MAX_SIZE = 431341;

int hash_table[MAX_SIZE][20],hash_size[MAX_SIZE];
int data[100001];
int N,M,flag;

int hash_function(int value){
    int ret=0;
    while(value){
        ret = (ret + value*10) % MAX_SIZE;
        value /= 10;
    }
    return ret;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N;
    for(int i=0; i<N; i++) {
        int res,isIn =0;
        
        cin >> data[i];
        res = hash_function(abs(data[i]));
        for(int j=0; j<hash_size[res]; j++){
            if(hash_table[res][j] == data[i]){
                isIn =1;
                break;
            } 
            
        }
        if(!isIn) {
            hash_table[res][hash_size[res]] = data[i];
            hash_size[res]++;
            //cout <<"stored\n";
        }
    }

    cin >> M;
    for(int i=0; i<M; i++){
        int res,find;
        flag =0;
        cin >> find;
        res = hash_function(abs(find));
        
        for(int j=0; j<hash_size[res]; j++){
            if(hash_table[res][j] == find ){
                flag=1;
                break;
                //cout <<"find"<<find<<'\n';
            }  
            
        }

        if(flag) cout <<"1\n";
        else cout <<"0\n";
        
    }


    return 0;
}