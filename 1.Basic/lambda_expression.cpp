#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int arr[7] ={1,3,2,5,8,9,7};

    for(int i=0; i<7; i++) cout << arr[i]<<' ';
    cout <<"\n";

    sort(arr,arr+7, [](const int &l, const int &r){
        return l<r;
    } ); 

    for(int i=0; i<7; i++) cout << arr[i]<<' ';
    cout <<"\n";
    return 0;
}