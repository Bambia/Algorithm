#include <iostream>
#include <string>
#include <stack>


using namespace std;

int f,cnt,a;
char temp;
string st,bomb;
stack <char> s1,s2;

int main(void){

    cin >> st >> bomb;

    for(int i=0; i<st.length(); i++){
        s1.push(st[i]);
        cout <<s1.top();
    }
    cout <<'\n';
    while(1){
        
        for(int i = bomb.length()-1; i>0; i--){
            stack <char> b;
            temp = s1.top();
            s1.pop();
            
            if(temp == bomb[i]){
                b.push(temp);
                cout << temp ;
            }
            else {
                for(int j=0; j<b.size(); j++){
                    f = b.top();
                    b.pop();
                    s2.push(f);                               
                }
            }
            //if(b.size() == bomb.length()) fun=1; 
            

        }
        if(s1.empty()) {
            for(int i=0; i<s2.size(); i++){
                int a = s2.top();
                s1.push(a);
            }
        }
        cout <<'\n';
        //if(fun) a =1;
        //else a =0;
         

    }
    return 0;
}