#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

struct POS{
    int x,y;
};


int map[4][4],visited[10][10][10][10][10][10][10];
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
int ans;

vector <int> v;

void solve(POS pos){
    
    if(v.size() == 7) {
        if(visited[v[0]][v[1]][v[2]][v[3]][v[4]][v[5]][v[6]] == 0) {
            visited[v[0]][v[1]][v[2]][v[3]][v[4]][v[5]][v[6]] = 1;
            ans ++;
        }
        return;
    }

    for(int i=0; i<4; i++ ){
        POS next;
        next.x = dx[i] + pos.x;
        next.y = dy[i] + pos.y;
        
        if(next.x >= 4 || next.y >= 4 || next.x <0 || next.y < 0) continue;

        v.push_back(map[next.y][next.x]);
        solve(next);
        v.pop_back();
    }
}
int main(){

    int test_case;

    cin >> test_case;

    for(int tc = 1; tc <= test_case; tc++){
        memset(visited,0,sizeof(visited));
        memset(map,0,sizeof(map));
        ans = 0;
        
        for(int i=0; i<4; i++){
            for(int j=0; j<4; j++){
                cin >> map[i][j];
            }
        }

        for(int i=0; i<4; i++){
            for(int j=0; j<4; j++){
                solve({j,i});
            }
        }
        cout <<"#"<<tc<<" "<<ans<<'\n';
    
    }
    return 0;    
}