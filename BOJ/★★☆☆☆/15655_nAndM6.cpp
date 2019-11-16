/*
N과 M (6)
시간 제한	메모리 제한	제출	정답	맞은 사람	정답 비율
1 초	512 MB	1021	898	788	89.241%
문제
N개의 자연수와 자연수 M이 주어졌을 때, 아래 조건을 만족하는 길이가 M인 수열을 모두 구하는 프로그램을 작성하시오. N개의 자연수는 모두 다른 수이다.

N개의 자연수 중에서 M개를 고른 수열
고른 수열은 오름차순이어야 한다.
입력
첫째 줄에 N과 M이 주어진다. (1 ≤ M ≤ N ≤ 8)

둘째 줄에 N개의 수가 주어진다. 입력으로 주어지는 수는 10,000보다 작거나 같은 자연수이다.

출력
한 줄에 하나씩 문제의 조건을 만족하는 수열을 출력한다. 중복되는 수열을 여러번 출력하면 안되며, 각 수열은 공백으로 구분해서 출력해야 한다.

수열은 사전 순으로 증가하는 순서로 출력해야 한다.
*/
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int visited[9];
int arr[9]={0};
vector <int> varr;
int N,M,c=0;
bool pass=0;
void func(int cnt){
       //if (visited[cnt]==1) return;

    if(cnt ==M){
        pass=0;
        for(int i=0; i<M-1; i++){
            if(arr[i]>arr[i+1]){
                pass=1;
            }
        }
        if(!pass){
             for(int i=0; i<M; i++){
                cout << arr[i]<<' ';
            }
        cout << '\n';           
        }
    return;    
    }
   
    for(int i=0; i<N; i++){
        if(!visited[i]){
            visited[i]=1;
            arr[cnt] = varr[i];
            func(cnt+1);
            visited[i]=0;
        }
    }
}


int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M ;
    for(int i=0; i<N; i++){
        cin >> c;
        varr.push_back(c);
    }
    
    sort(varr.begin(),varr.end());
    //for(int i=0; i<N; i++) cout << varr[i]<<' ';

    func(0);

    return 0;
}


/*
예제 입력 1 
3 1
4 5 2
예제 출력 1 
2
4
5
예제 입력 2 
4 2
9 8 7 1
예제 출력 2 
1 7
1 8
1 9
7 8
7 9
8 9
예제 입력 3 
4 4
1231 1232 1233 1234
예제 출력 3 
1231 1232 1233 1234
*/