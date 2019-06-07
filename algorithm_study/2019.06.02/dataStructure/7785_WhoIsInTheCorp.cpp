#include <iostream>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

int N;
string name,log;

map <string, int, greater<string> > m;
map <string, int, greater<string> >::iterator it;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for(int i =0; i < N; i++){
        cin >> name >> log; 

        if(log == "enter") m[name] = 1;
        else if(log == "leave") m[name] = 0;
    }


    for(it = m.begin(); it !=m.end(); it++){
        if(it->second == 1)cout << it->first<<'\n';
    }

    return 0;
}