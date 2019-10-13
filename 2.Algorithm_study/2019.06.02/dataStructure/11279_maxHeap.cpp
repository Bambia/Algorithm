#include <iostream>
using namespace std;

int heap[500005];
int pos=1;

void swap(int *a, int *b){
    int temp=*a;
    *a = *b;
    *b = temp;
}

void push(int val){
    int cur = pos++; 
    heap[cur] = val;
    if(cur == 1) return;
    else {
        while(cur > 1){
            int next = cur /2;
            if(heap[cur] > heap[next]) swap(heap[cur],heap[next]);
            else return;
            cur =next;
        }
    }
}

int pop(){
    int ret = heap[1];
    int left_c,right_c,par=1;
    heap[1] =0;
    swap(heap[1], heap[pos-1]);

    while(par <= pos-1){
        left_c = par*2;
        right_c = par*2+1;

            if(heap[left_c] >= heap[right_c]) {
                if(heap[par]< heap[left_c]) {
                    swap(heap[par] ,heap[left_c]);
                    par = left_c;
                }
                else break;
            }
            else {
                if(heap[par]< heap[right_c]) {
                    swap(heap[par] ,heap[right_c]);
                    par = right_c;
                }
                else break;
            }
    
    }
    return ret;
}
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N=0,num=0;

    cin >>N;
 
    while(N--){
        cin >> num; 
        if(num == 0) {
            cout << pop() <<'\n'; 
                
        }
        else push(num);

    }

    return 0;
}
