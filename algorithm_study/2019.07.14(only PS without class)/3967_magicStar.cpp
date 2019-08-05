#include <iostream>
#include <vector>
#include <string>

using namespace std;
int star[6][4];
char ans[12];
char input;
int sum[6]={0,},ok=0,idx=0;

vector <int > v,x_idx;
vector <pair <int,int> > star_idx;
//string ans,res;

bool num[13];

int printAns(){
    int idx=0;

    for(int i=0; i<5; ++i){
        for(int j=0; j<9; ++j){
            if(star_idx[idx].first == i && star_idx[idx].second == j) {
                cout <<ans[idx++];
            }
            else cout <<'.';
            
        }
        cout <<'\n';
   }
}

void getInput(){
    for(int i=0; i<5; ++i){
        for(int j=0; j<9; ++j){
            cin >> input;
            if(input == '.') continue;
            star_idx.push_back({i,j});

            if(input == 'x') {
                v.push_back(0); 
                x_idx.push_back(idx);
            }
            else {
                v.push_back((input-'A')+1);
                num[input-'A'] = true; 
            }  
            idx++;
        }
    }

    // for(int i=0; i<v.size(); ++i) cout << v[i]<<' ';
    // cout <<'\n';
    // for(int i=0; i<12; ++i) cout << num[i]<<' ';
    // cout <<'\n';
    // for(int i=0; i<x_idx.size(); ++i) cout << x_idx[i]<<' ';
    // cout <<'\n';
}
bool Calculator(){
    star[0][0] = v[0];
    star[0][1] = v[2];
    star[0][2] = v[5];
    star[0][3] = v[7];

    star[1][0] = v[0];
    star[1][1] = v[3];
    star[1][2] = v[6];
    star[1][3] = v[10];

    star[2][0] = v[1];
    star[2][1] = v[2];
    star[2][2] = v[3];
    star[2][3] = v[4];

    star[3][0] = v[11];
    star[3][1] = v[8];
    star[3][2] = v[5];
    star[3][3] = v[1];

    star[4][0] = v[11];
    star[4][1] = v[9];
    star[4][2] = v[6];
    star[4][3] = v[4];

    star[5][0] = v[7];
    star[5][1] = v[8];
    star[5][2] = v[9];
    star[5][3] = v[10];

    for(int i=0; i<6; i++){
        sum[i]=0;
        for(int j=0; j<4; j++){
            sum[i] += star[i][j];
        }
        if(sum[i] != 26) return false;
    }
     for(int i=0; i<12; i++) ans[i] = v[i]+64;
    return true;
}

void findSolution(int pos,int size){
    
    if(size == x_idx.size()){
        //for(int i=0; i<12; ++i) cout <<v[i] <<' ';  
        //cout <<'\n';
        //Calculator();
        if(Calculator()) ok =1;
        return;
    } 
    if(ok) return; 

    for(int i=0; i<12; i++){
        if(num[i] == false) {
            num[i] =true;
            v[x_idx[pos]] = i+1;
            //cout <<"v["<< pos<<"]" << ": "<< v[pos]<<'\n';
            findSolution(pos+1,size+1);
            num[i] =false;
        } 
    }
}


int main(){
    getInput();
    findSolution(0,0);
    printAns();
    return 0;
}