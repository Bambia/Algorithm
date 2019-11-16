#include <iostream>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int A,B,tc;
    char C;
    cin >> tc;
    while(tc--){
        cin >> A >>C>> B;
        cout << A+B<<'\n';
    }

    return 0;
}