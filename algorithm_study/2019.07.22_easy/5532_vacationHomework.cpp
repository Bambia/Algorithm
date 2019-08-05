#include <iostream>

using namespace std;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int L,A,B,C,D,fKorean=0,fMath=0,Day=0;

    cin >> L >> A >> B >> C >> D;

    while(1){
        Day++;
        fKorean += C;
        fMath += D;
        if(fKorean >= A && fMath >= B) break;
    }

    cout <<L-Day<<'\n';

    return 0;
}
