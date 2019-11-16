#include <iostream>
#include <stack>

using namespace std;

stack <int> s;
int main(void){
    int input;

    
    
    cin >> input;
    s.push(input);
    cout<< s.top();
    s.pop();
    cout<< s.top();
    /*
    cin >> input;
    s.push(input);

    cout << s.top()<< "\n";
    s.pop();
    cout << s.top();
    */
    return 0;
}
