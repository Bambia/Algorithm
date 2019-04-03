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