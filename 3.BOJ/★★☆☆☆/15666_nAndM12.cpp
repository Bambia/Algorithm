#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N,M;
int a;
int arr[8];
int check[8];

vector <int> v;

void dfs(int pos,int index){
    if(pos ==M){
        for(int i=0; i<M; i++){
            cout << arr[i]<<' ';
        }
        cout <<'\n';

        return;
    }
    for(int i=index; i<v.size(); i++){
        
        arr[pos]=v[i];
        dfs(pos+1,i);
    }
}
int main(void){
    //ios::sync_with_stdio(false);
    //cin.tie(NULL);

    cin >> N >> M;
    for(int i=0; i<N; i++){
        cin >>a;
        if( find(v.begin(),v.end(),a) == v.end() ) v.push_back(a);
    }

    //cout <<"v:";
   // for(int i=0; i<v.size(); i++) cout << v[i]<<' ';
    sort(v.begin(),v.end());
   // cout <<'\n';
    //cout <<"v:";
    //for(int i=0; i<v.size(); i++) cout << v[i]<<' ';
    dfs(0,0);

    return 0;
}