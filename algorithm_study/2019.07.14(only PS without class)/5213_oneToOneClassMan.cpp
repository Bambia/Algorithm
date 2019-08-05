#include <iostream>
using namespace std;

const int MX = 1000000;

int dat[MX];
int pre[MX];
int nxt[MX];
int size=0;
int unused=0;

void insert(int idx, int dat){
    dat[unused] = dat;
    pre[unused] = idx;
    nxt[unused] = nxt[idx];

    if(nxt[idx] != -1) pre[nxt[idx]] = unused;
    nxt[idx] = unused;
    unused++;
    size++; 

    return;
}

void erase(int idx){
    nxt[pre[idx]] = nxt[idx];
    if(nxt[idx] != -1 )pre[nxt[idx]] = pre[idx];
    
    return ;

}
int main(){


    return 0;
}