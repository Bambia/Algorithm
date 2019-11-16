#include <iostream>

using namespace std;

void push(int val);
void pop();
int back();
int front();

const int MAX = 10000007;
int dat[MAX];
int tail;
int head;



int main(void){

    ios::sync_with_stdio(0);
    cin.tie(0);

    push(10);
    push(20);
    cout << front()<<'\n';
    cout << back()<<'\n';
    pop();
    cout << front()<<'\n';
    cout << back()<<'\n';

    return 0;
}

void push(int val){
    dat[tail++]= val;
}
void pop(){
    head++;
}
int back(){
    return dat[tail-1];
}

int front(){
    return dat[head];
}