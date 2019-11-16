#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int n,num[10],ans,sum;
string str;

int main(){
    cin >>str;
    
    for(int i=0; i<str.length(); i++) {
        num[str[i]-'0']++;
        sum += str[i]-'0';
    }
    if( (num[0] == 0 ) || (sum % 3 != 0 ) ) cout <<"-1";
    else{
        for(int i=9; i>=0; i--) {
            for(int j=0; j<num[i]; j++) cout <<i;
            
        }
        cout <<'\n';
    }

    return 0;
}