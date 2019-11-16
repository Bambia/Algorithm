#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int a;
int main(void){
    int tc;
    cin >> tc;
    while(tc--){
        queue <pair<int,int>> q;
        priority_queue <int> pq;

        int N,M,d=0,cnt=0;
        cin >> N >> M;
        for(int i=0; i<N; i++){
            cin >> a;
            q.push({a,i});
            pq.push(a); 
        }
        while(!q.empty()){
            int here = q.front().first;
            int num = q.front().second;
            q.pop();
            if(pq.top()== here){
                cnt++;
                pq.pop();
                if(M==num) break;
            }
            else q.push({here,num});
        }
        cout <<cnt <<'\n';
    }
    return 0;
}