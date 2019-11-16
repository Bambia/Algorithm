#include <iostream>
#include <stack>

using namespace std;

int N, P,cnt;
int s,p;

stack <int > st[6];

int main(void){

    cin >> N >> P;
    for(int i=0; i<N; i++){
        cin >> s >> p;

        if(st[s-1].empty() || st[s-1].top() < p){
                st[s-1].push(p);
                cnt ++;
                //cout <<"a\n";
        }
        else if(st[s-1].top() > p){
                while(!st[s-1].empty() && st[s-1].top() > p  ){
                    st[s-1].pop();
                    cnt++;
                    //cout << "b\n";
                }
                //cout <<"d\n";
                if(st[s-1].empty()|| st[s-1].top() != p) {
                    st[s-1].push(p);
                    cnt++;                    
                }
                //cout << "c\n";
        }
    
       
    }
    cout << cnt;
      
    return 0;
} 