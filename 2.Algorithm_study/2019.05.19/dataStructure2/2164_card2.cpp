#include <iostream>
#include <queue>
using namespace std;

queue <int> q;
int N, ans;
int main(void){

    cin >> N;

    for(int i=0; i<N; i++) q.push(i+1);

    while(q.size()>1){
        q.pop();
        ans = q.front();
        q.pop();
        q.push(ans);
    }
    ans = q.front();
    cout <<ans ;
    return 0;
}