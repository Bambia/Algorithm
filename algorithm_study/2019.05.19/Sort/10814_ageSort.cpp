#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

struct person{
    int age;
    string name;
    int num;
};
person p[100000];
int N,K;
string name[100000];
int age[100000];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> N;
    for(int i=0; i<N; i++) {
        cin >> p[i].age >> p[i].name;
        p[i].num = i;
    }
    sort(p,p+N, [](const struct person &l, const struct person &r){
        if(l.age == r.age) return l.num < r.num;
        else return l.age < r.age;
    });

    for(int i=0; i<N; i++) {
        cout << p[i].age<<" "<< p[i].name<<'\n';
    }
    return 0;

}