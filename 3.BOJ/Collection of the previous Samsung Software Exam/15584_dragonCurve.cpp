#include <iostream>
#include <vector>
using namespace std;

int N,ans;
int x,y,d,g;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,-1,0,1};

int map[106][106];

void doPaint(int y,int x){
    for(int d=0; d<4; d++){
        map[y + (d/2)][x + (d%2)] |= (1 << d);
    }
}

bool isPainted(int y, int x){
    if(map[y][x] == 15 ) return true;
    return false;
}
int main(){
    
    vector <int> dragon(1,0);
    for(int i =0; i<=10; i++){
        for(int j=dragon.size()-1; j>=0; j--){
            dragon.push_back((dragon[j]+1)%4);
        }
    }
    //cout <<"size: "<<dragon.size()<<'\n';

    cin >> N;
    for(int i=0; i<N; i++){
        cin >> x >> y >> d >> g;
        int gen_cnt = 1<< g;
        int nx=x,ny=y;

        for(int i=0; i<= gen_cnt; i++){
            doPaint(ny,nx);
            //if(i == gen_cnt ) break;

            nx += dx[ (dragon[i]+d)%4   ];    
            ny += dy[ (dragon[i]+d)%4   ];

        }
    }

    for(int i=1; i<=101; i++){
        for(int j=1; j<=101; j++){
            //cout <<map[i][j] <<' ';
            ans += isPainted(i,j);
        }
        //cout <<'\n';
    }
    
    cout <<ans <<'\n';
    return 0; 
}