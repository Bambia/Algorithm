#include <iostream>
using namespace std;

const int MAX_SIZE = 1e5+3;

int pos[MAX_SIZE];
int light[MAX_SIZE];
int N,M,ans,Hleft[MAX_SIZE],Hright[MAX_SIZE];
void init(){
    for(int i=0; i<M; i++) {
        Hleft[i] =0;
        Hright[i]= 0;
    }
}
bool check(int h){
    init();
    for(int i=0; i<M; i++){
        if(i==0) {
            if(0 >= (pos[i]-h) ){
                Hleft[i] =1;
                //cout <<"left:"<<i <<" clear ";
            } 
            if(M ==1){
                if(N<= pos[i]+h) {
                    Hright[i] = 1;
                    //cout <<"right"<<i <<" clear ";
                }
            }
            else if((pos[i]+h)>=(pos[i+1]-h)){
                Hright[i] =1;
                //cout <<"right:"<<i <<" clear ";
            } 
            //cout <<'\n';
        }
        else if(i==M-1){
            if(N <= (pos[i]+h) ){
                Hright[i] =1;
                //cout <<"right:"<<i <<" clear ";
            } 
            if((pos[i]-h)<=(pos[i-1]+h)) {
                Hleft[i] = 1;
                //cout <<"left:"<<i <<" clear ";
            }
            //cout <<'\n';
        }
        else{
            if((pos[i]+h)>=(pos[i+1]-h)){
                Hright[i]  =1;
                //cout <<"right:"<<i <<" clear ";
            } //오른쪽
            if((pos[i]-h)<=(pos[i-1]+h)) {
                Hleft[i] =1;
                //cout <<"left:"<<i <<" clear ";
            } // 왼쪽 
            //cout <<'\n';
        }
    }
    for(int i=0; i<M; i++){
        if(Hleft[i]==0) return false;
        if(Hright[i]==0) return false;
    }
    //cout <<"return true\n";
    ans = h;
    return true;
    
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> M;
    for(int i =0; i< M; i++) cin >> pos[i];
    int l=0, r= MAX_SIZE;
    while(l<r){
        int mid = (l+r+1)/2;
        //cout <<"mid:"<<mid <<"\n";
        if(!check(mid)) l = mid;
        else r = mid-1;
    }
    cout <<ans;
    return 0;
}  