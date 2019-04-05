#include <iostream>

using namespace std;
int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int e,s,m,year=0;
    int cmp_e=0,cmp_s=0,cmp_m=0;
    cin >> e >>s >> m ;
    while(!((cmp_e==e) && (cmp_s==s) && (cmp_m==m))){
        year++;
        cmp_e++;
        cmp_s++;
        cmp_m++;
        if(cmp_e>15) cmp_e =1;
        if(cmp_s>28) cmp_s =1;
        if(cmp_m>19) cmp_m =1;
    }
    cout << year ;


    return 0;
}