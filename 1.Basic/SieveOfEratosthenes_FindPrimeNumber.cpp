#include <iostream>
using namespace std;
const int MAX = 3000000;
long long p[MAX],cnt,arr[2000000];

int main(){
    for(int i=2; i<MAX; i++){
        if(p[i] == 0) {
            arr[cnt++] = i;
            for(int j=i*2; j<MAX; j+=i){
                //cout <<j <<" ";
                p[j] = 1;
            }
            //cout <<'\n';
        }
        
    }

    cout <<arr[160000]<<'\n';
    return 0;
}