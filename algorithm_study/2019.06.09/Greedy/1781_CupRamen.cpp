#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

struct SET{
    int dead,ramen;
};
int N,sum;
SET dongHo[200001];
priority_queue <int> pq;

int main(){
    cin >> N;
    for(int i=0; i<N; i++) cin >> dongHo[i].dead >> dongHo[i].ramen;

    sort(dongHo,dongHo+N,[](const SET &l, const SET &r){
        if(l.dead == r.dead) return l.ramen > r.ramen;
        else return l.dead < r.dead;
    });

    for(int i=0; i<N; i++){
        int comp = dongHo[i].dead;
        pq.push(-dongHo[i].ramen);

        while(comp < pq.size() ){
            pq.pop();
        }

    }
    while(!pq.empty()){
        sum -= pq.top();
        //cout <<pq.top()<<'\n';
        pq.pop();
    }

    cout <<sum <<'\n';
    return 0;
}