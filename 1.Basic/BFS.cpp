#include <iostream>
#include <queue>

using namespace std;

int N,S,M,K;
int arr[21]={0,};
int visited[21]={0,};
int a[21][21];

int ans=0;
//int MAX=;

    void bfs(int pos){
        
        queue<int> q;
        q.push(pos);
        visited[pos] =1;

        while(!q.empty()){

            pos = q.front();
            q.pop();
            cout << pos<<' ';

            B=pos+1;
            q.push(B);

            B=pos-1;
            q.push(B);

            B=pos*2;
            q.push(B);

            ==q.front();

            for(int i=1; i<3; i++){
                if(a[pos][i]==1 && visited[i]==0){
                    visited[i]=1;
                    q.push(i);
                }
            }
        }

    
    
    }
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int x,y;
    cin >> N >> K;
    /*
    for(int i=0; i<M; i++){
        cin >> x>>y;
        a[x][y] =1;
        a[y][x] =1;
    }

    for(int i=0; i<N+1; i++){
        for(int j=0; j<N+1; j++){
            cout << a[i][j]<<' ';
        }
        cout <<'\n';
    }
    bfs(N);
    
    return 0;
}

#include <iostream>
#include <queue>

using namespace std;

int N,S,K,M;
int arr[21]={0,};
int visited[21]={0,};
int a[21][21];

int ans=0;
//int MAX=;

    void dfs(int pos){
        
        queue<int> q;
        q.push(pos);
        visited[pos] =1;

        while(!q.empty()){

            pos = q.front();
            q.pop();
            cout << pos<<' ';

            for(int i=1; i<N+1; i++){
                if(a[pos][i]=1 && visited[i]==0){
                    visited[i]=1;
                    q.push(i);
                }
            }
        }

    
    
    }
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int x,y;
    cin >> N >>M>> K;
    for(int i=0; i<N; i++){
        cin >> x>>y;
        a[x][y] =1;
        a[y][x] =1;
    }

    for(int i=0; i<N+1; i++){
        for(int j=0; j<N+1; j++){
            cout << a[i][j]<<' ';
        }
        cout <<'\n';
    }
    dfs(1);
    
    return 0;
}