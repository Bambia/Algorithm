#include <iostream>

using namespace std;

int N,S;
int arr[21]={0,};
int visited[21]={0,};
int ans=0;
//int MAX=;

void dfs(int cnt,int sum){



   if(cnt==N){
        if((sum==S)) {
            ans++;
            cout <<"Sum:"<<sum<<"//"; 
            
            for(int i=0; i<cnt; i++){
                cout <<arr[i]<<' ';
            }
            cout <<'\n';
            return; //탐색 종료
        }
    }
    dfs(cnt+1,sum+arr[cnt]);
    dfs(cnt+1,sum);
    return;
    
    
}
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> S;
    for(int i=0; i<N; i++){
        cin>> arr[i];
    
    }
    dfs(0,0);
    cout << ans;
    return 0;
}