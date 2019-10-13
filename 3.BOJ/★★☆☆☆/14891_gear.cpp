#include <iostream>

using namespace std;
struct Gear{
    char T[8]={0,};
    int dir=0;
};

struct Input{
    int num;
    int D;
};

Input input[101];
Gear gear[4];

int K,num,dir,sum;
void rotate(int start){ //시계 1 반시계 -1
    int t[8];
    if(gear[start].dir==1){ //시계
        for(int i=0; i <8; i++){
            if(i==0) t[0]=gear[start].T[7];
            else t[i] = gear[start].T[i-1];
        }
        //cout <<"C_rotate: ";
    }
    else if(gear[start].dir==(-1)){
        for(int i=0; i <8; i++){
            if(i==7) t[7]=gear[start].T[0];
            else t[i] = gear[start].T[i+1];
        }
    }

    for(int i=0; i<8; i++) gear[start].T[i] = t[i];


}

void cmp(int start,int dir,int left,int right){
    //rotate(gear[start-1],dir);
    if(start<0 || start>3) return;

    if(gear[start].T[6]!=gear[start-1].T[2]&&left==1) cmp(start-1,(-1)*(dir),1,0);
    if(gear[start].T[2]!=gear[start+1].T[6]&&right==1) cmp(start+1,(-1)*(dir),0,1);
    
    gear[start].dir=dir;
    rotate(start);

    return;
    //cmp(start-1,(-1)*(dir));
}
int main(void){
    
    
    for(int i=0; i<4; i++){
        for(int j=0; j<8; j++){
            cin >> gear[i].T[j];
        }
    }
    /*
    cout <<'\n';
    for(int i=0; i<4; i++){
        for(int j=0; j<8; j++){
            cout << gear[i].T[j];
        }
        cout <<'\n';
    }*/
    
    
    cin>> K; 
    for(int i=0; i<K; i++) {
        cin >> input[i].num >> input[i].D;
    }

    /*
    cout <<'\n';
    for(int i=0; i<K; i++) {
        cout << input[i].num <<' '<< input[i].D;
        cout <<'\n';
    }*/
    for(int i=0; i<K; i++) {
        cmp((input[i].num-1),input[i].D,1,1);
    }

    //cmp(input[0].num,input[0].D,1,1);

    if(gear[0].T[0]=='1') sum+=1;
    if(gear[1].T[0]=='1') sum+=2;
    if(gear[2].T[0]=='1') sum+=4;
    if(gear[3].T[0]=='1') sum+=8;
    
    cout << sum;
    
    return 0;
}

