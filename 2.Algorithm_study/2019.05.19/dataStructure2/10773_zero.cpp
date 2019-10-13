#include <iostream>
#include <stack>

using namespace std;
int N;
int main(void){
    ios:: sync_with_stdio(false);
    cin.tie(NULL);

    stack <int > st;

    cin >> N;
    int a=0,sum=0;
    while(N--){
        cin >> a;
        if(a== 0) st.pop();
        else st.push(a);
    }
    while(!st.empty()){
        sum += st.top();
        st.pop(); 
    }
    cout << sum;

}