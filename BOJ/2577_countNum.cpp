#include <iostream>


using namespace std;
int num[10];

int main(void){
    int a,b,c,ans;
    cin >>a >>b>>c;
    ans=a*b*c;

    while(ans!=0){
          num[ans%10]++;
          ans=ans/10;
    }
    for(int i=0; i<10; i++){
     cout <<num[i]<<'\n';
    }

}