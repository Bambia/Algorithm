#include<iostream>
#include<algorithm>
#include<vector>
#include<utility>

using namespace std;
const int MAX = 12;

pair<int,int> pairArr[MAX][MAX];
int costMap[MAX][MAX]={0,};
int map[MAX][MAX]={0,};
int N=0;
int arr[MAX]={0,};
vector <int> village;
int visited[MAX] ={0,};


void dfs(int start){
    if(visited[start]==1)return;
    visited[start]=1;
    
    if(start==N){
         for(int i=0; i<N; i++){
                cout << arr[i]<<' ';
         }
         cout << '\n';
    }
    
    for(int i=0; i<N; i++){
        if((map[start][i]==1)&&(!visited[i])){
            visited[i]=1;
            arr[start]=village[i];
            //cout <<arr[start]<<' ';
            dfs(start+1);
            visited[i]=0;
        }
    }
    
     
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
             cin >> costMap[i][j];
             if(costMap[i][j]!=0){
                 map[i][j] = 1;
             }
        }
    }
    for(int i=0; i<N; i++){
        village.push_back(i+1);
    }
    cout << "village:";
    for(int i=0; i<N; i++){
        cout << village[i];
    }
    cout <<'\n';
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
             cout << map[i][j]<<' ';
        }
        cout <<'\n';
    }
    cout <<'\n';
        dfs(0);
    


    return 0;
}