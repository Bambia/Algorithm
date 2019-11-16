/*
문제
자연수 N과 M이 주어졌을 때, 아래 조건을 만족하는 길이가 M인 수열을 모두 구하는 프로그램을 작성하시오.

1부터 N까지 자연수 중에서 M개를 고른 수열
같은 수를 여러 번 골라도 된다.
입력
첫째 줄에 자연수 N과 M이 주어진다. (1 ≤ M ≤ N ≤ 7)

출력
한 줄에 하나씩 문제의 조건을 만족하는 수열을 출력한다. 중복되는 수열을 여러번 출력하면 안되며, 각 수열은 공백으로 구분해서 출력해야 한다.

수열은 사전 순으로 증가하는 순서로 출력해야 한다.
*/
#include <iostream>

using namespace std;
int visited[9],visited2[9];
int arr[9];
int N,M,c=0;
void func(int cnt){
       //if (visited[cnt]==1) return;

    if(cnt ==M){
        
        for(int i=0; i<M; i++){
            cout << arr[i]<<' ';
            
        }
    cout << '\n';
    return;    
    }
   
    for(int i=0; i<N; i++){
            arr[cnt]=i+1;
            //cout <<arr[cnt]<<' ';
            func(cnt+1);
        
    }
}


int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M ;
    func(0);

    return 0;
}

/*
예제 입력 1 
3 1
예제 출력 1 
1
2
3
예제 입력 2 
4 2
예제 출력 2 
1 1
1 2
1 3
1 4
2 1
2 2
2 3
2 4
3 1
3 2
3 3
3 4
4 1
4 2
4 3
4 4
예제 입력 3 
3 3
예제 출력 3 
1 1 1
1 1 2
1 1 3
1 2 1
1 2 2
1 2 3
1 3 1
1 3 2
1 3 3
2 1 1
2 1 2
2 1 3
2 2 1
2 2 2
2 2 3
2 3 1
2 3 2
2 3 3
3 1 1
3 1 2
3 1 3
3 2 1
3 2 2
3 2 3
3 3 1
3 3 2
3 3 3
*/