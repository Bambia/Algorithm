/*
문제
네 개의 명령어 D, S, L, R 을 이용하는 간단한 계산기가 있다. 이 계산기에는 레지스터가 하나 있는데, 이 레지스터에는 0 이상 10,000 미만의 십진수를 저장할 수 있다. 각 명령어는 이 레지스터에 저장된 n을 다음과 같이 변환한다. n의 네 자릿수를 d1, d2, d3, d4라고 하자(즉 n = ((d1 × 10 + d2) × 10 + d3) × 10 + d4라고 하자)

D: D 는 n을 두 배로 바꾼다. 결과 값이 9999 보다 큰 경우에는 10000 으로 나눈 나머지를 취한다. 그 결과 값(2n mod 10000)을 레지스터에 저장한다.
S: S 는 n에서 1 을 뺀 결과 n-1을 레지스터에 저장한다. n이 0 이라면 9999 가 대신 레지스터에 저장된다.
L: L 은 n의 각 자릿수를 왼편으로 회전시켜 그 결과를 레지스터에 저장한다. 이 연산이 끝나면 레지스터에 저장된 네 자릿수는 왼편부터 d2, d3, d4, d1이 된다.
R: R 은 n의 각 자릿수를 오른편으로 회전시켜 그 결과를 레지스터에 저장한다. 이 연산이 끝나면 레지스터에 저장된 네 자릿수는 왼편부터 d4, d1, d2, d3이 된다.
위에서 언급한 것처럼, L 과 R 명령어는 십진 자릿수를 가정하고 연산을 수행한다. 예를 들어서 n = 1234 라면 여기에 L 을 적용하면 2341 이 되고 R 을 적용하면 4123 이 된다.

여러분이 작성할 프로그램은 주어진 서로 다른 두 정수 A와 B(A ≠ B)에 대하여 A를 B로 바꾸는 최소한의 명령어를 생성하는 프로그램이다. 예를 들어서 A = 1234, B = 3412 라면 다음과 같이 두 개의 명령어를 적용하면 A를 B로 변환할 수 있다.

1234 →L 2341 →L 3412
1234 →R 4123 →R 3412

따라서 여러분의 프로그램은 이 경우에 LL 이나 RR 을 출력해야 한다.

n의 자릿수로 0 이 포함된 경우에 주의해야 한다. 예를 들어서 1000 에 L 을 적용하면 0001 이 되므로 결과는 1 이 된다. 그러나 R 을 적용하면 0100 이 되므로 결과는 100 이 된다.

입력
프로그램 입력은 T 개의 테스트 케이스로 구성된다. 테스트 케이스 개수 T 는 입력의 첫 줄에 주어진다. 각 테스트 케이스로는 두 개의 정수 A와 B(A ≠ B)가 공백으로 분리되어 차례로 주어지는데 A는 레지스터의 초기 값을 나타내고 B는 최종 값을 나타낸다. A 와 B는 모두 0 이상 10,000 미만이다.

출력
A에서 B로 변환하기 위해 필요한 최소한의 명령어 나열을 출력한다.

*/
#include <iostream>
#include <queue>

using namespace std;
const int MAX = 100500;
int arrL[5],arrR[5];
int d,s,l,r;
int decArr[5];
int A,B;
int visited[MAX]={0,}
int v=0,c,size;
//int MAX=;

void bfs(int pos){
    queue <int> q;
    
    q.push(pos);
    visited[pos]=1;

    while(!q.empty()){
        
        v=q.front();
        q.pop();
        size= q.size();
        for(int i=0; i<size; i++){ 
            
            //Double
            if(v*2<10000) d=v*2;
            else d=(v*2)%10000;
            if(visited[d]==0){ //D
                q.push(d);
                visited[d]=1;
            }

            //Sub
            if(v==0) s=9999;
            else s=s-1;
            if(visited[s]==0){ //D
                q.push(s);
                visited[s]=1;
            }

            // Left
             DecToArr(v,arrL); 
             leftOrRight(arrL,1);
             ArrToDec(arrL,l);
            if(visited[l]==0 && ){      
                q.push(l);
                visited[l]=1;
            }

            // Right
             DecToArr(v,arrR); 
             leftOrRight(arrR,0);
             ArrToDec(arrR,r);
            if(visited[r]==0 && ){      
                q.push(r);
                visited[r]=1;
            }
        }


    }
        


    
    
}

void leftOrRight(int Arr[],bool direction){
    int temp[5]={0,};

    if(direction){ //left

        temp[3]=Arr[0];
        temp[0]=Arr[1];
        temp[1]=Arr[2];
        temp[2]=Arr[3];
        for(int i=0; i<4; i++) Arr[i]=temp[i];
         
    }
    else
    {
        temp[1]=Arr[0];
        temp[2]=Arr[1];
        temp[3]=Arr[2];
        temp[0]=Arr[3];
        for(int i=0; i<4; i++) Arr[i]=temp[i];   
    }
    
}
void DecToArr(int Dec,int Arr[]){
    int a=1;
    //cout <<Dec <<' ';
    for(int i=0; i<4; i++){
        Arr[i]= (Dec/(1000/a))%10;
        a*=10;
        //cout <<arr[i]<<' ';
    }
    

}
void ArrToDec(int Arr[],int *Dec){
    int a=1;
    *(Dec)=0;
    //cout <<"dec: "<<*Dec;
    for(int i=0; i<4; i++){
        *(Dec)+=Arr[i]*(1000/a);
        a*=10;
        //cout <<arr[i]<<' ';
    }
    //cout <<Dec <<' ';
}
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int x,y;
    while(tc--){
        cin >> A>>B;
        bfs(A);
    }







    DecToArr(A,decArr);
    cout << "Arr:";
    for(int i=0; i<4; i++) cout <<decArr[i];
    cout <<'\n';

    //ArrToDec(decArr,&A);
    //for(int i=0; i<4; i++) cout <<decArr[i];
    leftOrRight(decArr,1);
    cout << "Left Arr:";
    for(int i=0; i<4; i++) cout <<decArr[i];
    cout <<" Dec: ";
    ArrToDec(decArr,&A);
    cout <<A; 
    cout <<'\n';
    
    leftOrRight(decArr,1);
    cout << "Left Arr:";
    for(int i=0; i<4; i++) cout <<decArr[i];
    cout <<" Dec: ";
    ArrToDec(decArr,&A);
    cout <<A;
    //for(int i=0; i<4; i++) cout <<decArr[i];
    cout <<'\n';
    return 0;
}



/*
예제 입력 1 
3
1234 3412
1000 1
1 16
예제 출력 1 
LL
L
DDDD
출처

*/