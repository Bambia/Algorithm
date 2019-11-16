#include <iostream>

using namespace std;
int N,max_r,max_n;
int sum;
long long int d;
int main(){
    cin >> N;
    max_r = -1;
    for(int i=2; i<N+1; i++){
        d=1;
        sum=0;
            //cout <<"i: "<<i<<'\n'; 
            while((N/d) !=0){
                //cout <<(N/d)%i <<' ';
                sum += (N/d)%i;
                
                d *=i;
            }
             //cout <<" sum: ";
            //cout << sum <<'\n';
            if(sum > max_r ) {
                max_r = sum;
                max_n = i;
                //cout <<"max_r : "<<max_r<<'\n';
            }    
    }
    cout <<max_r <<' '<< max_n;
    return 0;
}