#include <iostream>

using namespace std;

int Div[3]= {0,};
int main(){
    int A,B,ans;
    cin >> A >> B;
    ans = A*B;
    for(int i =0; i<3; i++) {
        Div[i] = B%10;
        B /= 10;
    }

    for(int i=0; i<3; i++){
        cout << A*Div[i]<<'\n';
    }
    cout << ans <<'\n';
    
    return 0;
}