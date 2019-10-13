#include <iostream>
#include <stack>
using namespace std;

stack <char > st;
int N,fail;
char data;
int main(){
    int test_case =10;

    for(int tc =1; tc<=test_case; tc++){
        
        fail = 0;
        while(!st.empty()) st.pop();

        cin >> N;
        for(int i=0; i<N; i++){
            cin >> data;
            if(data == '('||data =='<'||data == '{'||data == '[') {
                st.push(data);
                //cout <<"push\n";
            }
            else{
                if(st.top() == '(' && data == ')') {
                    st.pop();
                }
                else if(st.top() == '<' && data == '>'){
                    st.pop();
                }
                else if(st.top() == '{' && data == '}'){
                    st.pop();
                }
                else if(st.top() == '[' && data == ']'){
                    st.pop();
                    //cout <<"pop\n";
                }
                else fail = 1;
            }
        }
        cout << "#"<<tc <<' '<< !fail<<'\n';
    }
    return 0;
}