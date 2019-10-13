#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <queue>
using namespace std;

int main(){
    int N,K;
    int pocket[300001];
    vector <pair<int,int> > jewelry;
    priority_queue <int> pq;

    long long sumPrice = 0;

    cin >> N >> K;
    for(int i=0; i<N; i++) {
        pair <int,int> a;
        cin >> a.first >> a.second;
        jewelry.push_back(a);
    }
    for(int i=0; i<K; i++) cin >> pocket[i];
    sort(jewelry.begin() , jewelry.end() ,[](const pair<int,int> &l,const pair<int,int> &r){
        return l.first < r.first;  
    });
    sort(pocket,pocket+K );

    //for(int i=0; i<N; i++) cout << jewelry[i].first<<' '<< jewelry[i].second<<'\n';
    //cout <<'\n';
    //for(int i=0; i<K; i++) cout << pocket[i] <<'\n';
    int dir=0;
    for(int i=0; i<K; i++){
        
        while(pocket[i] >= jewelry[dir].first && dir < N ){
            pq.push(jewelry[dir].second);
            dir++;
        }
        
        if(!pq.empty()) {
            sumPrice += pq.top();
            //cout <<pq.top() <<' ';
            pq.pop();
        }
    }
    //cout <<'\n';

    cout <<sumPrice <<'\n';

    return 0;
}