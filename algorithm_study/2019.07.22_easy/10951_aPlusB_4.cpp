#include <iostream>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int A,B;
    while(cin >> A >> B){
        cout << A+B<<'\n';
    }

    return 0;
}

/*
#include <cstdio>

using namespace std;

int main(){
    int A=0,B=0;
    while(scanf("%d%d",&A,&B)!= EOF){
        printf("%d\n",A+B);
    }

    return 0;
} */