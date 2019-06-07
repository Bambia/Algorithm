#include <iostream> 
#include <vector>
using namespace std;

int num1,num2;

vector <int> cal[15];

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> num1 >>num2;
    int a= 10000000;
    for(int i=0; i<8; i++){
        cal[0].push_back((num1/a)%10);
        cal[0].push_back((num2/a)%10);
        a/=10;
    }
    
    // for(int i=0; i<cal[0].size(); i++){
    //     cout << cal[0][i]<<' ';
    // }
    // cout <<'\n';

    for(int i=0; i<14; i++){
        for(int j=0; j<cal[i].size()-1; j++){
            int a = (cal[i][j] + cal[i][j+1])%10;
            //cout <<a <<' ';
            cal[i+1].push_back(a);
        }
        //cout <<'\n';
    }
    for(int i=0; i<cal[14].size(); i++) cout <<cal[14][i];
    return 0;
}