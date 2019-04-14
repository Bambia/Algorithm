#include <iostream>
#include <algorithm>

using namespace std;

const int MAX= 1001;

int M,N;
int helmet[MAX];
int jacket[MAX];

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N>>M;
    for(int i=0; i<N; i++) cin >> helmet[i];
    for(int j=0; j<M; j++) cin >> jacket[j];

    sort(helmet,helmet+N);
    sort(jacket,jacket+M);

    cout <<helmet[N-1]+jacket[M-1];

    return 0;
}