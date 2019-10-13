#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int R,C,T,purifier;
long long ans;
int map[51][51];
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

void spread(){
    int cmap[51][51]={0,};
    memcpy(cmap,map,sizeof(cmap));
    for(int i=0; i<R; i++){
        for(int j=0; j<C; j++){
            if(map[i][j] >= 5 && map[i][j] != -1 ){
                int spreadDust = map[i][j]/5;
                for(int k=0; k<4; k++){
                    int n_y = i + dy[k];
                    int n_x = j + dx[k];
                    if( (map[n_y][n_x] == -1) || n_y >= R || n_x >= C || n_y < 0 || n_x < 0 ) continue;
                    cmap[n_y][n_x] += spreadDust;
                     cmap[i][j] -= spreadDust;     
                }
            } 
        }
    }
    memcpy(map,cmap,sizeof(map));
    map[purifier][0] = -1;
    map[purifier-1][0] = -1;

}
void workingAirpurifier(){
    for(int j = purifier -2; j>0; j--) map[j][0] = map[j-1][0];  // 좌 
    for(int j = 0; j<C-1; j++) map[0][j] = map[0][j+1]; // 상
    for(int j = 1; j<=(purifier-1); j++) map[j-1][C-1] = map[j][C-1]; // 우
    for(int j = C-1; j>1; j--) map[purifier-1][j] = map[purifier-1][j-1]; // 하
    map[purifier-1][1] = 0;

    for(int j = purifier+1; j<R-1; j++) map[j][0] = map[j+1][0];  // 좌 
    for(int j = 0; j<C-1; j++) map[R-1][j] = map[R-1][j+1]; // 하
    for(int j = R-1; j>purifier; j--) map[j][C-1] = map[j-1][C-1]; // 우
    for(int j = C-1; j>1; j--) map[purifier][j] = map[purifier][j-1]; // 상
    map[purifier][1] = 0;
}

int main(){
    ans = 0;
    cin >> R >> C >> T;
    for(int i=0; i<R; i++){
        for(int j=0; j<C; j++){
            cin >> map[i][j]; 
            if(map[i][j] == -1) purifier = i;
        }
    }
    
    while(T--){
        spread();
        workingAirpurifier();
    }

    for(int i=0; i<R; i++){
        for(int j=0; j<C; j++){
            if(map[i][j] == -1) continue;
            ans += map[i][j];
        }
    }
    cout <<ans <<'\n';
    return 0;
}

/*
while(T--){
        spread();
        cout <<"spreaded\n";
        for(int i=0; i<R; i++){
            for(int j=0; j<C; j++){
                cout << map[i][j]<<' '; 
            
            }
            cout <<'\n';
        }
        workingAirpurifier();

        cout <<"cleaned\n";
        for(int i=0; i<R; i++){
            for(int j=0; j<C; j++){
                cout << map[i][j]<<' '; 
            
            }
            cout <<'\n';
        }
    }

    for(int i=0; i<R; i++){
        for(int j=0; j<C; j++){
            if(map[i][j] == -1) continue;
            ans += map[i][j];
        }
    }
*/