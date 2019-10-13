#include <iostream>
using namespace std;
int N,M,K,con;

int main(){
    cin >> N>> M >> K;

    while(N >= 2 && M >= 1 ){
        N -= 2;
        M -= 1;
        con++;
    }

    while(K>0){
        if(N >0 ) {
            N -= 1;
            K -= 1;
        }
        else if(M >0 ) {
            M -= 1;
            K -= 1;
        }
        else {
            con --;
            N += 2;
            M += 1;
        }
    }

    cout <<con <<'\n';

    return 0;
}