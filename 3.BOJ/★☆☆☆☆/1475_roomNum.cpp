#include <iostream>

using namespace std;
int num[10];
int main(void){
    int n,maxNum=0;
    float a;
    cin >>n;
    
    while(1){
        num[n%10]++;
        if((n/10)==0) break;
        n=n/10;
    }
    a=(num[6]+num[9])/2.0;
    num[6] =(int)(a+0.5);

    for(int i=0; i<9; i++){
        if(maxNum<num[i]){
            maxNum = num[i];
        }
    }

    cout <<maxNum;

    return 0;
}