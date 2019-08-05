#include <iostream>

using namespace std;

const int MAX = 1000;
int N,F,flag =1,num=1,x,y,ansX,ansY;
int map[MAX][MAX];

int main(){
        ios::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        cin >> N >> F;

        x = N/2;
        y = x;
        map[y][x] = 1;
        int cnt= 1,cal =0;

        while(cnt <N){
            if(flag == 1){
                for(int i=0; i<cnt; i++)  {
                    map[--y][x] = ++num;
                    if(num == F) {
                        ansX = x;
                        ansY = y;
                    }
                }
                for(int i=0; i<cnt; i++)  {
                    map[y][++x] = ++num;
                    if(num == F) {
                        ansX = x;
                        ansY = y;
                    }
                }
                flag = -1;
            }
            else {
                for(int i=0; i<cnt; i++)  {
                    map[++y][x] = ++num;
                    if(num == F) {
                        ansX = x;
                        ansY = y;
                    }                    
                }
                for(int i=0; i<cnt; i++)  {    
                    map[y][--x] = ++num;
                    if(num == F) {
                        ansX = x;
                        ansY = y;
                    }
                }
                flag = 1;
            }
            //cout <<"cnt:"<<cnt <<'\n';
            cnt ++;
        }
        for(int i=0; i<cnt-1; i++) {
            map[--y][x] = ++num;
                if(num == F) {
                    ansX = x;
                    ansY = y;
                }
        }
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                cout << map[i][j]<<' ';
            }
            cout <<'\n';
        }
        cout << ansY+1 <<" "<<ansX+1<<'\n';

        return 0;
}
