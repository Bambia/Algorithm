#include <iostream>
#include <string>
using namespace std;
int C,P,cnt=0;
int map[100];
int res[4];

int check(string fig){

    int hi[4]={0,};
    for(int i=0; i<fig.length(); i++){
        if(fig[i] == '0'){
            hi[i] = 0;
        }
        else if(fig[i] == '1'){
            hi[i] = 1;
        }
        else if(fig[i] == '2'){
            hi[i] =2;
        }
        
    }

    for(int i=0; i<=(C-fig.length()); i++){
        int no =0;
        for(int j=0; j<fig.length()-1; j++){
            if( (map[i+j]-hi[j]) != (map[i+j+1]-hi[j+1]) ) no =1; 
        }
        if(!no) cnt++;
    }
}

int solve(int num){
    if(num == 1){
        cnt += C; // 1줄짜리는 어디든 들어갈 수 있기 떄문
        check("0000");
    }
    else if(num == 2){
        check("00");
    }
    else if(num == 3){
        check("001");
        check("10");
    }
    else if(num == 4){
        check("100");
        check("01");
    }
    else if(num == 5){
        check("000");
        check("01");
        check("101");
        check("10");
    }
    else if(num == 6){
        check("000");
        check("00");
        check("011");
        check("20");
    }
    else if(num == 7){
        check("000");
        check("02");
        check("110");
        check("00");
    }
}

int main(){
    cin >> C >> P;
    for(int i =0; i<C; i++){
        cin >> map[i];
    }
    
    solve(P);
    cout << cnt;
    return 0;
}