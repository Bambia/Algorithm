#include <iostream>


using namespace std;

int x,y;
int day=0;
char date[8][4] ={"SUN","MON","TUE","WED","THU","FRI","SAT"};
int s =1;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);


    cin >> x>>y;
    
    while(s<x){
        
        if(s==1||s==3||s==5||s==7||s==8||s==10||s==12){
            day=day+31;
            s++;
        }
        else if(s==2){
            day=day+28;
            s++;
        }
        else{
            day=day+30;
            s++;
        }
    }
    day=day+y;
    //cout <<"day: "<<day<<'\n';
    day=day%7;
 
    for(int i=0; i<3; i++){
        cout << date[day][i];
    }
    
    

    return 0;
}