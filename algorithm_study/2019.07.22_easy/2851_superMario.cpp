#include <iostream>

using namespace std;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int totalScore =0,score[10]={0,},ans=0;

    for(int i=0; i<10; i++){
        cin >> score[i];
    }
    for(int i=0; i<10; i++){
        totalScore += score[i];
        if(totalScore > 100) {
            int cmp = totalScore - score[i];
            if( (totalScore-100) - (100-cmp) <= 0) ans = totalScore;
            else if((totalScore-100) - (100-cmp) > 0) ans = cmp;
            break;
        }
        else ans = totalScore;
    }
    cout <<ans <<'\n';

    return 0;
}
