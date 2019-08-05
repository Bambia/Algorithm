#include <iostream>
#include <cmath>
using namespace std;
const int MAX_SIZE = 2160563;

int data[500001];
int hashTable[MAX_SIZE][5];
int hashSize[MAX_SIZE];
int M,N;

int hash_func(int value){
    int ret=0;
    while(value){
        ret = (ret + value*8) % MAX_SIZE;
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
        int ret= 0,isInData=0;
        
        cin >> data[i];
        ret = hash_func(abs(data[i]));
        for(int j =0; j<hashSize[ret]; j++){
            if(hashTable[ret][hashSize[ret]] == data[i]  ){
                isInData = 1;
                break;
            }
            
        }
        if(!isInData) hashTable[ret][hashSize[ret]++] = data[i];
    }

    cin >> M;
    for(int i=0; i<M; i++){
        int ret=0,find=0,flag=0;
        cin >> find;
        ret = hash_func(abs(find));
        for(int j=0; j<hashSize[ret]; j++){
            if(hashTable[ret][j] == find) flag = 1;
        }
        if(flag) cout << "1 ";
        else cout <<"0 ";
    }
    return 0;
}