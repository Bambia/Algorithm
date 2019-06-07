#include <iostream>
#include <vector>

using namespace std;
struct point{
    int x,y;
};
int check[10][10][10][10][10][10];
int map[6][6];
vector <int> v;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
int cnt;

void dfs(struct point pos){
        if(v.size()==6){
            if(check[v[0]][v[1]][v[2]][v[3]][v[4]][v[5]] == 0 ){
                check[v[0]][v[1]][v[2]][v[3]][v[4]][v[5]] =1;
                cnt ++;
            }
            return;
        }
        for(int i=0; i<4; i++){
            point new_pos;
            new_pos.x = pos.x+dx[i];
            new_pos.y = pos.y+dy[i];
            if(new_pos.x <0 || new_pos.y <0 || new_pos.x >4 || new_pos.y >4) continue;
            v.push_back(map[new_pos.y][new_pos.x]);
            dfs(new_pos);
            v.pop_back();
        }
}

int main(){
    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++){
            cin >> map[i][j];
        }
    }
 
    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++){
            point a;
            a.x = j;
            a.y = i;
            v.push_back(map[a.y][a.x]);
            dfs(a);
            v.pop_back();
        }
    }
    cout << cnt <<'\n';
     
    return 0;
}