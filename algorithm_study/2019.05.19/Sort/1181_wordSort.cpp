#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
string s[20000];
int N;

bool comp(string a, string b){
    if(a.length() == b.length()) {
        return a<b;
    }
    else return a.length() <b.length();
}

int main(){
    cin >> N;
    for(int i = 0; i< N; i++){
        cin >> s[i];
    }
    
    sort(s,s+N,comp);

    for(int i = 0; i< N; i++){
        
        if(s[i]==s[i+1]) continue;

        cout << s[i]<<'\n';
    }
    return 0;
}