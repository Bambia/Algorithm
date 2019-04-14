#include <iostream>

using namespace std;

struct station{
    int out;
    int in;
};

station S[5];
int p[5];
int max1=0;
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);

    for(int i=0; i<4; i++){
        cin >> S[i].out >>S[i].in;
    }
    /*
    cout <<"*********Station*******\n";
    for(int i=0; i<4; i++){
        cout << S[i].out<<' '<<S[i].in<<'\n';
    }
    */
    p[0]=0;
    for(int i=0; i<4; i++){
        p[i+1]=p[i]+(S[i].in-S[i].out);
        //cout <<"P"<<i+1<<": "<<p[i+1]<<'\n';
        if(max1<p[i+1]){
            max1=p[i+1];
            //num=i;
        }
    } 
    
    cout <<max1;
    /*
    for(int i=0; i<4; i++){
        cout << S[i].out<<' '<<S[i].in<<'\n';
    }
    */

    return 0;
}