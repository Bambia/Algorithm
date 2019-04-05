#include <iostream>
#include <list>
#include <string>

using namespace std;

list <char> cl;

int main(void){
    int tc=0;
    string str;
    
    cin >> tc;
    while(tc--){
        cin >> str;
        auto t = cl.begin();

        for(int i=0; i<str.size(); i++){
            
            if(str[i]=='-'){
                if(t==cl.begin()) continue;
                t= cl.erase(--t);
                
            }
            else if(str[i]=='<'){
                if(t==cl.begin()) continue;
                t--;
                
            }
            else if(str[i]=='>'){
                if(t==cl.end()) continue;
                t++;
            }
            else{
                if(t==cl.end()) cl.push_back(str[i]); 
                else if(t==cl.begin()) cl.push_front(str[i]);
                else cl.insert(t,str[i]); 
            }


        }
        for(auto s:cl) cout << s;
        cout <<'\n';
        cl.clear();
    }
    return 0;
}

/*
 Another solution by using Stack library
*/

/*
#include <iostream>
#include <stack>
#include <string>
using namespace std;
int main() {
   stack<char> a, b;
   string s;
   int T;
   cin >> T;
   for (int j = 0; j < T; j++) {
      cin >> s;
      for (int i = 0; i < s.length(); i++) {
         if (s[i] == '<') {
            if (a.empty()) continue;
            else {
               b.push(a.top());
               a.pop();
            }
         }
         else if (s[i] == '>') {
            if (b.empty()) continue;
            else {
               a.push(b.top());
               b.pop();
            }
         }
         else if (s[i] == '-') {
            if (a.empty()) continue;
            else a.pop();
         }
         else {
            a.push(s[i]);

         }
      }
      if (!b.empty()) {
         while (!b.empty()) {
            a.push(b.top());
            b.pop();
         }
      }
      while (!a.empty()) {
         b.push(a.top());
         a.pop();
      }
      while (!b.empty()) {
         cout << b.top();
         b.pop();
      }
      cout << "\n";
   }
   return 0;
}
*/