#include <iostream>

using namespace std;

int main(){
    int N=0;
    int result=10000001;
    int ans = 10000000;
    int no=0;
    cin >> N;
    //cout <<ans <<'\n';
    for(int i=1; i<N+1; i++){
        int d=1,sum=0;
        //cout <<"i = " <<i <<' ';
        while( (i/d)!= 0){ // 각 자리수 합
            sum +=(i/d)%10;
            //cout << sum <<' ';
            d *= 10;
        }
        //cout <<'\n';
        if( (i+sum)== N) {
           result = i;
           //cout <<"find value i= "<<result <<" sum= "<<sum<<'\n';
        }
        if(result < ans) {
            ans = result;
            no =1;
            //cout <<"find minimum " <<ans <<'\n';
        }
    }

    if(!no) cout <<"0"<<'\n';
    else cout <<ans <<'\n';
    return 0;
}