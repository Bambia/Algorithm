#include <iostream>
#include <algorithm>  
using namespace std;   

int N;
int A[50],B[50];
int visited[50];
int main(){
    cin >> N;
    for(int i =0; i<N; i++){
        cin >> A[i];
        B[i]=A[i]; 
    }

    sort(B,B+N);
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(A[i]== B[j] && visited[j]== 0){
                cout << j<<' ';
                visited[j]=1;
                break;
            }
        }
    }

    return 0;
}