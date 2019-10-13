#include<iostream>
#include <map>
#include <string>

using namespace std;
int tc,n;
int sum;
map <string, int> m;
map <string, int>::iterator it;

string name,category;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> tc;
    
    while(tc--){
        sum =1;
        m.clear();
        cin >> n;
        for(int i =0; i<n; i++){
            cin >> name >> category;
            m[category]++;

        }
        for(it=m.begin(); it!=m.end(); it++){
            sum*=(it->second+1);   
        }

        cout <<sum-1<<'\n';

    }    
    return 0;
}