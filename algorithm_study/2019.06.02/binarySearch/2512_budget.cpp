#include <iostream>
using namespace std;

typedef long long ll;
int rural[10000];
int N,budget;
int res,ret;
bool checkNum1Condition(){
    ll temp=0;
    for(int i =0; i<N; i++){    
        temp += rural[i]; 
        if(ret< rural[i]) ret =rural[i];
    }
    //cout <<"max rural bedget:\n"<<ret;
    if(temp <= budget ) {
        res = ret;
        //cout <<"budget: " <<budget <<"max: "<<res<<'\n';   
        return true;
    }
    else return false;

}
bool checkNum2Condition(int v){
    long long temp=0;
    //cout <<"v:"<<v<<" temp:";
    for(int i =0; i<N; i++){
        if(rural[i]< v) temp += rural[i];
        else temp += v;
        //cout <<temp <<' ';
    }
    //cout <<'\n';
    if(temp <= budget ) {
        //cout <<"budget: " <<budget <<"cal: "<<temp<<'\n';    
        return true;
    }
    else return false;
}
void biniary_sarch(){
    int l=0,r =1e9;
    while(l<r){
        
        int mid = (l+r+1)/2;
        if(checkNum2Condition(mid)) l = mid;
        else r = mid -1;
        //cout <<"mid:" <<mid <<"l:" <<l <<"r:"<<r<<'\n';
    }
    //cout <<"find max = "<<l<<'\n';
    res =l;
}
int main(){
    cin >> N;
    for(int i = 0; i<N; i++) cin >> rural[i];
    cin >> budget;
    if(!checkNum1Condition()) biniary_sarch();
    cout << res <<'\n';

    return 0;
}