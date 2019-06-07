#include <iostream>
#include <stack>
#include <vector>
#include <string>
using namespace std;
string input;
stack <int> s;
vector <int>v;
int result;
int main(){
    
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> input;

    for(int i=0; i<input.length(); i++){
        if( (input[i]=='(') && (input[i+1]==')') ){
            v.push_back(i);
            i++;
        } 
        else if(input[i]=='(') s.push(i);
        else if(input[i]==')') {
            int st=s.top();
            s.pop();
            int cnt= 0;
            for(int j=0; j<v.size(); j++){
                if(v[j]>st && v[j] <i) cnt++;
            }
            result += (cnt+1);
        }
    }
    cout << result; 
    return 0;
}