#include <iostream>

using namespace std;
const int MAX =100;

int m_a[MAX][MAX],m_b[MAX][MAX];
int result[MAX][MAX];
int aN,aM,bN,bM;

int main(){
    cin >> aN >> aM;
    for(int i=0; i<aN; i++){
        for(int j=0; j<aM; j++){
            cin >>m_a[i][j];
        }
    }
    cin >> bN >> bM;
    for(int i=0; i<bN; i++){
        for(int j=0; j<bM; j++){
            cin >>m_b[i][j];
        }
    }

    for(int i=0; i<aN; i++){
        for(int j=0; j<bM; j++){
            for(int k=0; k<aM; k++){
                result[i][j] += (m_a[i][k]*m_b[k][j]);
            }
              
        }
    }

    for(int i=0; i<aN; i++){
        for(int j=0; j<bM; j++){
            cout << result[i][j]<<' ';
        }
        cout <<'\n';
    }


    return 0;
}