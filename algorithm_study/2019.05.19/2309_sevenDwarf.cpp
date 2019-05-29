#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector <int> v,dwarf;
int sum,flag=0;
void func(int cnt){
    if(v.size() == 7 && !flag){
        for(int i=0; i<v.size(); i++) sum += dwarf[v[i]];
        //cout <<"sum :"<<sum<<'\n';
        if(sum == 100) {
            for(int i=0; i<v.size(); i++) cout << dwarf[v[i]] <<'\n'; 
            flag = 1;
        }  
        sum = 0;
        return;
    }
    for(int i=cnt; i<9; i++){
        v.push_back(i);
        func(i+1);
        v.pop_back();
    }
}
int main(void){
    for(int i=0; i<9; i++){
        int a=0;
        cin >> a;
        dwarf.push_back(a);        
    }
    sort( dwarf.begin(), dwarf.end() );
    func(0);
    return 0;
}