#include <iostream>
#include <queue>
#include <math.h>
using namespace std;
struct a{
    int start;
    int end;
    int value;
    a(int value): start(0),end(0),value(value){

    }
};
struct cmp{
    bool operator()(a l,a r){
        if(abs(l.value)==abs(r.value) ){
            if(l.value>r.value ) return true;
            else return false;
        }
        else if( abs(l.value)>abs(r.value) ) return true;
        else return false;

    }
};

priority_queue <a, vector<a>, cmp > pq;

int N,input;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    for(int i=0; i<N; i++) {
        cin >> input;
        if(input == 0 ) {
            if(pq.empty()) cout <<"0\n";
            else {
                cout << pq.top().value<<'\n';
                pq.pop();
            }
        }
        else pq.push(a(input));
    }
    return 0;
}