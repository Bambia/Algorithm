#include <iostream>
#include <math.h>
using namespace std;
const int TableSize =431341;
int hashTable[TableSize][20],hashSize[TableSize];
int data[100001];

int hashFunction(int value){
    int ret =0;
    while(value){
        ret = (ret+value*10) % TableSize;
        value /= 10;
    }
    return ret;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N,M;

    cin >> N;
    for(int i=0; i<N; i++){
        int res,isIn =0;

        cin >> data[i];
        res = hashFunction(abs(data[i]));
        for(int j=0; j<hashSize[res]; j++){
            if(hashTable[res][j] == data[i]) isIn =1;
        }

        if(!isIn){
            hashTable[res][hashSize[res]] = data[i];
            hashSize[res]++;
        }
    }

    cin >> M;
    for(int i=0; i<M; i++){
        int res,find,flag=0;
        cin >> find;
        res = hashFunction(abs(find));

        for(int j= 0; j<hashSize[res]; j++){
            if(hashTable[res][j] == find) flag =1;

        }
        if(flag) cout <<"1"<<'\n';
        else cout <<"0\n";
    }
    return 0;
}