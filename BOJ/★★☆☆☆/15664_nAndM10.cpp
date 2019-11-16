/*
N과 M (10)
시간 제한	메모리 제한	제출	정답	맞은 사람	정답 비율
1 초	512 MB	800	586	512	76.877%
문제
N개의 자연수와 자연수 M이 주어졌을 때, 아래 조건을 만족하는 길이가 M인 수열을 모두 구하는 프로그램을 작성하시오.

N개의 자연수 중에서 M개를 고른 수열
고른 수열은 비내림차순이어야 한다.
길이가 K인 수열 A가 A1 ≤ A2 ≤ ... ≤ AK-1 ≤ AK를 만족하면, 비내림차순이라고 한다.
입력
첫째 줄에 N과 M이 주어진다. (1 ≤ M ≤ N ≤ 8)

둘째 줄에 N개의 수가 주어진다. 입력으로 주어지는 수는 10,000보다 작거나 같은 자연수이다.

출력
한 줄에 하나씩 문제의 조건을 만족하는 수열을 출력한다. 중복되는 수열을 여러번 출력하면 안되며, 각 수열은 공백으로 구분해서 출력해야 한다.

수열은 사전 순으로 증가하는 순서로 출력해야 한다.


*/



#include <iostream>
#include <algorithm>

using namespace std;

const int MAX = 100001;


int N,M;

int check[10];
int arr[10];
int input[10];
int temp=0;
int flag=0;

void dfs(int pos){
    
    if(pos == M){
        flag=0;

        for(int i=0; i<M-1; i++){
            if(arr[i]>arr[i+1]){
                flag=1;
            }
        }

        if(!flag){
            for(int i=0; i<M; i++){
                cout <<arr[i]<<' ';
            }
            cout <<'\n';
        }
        

    }

    int temp=0;

    for(int i=0; i<N; i++){
        if(!check[i]&&temp!=input[i]){
            check[i]=1;
            temp=input[i];
            arr[pos] = input[i];
            dfs(pos+1);
            check[i]=0;
        }
    }
    
}



int main(void){

    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M;

    for(int i=0; i<N; i++){
        cin >> input[i];
    }
    sort(input,input+N);
    dfs(0);

    return 0;
}
























/*
예제 입력 1 
3 1
4 4 2
예제 출력 1 
2
4
예제 입력 2 
4 2
9 7 9 1
예제 출력 2 
1 7
1 9
7 9
9 9
예제 입력 3 
4 4
1 1 2 2
예제 출력 3 
1 1 2 2

*/