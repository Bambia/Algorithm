#include <iostream>
using namespace std;

int coin[6] = {500,100,50,10,5,1};
int value,exchange,cnt;

int main(){
    cin >> value;
    exchange = 1000 -value;
    //cout <<"initical exchange money: "<<exchange<<'\n';
    for(int i=0; i<6; i++){
        while(1){
            if( exchange >= coin[i] ) {
                exchange -= coin[i];
                cnt++;
                //cout <<exchange<<'\n';
            }
            else break;
        }
    } 

    cout <<cnt<<'\n';

    return 0;
}