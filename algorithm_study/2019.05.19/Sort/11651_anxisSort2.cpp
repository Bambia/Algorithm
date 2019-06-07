#include <iostream>
#include <algorithm>
#include <utility>
using namespace std;

pair <int, int> p[100000];

int N;

int main(void){
    cin >> N;
    for(int i=0; i<N; i++){
        cin >> p[i].first >> p[i].second;
    }

    sort(p,p+N,[](const pair<int,int> &l,const pair<int,int> &r){
        if(l.second == r.second) return l.first<r.first;
        else return l.second<r.second;
    });

    for(int i=0; i<N; i++){
        cout << p[i].first <<' '<< p[i].second<<'\n';
    }

    return 0;
}