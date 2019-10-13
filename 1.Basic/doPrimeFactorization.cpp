/*
1000이하의 수를 입력 받아서 소인수 분해를 하는 코드 ~

*/
#include <iostream>
#include <math.h>

using namespace std;

int p[20];

int main(){
    int N,cnt=0;
    cin >> N;
    do{
        if(N>=2){
        int i=2;    
            for(; i<=N; i++) if(N%i == 0) break;
            p[cnt] = i;
            cnt ++;
            N/= i;
        }
        else return 0; 
    }
    while(N!=1);
        
    if(cnt ==1) {
        cout << "prime number\n";  
    }
    else {
        
        for(int i =0; i<cnt-1; i++){
            cout <<p[i]<<"*";
        }
        cout <<p[cnt-1];
    
    }
    
    return 0;
}