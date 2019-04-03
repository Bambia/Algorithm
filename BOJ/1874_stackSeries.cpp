#include <iostream>
#include <stack>
#include <vector>
#include <queue>
#include <string>

using namespace std;
char str[200000];
int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m,b,j=0,i=0,x=0,no=1;
    vector <int> V;
    vector <int> num;
    stack <int> S;
    
    cin>>n;
    m=n;
    while(n--){
    
        cin >> b;
        V.push_back(b);
        num.push_back(++x);
        
        
    }
    /*
    for(int a=0; a<m; a++){
            cout << V[a] <<' ';
    }
    cout <<'\n';
    for(int a=0; a<m; a++){
            cout << num[a] <<' ';
            
    }*/
    
    x=0;
    for(int a=0; a<m; a++){
        
        S.push(num[x++]);
        str[j++]='+';

            while((!S.empty())&&(V[i]==S.top())){
                i++;
                S.pop();
                str[j++]='-';
            }
    
    }

    if(!S.empty()) cout << "NO";
    else {
        for(int a=0; a<j; a++){
            cout << str[a] <<'\n';
        }
    }
    return 0;
}