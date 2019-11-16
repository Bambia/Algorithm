#include <iostream>

using namespace std;
char map[51][51];
int N;
int ans,ans2;
int check(){
    int res1=1,cnt1=1,cnt2=1;
    for(int i =0; i<N; i++){
        for(int j=0; j<N; j++){
           if( map[i][j] ==map[i][j+1]) cnt1++;
           else {
               if(cnt1 > res1) res1 = cnt1;
               cnt1 =1;
           }
        }
        if(cnt1 > res1){
            res1 = cnt1;
            cnt1 =1;
        }
        for(int j=0; j<N; j++){
            if( map[j][i] ==map[j+1][i]) cnt2++;
            else {
                if(cnt2 > res1) res1 = cnt2;
                cnt2 =1;
            }
        }
        if(cnt2 > res1){
            res1 = cnt2;
            cnt2 =1;
        }

    }
    return res1;
}
int main(void){

    cin >> N;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin >> map[i][j];
        }
    }

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            char temp,ans2=0;
            temp = map[i][j];
            map[i][j] = map[i][j+1];
            map[i][j+1]= temp;
            ans2 = check();
            if(ans<ans2) ans = ans2;

            temp = map[i][j];
            map[i][j] = map[i][j+1];
            map[i][j+1]= temp;
        }
        for(int j=0; j<N; j++){
            char temp;
            temp = map[j][i];
            map[j][i] = map[j+1][i];
            map[j+1][i]= temp;
            ans2 = check();
            if(ans<ans2) ans = ans2;
            temp = map[j][i];
            map[j][i] = map[j+1][i];
            map[j+1][i]= temp;
        }
    }
    cout << ans;
    return 0;   
}