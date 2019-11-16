#include <iostream>
#include <map>
#include <string>
#include <stdlib.h>

using namespace std;
int M,N;
map <string, int> m;
string st;
string voca[100000];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    for(int i=1; i<=N; i++){
        cin >>st;
        m[st] = i;
        voca[i] = st;
    }
    for(int i=0; i<M; i++){
        cin >> st;
        if(st[0] >='0' && st[0]<= '9') cout << voca[stoi(st)] <<'\n';
        else cout << m[st] <<'\n';      
    }

   
    return 0;
}