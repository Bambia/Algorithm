#include <iostream>
#include <stack>
#include <string>


using namespace std;

int main(void){
     ios::sync_with_stdio(0);
     cin.tie(0);
    int n,a;
    string str;
    stack<int> S;
    cin>> n;
    while(n--){
        cin >> str; 
        
        if(str =="push"){
            
            cin >> a;
            S.push(a);     
        }
        else if(str =="pop"){
            if(S.empty()) cout << -1<<'\n';
            else {
                cout << S.top()<<'\n';
                S.pop();
            }
        }
        else if(str =="top"){
            if(S.empty()) cout << -1<<'\n';
            else cout << S.top()<<'\n';
        }
        else if(str =="size"){
            cout <<S.size()<<'\n';
        }
        else if(str =="empty"){
            cout << (int)S.empty()<<'\n';
            
        }
        else{

        }
    }    

    return 0;
}

