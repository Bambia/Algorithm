#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

struct person{
    string name;
    int MATH;
    int ENG;
    int KOR;
};

person p[100000];
int N;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> N;

    for(int i=0; i<N; i++) {
        cin >> p[i].name >> p[i].KOR >> p[i].ENG >> p[i].MATH; 
    }

    sort(p,p+N, [](const struct person &l, const struct person &r){
        if(l.KOR == r.KOR){
            if(l.ENG == r.ENG){
                if(l.MATH == r.MATH){
                    return l.name < r.name;
                }
                else return l.MATH > r.MATH;
            }
            else return l.ENG < r.ENG;
        } 
        else return l.KOR > r.KOR;
    });

    for(int i=0; i<N; i++) cout << p[i].name<<'\n'; 

    return 0;

}