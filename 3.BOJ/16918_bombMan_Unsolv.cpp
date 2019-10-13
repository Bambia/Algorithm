#include <iostream>

using namespace std;

char map[201][201];
char bomb1[201][201];
char bomb2[201][201];
bool flag=false;
int visited[201][201]={0,};
int r,c,n,i;

void bomb(){
    for(i=0; i<r; i++){
        for(int j=0; j<c; j++){            
            if(bomb1[i][j]=='1' && visited[i][j]!=1) {
                visited[i][j]==1;
                bomb2[i][j]='.';
                if((i-1)>=0) bomb2[i-1][j]='.';
                if((i+1)<r) bomb2[i+1][j]='.';
                if((j-1)>=0) bomb2[i][j-1]='.';
                if((j+1)<c) bomb2[i][j+1]='.';
            }
            
        }

    }
        
}

void func1(){

    for(int j=0; j<r; j++){
        for(i=0; i<c; i++){
            if( (map[j][i]=='O')) bomb1[j][i] = '1';
            else if((map[j][i]=='.')) bomb1[j][i] = '0';

            bomb2[j][i]='O';
        }   
    }

        
}
void func2(){

    for(int j=0; j<r; j++){
        for(i=0; i<c; i++){
            if( (bomb2[j][i]=='O')) bomb1[j][i] = '1';
            else if((bomb2[j][i]=='.')) bomb1[j][i] = '0';

            bomb2[j][i]='O';
        }   
    }
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            visited[i][j]=0;
        }
    }
        
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    

    cin >> r >> c >> n;
    
    for(int i=0; i<r; i++){
        for(int j =0; j<c; j++){
            cin >> map[i][j]; 
        }
    }
    // t=1
    func1();
    bomb();
    for(int i=0; i<n/3; i++){
        func2();
        bomb();
        
        for(int j =0; j<c; j++){
            cout << bomb1[i][j]; 
        }
        cout <<'\n';
         
    }
    
    for(int a=0; a<n+1; a++){
        if(a%2!=0) flag= !flag;
    }
    

    if(n==1){ //입력출력
        for(int i=0; i<r; i++){
            for(int j =0; j<c; j++){
                cout << map[i][j]; 
            }
        cout <<'\n';
        }  
    }
    else if(n%2 == 0){ //전체출력
        for(int i=0; i<r; i++){
            for(int j =0; j<c; j++){
                cout << 'O'; 
            }
        cout <<'\n';
        }      
    }
    else{
        
        if(!flag) { //다음꺼 출력
            for(int i=0; i<r; i++){
                for(int j =0; j<c; j++){
                    cout << bomb2[i][j]; 
                }
            cout <<'\n';
            }
               
        }
        else if(flag){ //입력출력
            for(int i=0; i<r; i++){
                for(int j =0; j<c; j++){
                    cout << map[i][j]; 
                }
            cout <<'\n';
            } 
            
        }
    } 
    return 0;
}    

    





/*
    cout <<"\n*bomb1s*\n";
    for(int i=0; i<r; i++){
        for(int j =0; j<c; j++){
            cout << bomb1[i][j]; 
        }
        cout <<'\n';
    }  

    bomb();
    cout <<"\n*bomb2s*\n";
    for(int i=0; i<r; i++){
        for(int j =0; j<c; j++){
            cout << bomb2[i][j]; 
        }
        cout <<'\n';
    }  
*/
