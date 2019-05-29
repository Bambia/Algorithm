#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main(void){
    stack <char> s;
    string st;
    int no=0;
    int pos=0,min=0,tc;
    cin >> tc;

    
     while(tc--){   
        cin >> st;
        for(int i=0; i<st.size(); i++){
            s.push(st[i]);
        }
        
        no =0;
        pos =0;
        min =0;
        while(!s.empty()){
            if(s.top()== ')' ) pos ++;
            else if(s.top()== '(') min++;
            if(pos <min) {
                no= 1;
            }
            s.pop();
        }
        //cout << pos <<' '<< min;
        if(pos!=min) no =1;

        if(no) cout <<"NO\n";
        else cout << "YES\n";
        
     }

        

    return 0;
}