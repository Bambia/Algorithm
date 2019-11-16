#include <iostream>
#include <string>
#include <map>

using namespace std;
const int MAX_SIZE = 1e6+5; 
int tc,F,p[MAX_SIZE],ans[MAX_SIZE];

string P1,P2;

int find(int c){
    if(p[c] == -1) return c;
    else return p[c] = find(p[c]);
}

bool Marge(int u,int v){
    v = find(v);
    u = find(u);
    
    if(v != u){
        p[u] = v;
        ans[v] += ans[u];
        //cout <<"ans[v]:"<<ans[v] <<" ans[u]"<<ans[u] <<"\n";
        ans[u] = 1;
    }
    cout <<ans[v] <<'\n';

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> tc;

    while(tc--){
        int cnt =1;

        map <string, int> m;
        cin >> F;
        for(int i =0; i< (2*F +1) ; i++){
            ans[i] =1;
            p[i] = -1;
            
        }
        for(int i=0; i<F; i++){
            cin >> P1 >> P2;
            if (m.count(P1) == 0 ) m[P1] = cnt ++;
            
            if (m.count(P2) == 0) m[P2] = cnt ++;
            
            Marge(m[P1],m[P2]);
            //cout << ans[m[P1]] <<'\n';
        }
        
    }
    return 0;
}