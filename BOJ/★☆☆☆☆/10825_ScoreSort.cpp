
/*
국영수
시간 제한	메모리 제한	제출	정답	맞은 사람	정답 비율
1 초	256 MB	7575	3354	2462	45.559%
문제
도현이네 반 학생 N명의 이름과 국어, 영어, 수학 점수가 주어진다. 이때, 다음과 같은 조건으로 학생의 성적을 정렬하는 프로그램을 작성하시오.

국어 점수가 감소하는 순서로
국어 점수가 같으면 영어 점수가 증가하는 순서로
국어 점수와 영어 점수가 같으면 수학 점수가 감소하는 순서로
모든 점수가 같으면 이름이 사전 순으로 증가하는 순서로 (단, 아스키 코드에서 대문자는 소문자보다 작으므로 사전순으로 앞에 온다.)
입력
첫째 줄에 도현이네 반의 학생의 수 N (1 ≤ N ≤ 100,000)이 주어진다. 둘째 줄부터 한 줄에 하나씩 각 학생의 이름, 국어, 영어, 수학 점수가 공백으로 구분해 주어진다. 점수는 1보다 크거나 같고, 100보다 작거나 같은 자연수이다. 이름은 알파벳 대소문자로 이루어진 문자열이고, 길이는 10자리를 넘지 않는다.

출력
문제에 나와있는 정렬 기준으로 정렬한 후 첫째 줄부터 N개의 줄에 걸쳐 각 학생의 이름을 출력한다.*/
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

struct info{
    string name;
    int ko;
    int en;
    int math;
};

int N=0;
const int MAX = 100500;
info student[MAX];
int size;
bool cmp(const info &p1, const info &p2){
    if(p1.ko>p2.ko){
        return true;
    }
    else if(p1.ko==p2.ko){
        if(p1.en<p2.en){
            return true;
        }
        else if(p1.en ==p2.en){
            if(p1.math>p2.math){
                return true;
            }
            else if(p1.math==p2.math){
                return p1.name <p2.name;     
            }
            
        }
    }
    return false;
}
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    
    cin >> N;

    for(int i=0; i<N; i++){
        cin >> student[i].name >> student[i].ko >> student[i].en >> student[i].math;
    }
    
    sort(student,student+N,cmp);
    
    for(int i=0; i<N; i++){
        cout << student[i].name<<'\n';
    }
    
    

    return 0;
}

/*
예제 입력 1 
12
Junkyu 50 60 100
Sangkeun 80 60 50
Sunyoung 80 70 100
Soong 50 60 90
Haebin 50 60 100
Kangsoo 60 80 100
Donghyuk 80 60 100
Sei 70 70 70
Wonseob 70 70 90
Sanghyun 70 70 80
nsj 80 80 80
Taewhan 50 60 90
예제 출력 1 
Donghyuk
Sangkeun
Sunyoung
nsj
Wonseob
Sanghyun
Sei
Kangsoo
Haebin
Junkyu
Soong
Taewhan

*/