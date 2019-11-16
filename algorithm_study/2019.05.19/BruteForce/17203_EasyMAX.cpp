#include <iostream>

using namespace std;
int A[1000];
int N,Q,X,Y;

int main(void){
    
    cin >> N >> Q;
    for(int i=1; i<N+1; i++){
        cin >> A[i];
    }
    while(Q--){
        int sum=0;
        cin >> X >> Y;
        if(X==Y) {
            cout << "0\n";
            continue;
        }
        for(int i=X; i<Y; i++){
            sum += abs(A[i+1]-A[i]);
        }
        cout << sum <<'\n';
    
    }
    return 0;
}