#include <iostream>
#include <math.h>
using namespace std;
int N,K;
int A[10];
int B[10];
int check[10];

int main(){
    cin >> N >> K; 
    for(int i=0; i<N; i++) cin >> A[i];
    for(int i=0; i<K; i++) cin >> B[i];

    for(int i=0; i<N-1; i++){
        for(int j=i; j<N; j++){
            for(int l=0; l<K; l++){
                int sum=0,min=0;
                sum = A[i]+A[j];
                sum %= 360;
                if( sum == B[l]) check[l]= 1;
                min = abs(A[i]-A[j]);
                if( min == B[l]) check[l]= 1;
            }
            
        }
    }
    int no =0;
    for(int i=0; i<K; i++){
        if(check[i]==0) no =1;
        
    }
    if(no ==0) cout <<"YES";
    else cout <<"NO";   
    return 0;
}