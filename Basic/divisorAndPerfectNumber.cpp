#include <iostream>

using namespace std;

int main(){
    int N = 4,P=0,D=0,cnt=0,sum =0;
    cout << "start \n";
    while(N<=10000){
        D= int(N/2);
        sum =0; 
        
        for(int i =1; i <=D; i++){
            if(N%i == 0) {
                sum +=i;
                //cout <<"find number :"<<i<<'\n';
            }
        }

        if(sum == N) {
            cout << sum<<"\n";
            cnt++;
        } 
        N++;
    }
    cout << cnt;
    return 0;
}