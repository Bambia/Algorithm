#include <iostream>

using namespace std;
int N,ans;
int corridor[201];
void init(){
    N =0;
    ans = 0;
    for(int i=0; i<=200; i++) corridor[i] =0;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int Test_Case;

    cin >> Test_Case;
    for(int tc =0; tc< Test_Case; tc++){
        
        init();
        cin >> N;
        for(int i= 0; i<N; i++){
            int From,To;
            cin >> From >> To;

            if(From > To) {int t = From; From = To; To = t;}
            if(From %2 != 0) From++;
            From /= 2;

            if(To %2 != 0) To++;
            To /= 2;
            for(int i = From; i<=To; i++ ) {
                corridor[i]++;
            } 

        }
        
        for(int i=0; i<200; i++){
            if(ans < corridor[i]) ans = corridor[i];
        }

        cout << "#"<<tc+1<<' '<<ans<<'\n';

    }
    return 0;
}