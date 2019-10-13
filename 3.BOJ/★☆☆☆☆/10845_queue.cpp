#include <iostream>
#include <queue>
#include <string>

using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tc;
    string str;
    queue <int> Q;
    cin >> tc;
    while(tc--){
        cin >> str;
        if(str =="push"){
            int a;
            cin >> a;
            Q.push(a);

        }
        else if(str =="pop"){
           if(Q.empty()) cout << -1 <<'\n';
           else {
               cout << Q.front()<<'\n';
               Q.pop();  
           }   
        }
        else if(str =="size"){
            cout << Q.size()<<'\n';
        }
        else if(str =="empty"){
            cout << (int)Q.empty()<<'\n';
        }
        else if(str =="front"){
           if(Q.empty()) cout << -1 <<'\n';
           else cout << Q.front()<<'\n';
        }
        else if(str =="back"){
           if(Q.empty()) cout << -1 <<'\n';
           else cout << Q.back()<<'\n';
        }
    }
    
    return 0;
}