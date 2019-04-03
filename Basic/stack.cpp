#include <iostream>

void push(int val);
int top(void);
void pop();
const int MAX  = 10000007;
int dat[MAX];
int pos;

using namespace std;

int main(void){
    int input;

    cin >> input;
    push(input);
    cin >> input;
    push(input);

    cout << top();
    pop();
    cout << top();

    return 0;
}

void push(int val){
    dat[pos++]= val;
}

int top(void){
    return dat[pos-1];
}

void pop(){
    pos--;
}