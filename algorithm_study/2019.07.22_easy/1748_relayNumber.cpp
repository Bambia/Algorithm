#include <iostream>

using namespace std;
int ans,N;

int square(int num){
    int ret = 1;
    for(int i=0; i<num; i++) ret *= 10;
    //cout <<"num:"<<num <<" ret:"<< ret<<'\n';
    return ret;
}
int getNumOfDigit(int N){
        int cnt =0;
        if(N<10) return 1;
        int cal =N/100;
        cnt++;
        while(cal){ 
               if( cal != 0){
                       cnt ++;
               }
               cal = cal/10; 
        }
        cnt ++;

        return cnt;
}
void func(int N){
        int cal =0,sum =0;
        int digit = getNumOfDigit(N);
        //cout <<"digit:"<< digit <<'\n';
        for(int i=0; i<digit-1; i++){
                sum = ((i+1)*9*square(i));
                //cout <<"sum:"<<sum <<'\n';
                ans += sum;
        }

        cal = N - square(digit-1) +1;
        cal *= digit;
        ans += cal;

}
int main(){
        ios::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        cin >> N;
        // 1  2                3  
        // 9 10~99= (89+1)*2 + 100~999 = (20+1)*3
                   
        func(N);
        cout << ans;
        return 0;
}
