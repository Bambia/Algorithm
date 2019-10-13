#include <iostream>

using namespace std;

int numArr[4]={0,};
char chArr[3]={0,};
int ans[3]={0,};
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> numArr[0] >> chArr[0] >> numArr[1] >> chArr[1] >> numArr[2];

    //cout << numArr[0] << chArr[0] << numArr[1] << chArr[1] << numArr[2];
for(int i=0; i<2; i++){    
    if(chArr[i]=='+') ans[i]=numArr[i]+numArr[i+1];
    else if(chArr[i]=='-') ans[i]=numArr[i]-numArr[i+1];
    else if(chArr[i]=='*') ans[i]=numArr[i]*numArr[i+1];
    else if(chArr[i]=='/') ans[i]=numArr[i]/numArr[i+1];
}
    if(chArr[1]=='+') ans[0]=ans[0]+numArr[2];
    else if(chArr[1]=='-') ans[0]=ans[0]-numArr[2];
    else if(chArr[1]=='*') ans[0]=ans[0]*numArr[2];
    else if(chArr[1]=='/') ans[0]=ans[0]/numArr[2];
    
    if(chArr[0]=='+') ans[1]=numArr[0]+ans[1];
    else if(chArr[0]=='-') ans[1]=numArr[0]-ans[1];
    else if(chArr[0]=='*') ans[1]=numArr[0]*ans[1];
    else if(chArr[0]=='/') ans[1]=numArr[0]/ans[1];

    if(ans[0]<ans[1]) cout << ans[0] <<'\n' <<ans[1];
    else cout << ans[1] <<'\n' <<ans[0];

    return 0;
}
