/*
1부터 100까지의 수 중에 가장 큰 소수를 찾아라
*/

#include <iostream>
#include <math.h>

using namespace std;

int main(){
    int P=2,M=0,N=3;

    while(N <=100){
        M = (int)sqrt((double)N);
        //cout << M<<'\n';
        for(int i= 2; i<=M; i++){
            if(N%i == 0 ) break; //나눠지는 수가 있으니까 소수가 아니지

            if(i==M) { //나눠지는 수가 없으니까 최대 소수로 저장
                P = N;
                cout <<P <<'\n';
            }
        }
        N++;
        
    }
    return 0;
}