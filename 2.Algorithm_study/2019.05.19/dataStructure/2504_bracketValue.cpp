#include <iostream>
#include <string>
#include <stack>


using namespace std;
stack <char> s;
string st;
int temp[30];
int cnt,sum;



int main(void){
    cin >> st;

    int temp =1;
    for(int i=0; i<st.length(); i++){
        if(st[i] == '('){
            temp *=2;
            s.push(st[i]);
        }
        else if(st[i] == '['){
            temp*=3;
            s.push(st[i]);
        }
        else if(st[i] ==')'){
            if(st[i-1] == '(' ) sum += temp;
            if(s.empty()) return !printf("0");
            if(s.top() =='(') s.pop();
            
            temp /= 2;
        }   
        else if(st[i]==']'){
            if(st[i-1] == '[' )  sum += temp;         
            if(s.empty()) return !printf("0");
            if(s.top() =='[') s.pop();
            
            temp /= 3;
        }

    }
    
    if(!s.empty()) cout << "0";
    else cout <<sum ;
    return 0;
}