#include <iostream>
using namespace std;


int N,tc,cnt;

void func(int cur){
    if(cur == N){ 
        cnt++;
        //cout <<"find one way\n";
        return;
        
    }
    else if(cur > N) return ;
    func(cur+1);
    func(cur+2);
    func(cur+3);

}
int main(){
    cin >> tc;
    while(tc--){
        cin >> N;
        cnt = 0;
        func(0);
        cout <<cnt<<'\n';
    }
        
    
    return 0;
}