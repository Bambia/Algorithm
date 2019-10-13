#include <iostream>

using namespace std;

char c[6][16],p[6];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    for(int i =0; i<5; i++) cin >> c[i];
    //for(int i =0; i<5; i++) cout << c[i];
    int cnt=0;

    while(1){
        int num =0,end=0;

        for(int i=0; i<5; i++){
            if(c[i][cnt] != '\0') {
                p[num++] = c[i][cnt];
            }
            else end++;
        }
        cnt++;
        if (end == 5) break;
        for(int i=0; i<num; i++) cout << p[i];
    } 
    cout <<'\n';

    return 0;
}