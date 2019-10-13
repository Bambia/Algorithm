#include <iostream>
#include <string>

using namespace std;

string format;
int c=0,d =0;
int sc=0,sd=0;

int sum=1;
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> format;
    
    for(int i=0; i<format.size(); i++){
        if(format[i]=='c') {
            if(format[i+1]=='c') sc++;

            c++;

        }
        else if(format[i]=='d'){
            d++;
            if(format[i+1]=='d') sd++;

            
        }
    }
    //cout <<"d:"<<d<<" c:"<<c<<'\n';
    //cout <<"sd:"<<sd<<" sc:"<<sc<<'\n';

    for(int i=0; i<c; i++) {
        if(sc>=1) {
            sum=sum*25;
            sc--;
        }
        else{
            sum=sum*26;
        }
    }
    for(int i=0; i<d; i++) {
        if(sd>=1) {
            sum=sum*9;
            sd--;
        }
        else{
            sum=sum*10;
        }
    }

    cout <<sum;

    return 0;
}