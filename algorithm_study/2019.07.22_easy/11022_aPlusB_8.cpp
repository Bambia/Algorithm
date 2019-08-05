#include <iostream>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int A,B,tc,cnt=0;
    cin >> tc;
    while(tc--){
        cnt++;
        cin >> A >> B;
        cout <<"Case #"<<cnt<<": " <<A<<" + "<<B<<" = "<<A+B<<'\n';
    }

    return 0;
}