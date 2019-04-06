#include<iostream>

using namespace std;

int k=1;
int lotto[12]={0,};

void dfs(int ){

}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    while(k!=0){
        cin >> k;
        for(int i=0; i<k; i++){
             cin >> lotto[i]; 
        }
        //dfs();
       for(int i=0; i<k; i++){
            cout << lotto[i]<<' ';
        }
        cout <<'\n';
        
    }
    

    


    return 0;
}

