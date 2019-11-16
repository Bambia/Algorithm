#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Land{
    int dtree; //여름엥 죽은나무 양분 주기 위해서
    int cur_nutri=0,add_nutri=0;
};
vector <int> tree[11][11];
Land land[11][11];
int N,M,K;
int total=0;
int dx[8] = {-1,0,1,1,1,0,-1,-1}; // 왼쪽 대각선부터 시계방향으로
int dy[8] = {-1,-1,-1,0,1,1,1,0};

bool in_range(int x ,int y){
    if(x>=0 && x<N && y>=0 && y<N) return true;
    else return false;
}
void ttime(int year){

    while(year--){
        //cout << "happy new year : "<<K-year<<" \n";

        //spring
        //cout <<"start spring\n";
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                if(!tree[i][j].empty()){
                    sort(tree[i][j].begin(),tree[i][j].end());

                    for(int k=0; k<tree[i][j].size(); k++){
                        
                        if(land[i][j].cur_nutri-tree[i][j][k]>=0 ){ //영양소가 현재나무를 키울만큼 충분히 있으면
                            //cout <<"grew a tree ["<<j<<"]"<<"["<<i<<"] "<<tree[i][j][k]<<'\n';
                            land[i][j].cur_nutri-=tree[i][j][k]; //영양소 없애고
                            tree[i][j][k]++; //나이 증가 시킨다
                            //cout <<" to "<<tree[i][j][k]<<"\n";
                        } 
                        else{ //충분한 영양소가 없으므로 현재의 나무를 죽인다ㅜㅜ
                            //cout <<"dead a tree["<<j<<"]"<<"["<<i<<"]"<<tree[i][j][k]<<"\n";
                            land[i][j].dtree += (tree[i][j][k]/2); //죽은나무 정보 저장
                            tree[i][j].erase(tree[i][j].begin()+k); //죽은나무 제거
                            k--; // 다음나무 접근
                            
                        }
                    }
                }
            }
        }
        /*
         //현재 양분 상태 보는 출력
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                cout << land[i][j].cur_nutri<<' ';
            }
            cout <<'\n';

        } // 현재 나무 그루 수 출력
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                cout << tree[i][j].size()<<' ';
            }
            cout <<'\n';
        }*/

        //summer
        //cout <<"start summer\n"; 
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                    //cout <<"The nutrient has been stored : "<< land[i][j].dtree <<'\n';
                    land[i][j].cur_nutri += land[i][j].dtree; //죽은나무 양분 저장
                    land[i][j].dtree = 0; //양분 초기화
            }
                
            
        }
        /*
        //현재 양분 상태 보는 출력
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                cout << land[i][j].cur_nutri<<' ';
            }
            cout <<'\n';

        } */

        //autumn 
       //cout <<"Start autumn\n";
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                for(int k=0; k<tree[i][j].size(); k++){ //전체 나무 갯수 체크
                    if(tree[i][j][k]%5==0){ //나무가 5의 배수이면
                        //cout <<"The tree has been breed\n";
                        for(int a=0; a<8; a++){ //8방향
                            
                            int n_x = j+dx[a];
                            int n_y = i+dy[a]; 

                            if(!in_range(n_x,n_y)) continue; //범위 초과면 지나감
                            
                            tree[n_y][n_x].push_back(1);
                        }
                    }
                
                }
            } 
        }
        /*
        // 현재 나무 그루 수 출력
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                cout << tree[i][j].size()<<' ';
            }
            cout <<'\n';
        }*/
        //winter
        //cout <<"Start winter\n";
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                //cout <<"Adding nutients\n";
                land[i][j].cur_nutri += land[i][j].add_nutri; //땅에 정해진 양분을 추가한다
            }
        }
        /*
        //현재 양분 상태 보는 출력
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                cout << land[i][j].cur_nutri<<' ';
            }
            cout <<'\n';

        } 
        */

    }


    //전체 나무 갯수 저장
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            //cout <<"The number of tree : "<<tree[i][j].size()<<'\n';
            total += tree[i][j].size();
        }
    }
}
int main(void){
    cin >> N >> M >> K;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin >> land[i][j].add_nutri;
            land[i][j].cur_nutri = 5;
        }
    }

    for(int i=0; i<M; i++){
        int x,y,z;
        cin >> y >> x >> z;
        tree[y-1][x-1].push_back(z); 

        // land[y-1][x-1].tree[land[y-1][x-1].end++]= z; //end의 값을 증가시켜서 크기 조절 나중에 나무가 죽으면 front 값을 증가시켜 나무 제거
    }
    /*
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cout << tree[i][j].size()<<' ';
        }
        cout <<'\n';
    }
        //현재 양분 상태 보는 출력
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cout << land[i][j].cur_nutri<<' ';
        }
        cout <<'\n';

    } // 현재 나무 그루 수 출력
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cout << tree[i][j].size()<<' ';
        }
        cout <<'\n';
    }*/

    total=0;
    ttime(K);

    cout <<total;

    return 0;
}






/*
    // 더할 양분 맵 상태보는 출력
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cout << land[i][j].add_nutri<<' ';
        }
        cout <<'\n';
    }
    
    //현재 양분 상태 보는 출력
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cout << land[i][j].cur_nutri<<' ';
        }
        cout <<'\n';

    } // 현재 나무 그루 수 출력
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cout << tree[i][j].size()<<' ';
        }
        cout <<'\n';
    }
*/