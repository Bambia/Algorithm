#include <iostream>
#include <algorithm>

using namespace std;

struct Point{
    int x;
    int y;
};

int N=0;
const int MAX = 100001;
Point cordinate[MAX]={0,};

bool cmp(const Point &p1, const Point &p2){
    if(p1.y<p2.y){
        return true;
    }
    else if(p1.y==p2.y){
        if(p1.x<p2.x){
            return true;
        }
    }
    return false;
}
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    
    cin >> N;

    for(int i=0; i<N; i++){
        cin >> cordinate[i].x >> cordinate[i].y;
    }

    sort(cordinate,cordinate+N,cmp);
    for(int i=0; i<N; i++){
        cout << cordinate[i].x<<' '<< cordinate[i].y;
        cout <<'\n';
    }
    return 0;
}