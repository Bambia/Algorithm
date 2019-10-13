#include <iostream>
#include <queue>
using namespace std;

priority_queue <int, vector<int>, greater<int> > pq;

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
                cout << pq.top()<<'\n';
                pq.pop();
            }
        }
        else pq.push(input);
    }
    return 0;
}