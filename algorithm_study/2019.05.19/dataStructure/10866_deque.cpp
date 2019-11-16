#include <iostream>
#include <deque>
#include <string>


using namespace std;

deque<int> DQ;
string cmd;
int tc;

int main(){
    cin >> tc;

    while(tc--){
        cin >> cmd;

        if(cmd == "push_front"){
            int f=0;
            cin >>f;
            DQ.push_front(f);
        }
        else if(cmd == "push_back"){
            int b=0;
            cin >>b;
            DQ.push_back(b);
        }
        else if(cmd == "pop_front"){
            if(DQ.empty()) cout << "-1\n";
            else {
                cout << DQ.front()<<'\n';
                DQ.pop_front();
            }
        }
        else if(cmd == "pop_back"){
            if(DQ.empty()) cout << "-1\n";
            else {
                cout << DQ.back()<<'\n';
                DQ.pop_back();
            }
        }
        else if(cmd == "size"){
            cout << DQ.size()<<'\n';
        }
        else if(cmd == "empty"){
            cout << DQ.empty()<<'\n';
        }
        else if(cmd == "front"){
            if(DQ.empty()) cout << "-1\n";
            else cout << DQ.front()<<'\n';
        }
        else if(cmd == "back"){
            if(DQ.empty()) cout << "-1\n";
            else cout << DQ.back()<<'\n';
        }
    }

    return 0;

}