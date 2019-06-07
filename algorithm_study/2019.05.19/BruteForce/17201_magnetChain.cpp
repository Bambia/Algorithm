#include <iostream>
#include <string>

using namespace std;

string st;

int main(void){
    int num =0;
    int no =0;
    cin >>num >>st;
    for(int i=1; i<st.length()-2; i++) if(st[i] == st[i+1]) no =1; 
    if(no) cout <<"No";
    else cout <<"Yes";
    return 0;
}