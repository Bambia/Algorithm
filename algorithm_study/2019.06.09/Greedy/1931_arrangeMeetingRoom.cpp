#include <iostream>
#include <algorithm>

using namespace std;

struct TIME{
    int S,E;
};

TIME meeting[100001];
int n,cur,cnt;

int main(){
    cin >> n;
    for(int i=0; i<n; i++) cin >> meeting[i].S >> meeting[i].E;

    sort(meeting,meeting+n,[](const TIME &l ,const TIME &r){
        if(l.E == r.E ) return l.S < r.S;
        return l.E < r.E;
    });

    //for(int i=0; i<n; i++) cout << meeting[i].S <<' '<< meeting[i].E<<'\n';
    

    for(int j=0; j<n; j++){
        if( cur <= meeting[j].S ) {
            //cout <<"find meeting:"<< meeting[j].S <<" "<<meeting[j].E<<'\n';
            cur = meeting[j].E;    
            cnt++;
        }
    }
    


    cout <<cnt <<'\n';
    return 0;
}