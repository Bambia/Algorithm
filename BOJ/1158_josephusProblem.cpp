#include <iostream>
#include <list>

using namespace std;

list <int> L; 
//int josephus[5000];
int main(void){
    int n,k;
    cin >> n>>k;

    for(int i=0; i<n; i++){
        L.push_back(i+1);
    }
    auto t = L.begin();
    //cout << "first : ";
    //for(auto i:L) cout << i <<' ';
    //cout <<"\n";
    cout <<"<";
    
    for(int j =0; j<n; j++){
        for(int i=0; i<k-1; i++) {
            t++;
            if(t==L.end()){
                t=L.begin();
            }
        }
        //josephus[j] =*t;
        cout << *t;
        if(j!=n-1) cout<< ", "; 

        t=L.erase(t);
        if(t==L.end()) t=L.begin();

          
    }
    cout << ">";
    
}