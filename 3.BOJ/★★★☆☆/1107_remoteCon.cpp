/*
리모컨
시간 제한	메모리 제한	제출	정답	맞은 사람	정답 비율
2 초	256 MB	17791	4000	2702	22.325%
문제
수빈이는 TV를 보고 있다. 수빈이는 채널을 돌리려고 했지만, 버튼을 너무 세게 누르는 바람에, 일부 숫자 버튼이 고장났다.

리모컨에는 버튼이 0부터 9까지 숫자, +와 -가 있다. +를 누르면 현재 보고있는 채널에서 +1된 채널로 이동하고, -를 누르면 -1된 채널로 이동한다. 채널 0에서 -를 누른 경우에는 채널이 변하지 않고, 채널은 무한대 만큼 있다.

수빈이가 지금 이동하려고 하는 채널은 N이다. 어떤 버튼이 고장났는지 주어졌을 때, 채널 N으로 이동하기 위해서 버튼을 최소 몇 번 눌러야하는지 구하는 프로그램을 작성하시오. 

수빈이가 지금 보고 있는 채널은 100번이다.

입력
첫째 줄에 수빈이가 이동하려고 하는 채널 N (0 ≤ N ≤ 500,000)이 주어진다.  둘째 줄에는 고장난 버튼의 개수 M (0 ≤ M ≤ 10)이 주어진다. 고장난 버튼이 있는 경우에는 셋째 줄에는 고장난 버튼이 주어지며, 같은 버튼이 여러번 주어지는 경우는 없다.

출력
첫째 줄에 채널 N으로 이동하기 위해 버튼을 최소 몇 번 눌러야 하는지를 출력한다.

*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

    int ch,btn[11]={0,},bn,n,a=1,digit=1;
    const int curCh=100;
    int chArr[7];
    bool fix=false;
    vector <int> vArr;
    int visited[7];
    int arr[7];
    int con1=0;
    int flag=0;
    int cmp1=0,cmp2=0,cmp3=0;
    int b=0;
    int min1=500000;
    int cmp2Arr[7];
    int cmp2digit=1,cmp1digit=1;
    int noBtn=0;
int cmpdigit(int cmp){
    a=1;   
    fix=0;
    int cmpdigit=1;
    for(int i=0; i<6; i++){
        cmp2Arr[5-i]=(cmp/(100000/a))%10; // 자리수 찾기
        a=a*10;
        if(cmp2Arr[5-i]!=0&&!fix) {
            cmpdigit= (5-i)+1; //채널 자리 수 저장
            fix=1;
        }
    }
    return cmpdigit;
}
void func(int cnt){

    if(cnt==digit+1){
       /* 
        cout <<"ch: ";
        for(int j=digit-1; j>=0; j--){
            cout <<chArr[j]<<' ';
        }

        cout << " arr: ";
      */  
       //if()
        b=1;
        for(int j=0; j<(digit+1); j++){
            cmp1= cmp1+(arr[j]*b);
            b=b*10;
            //cout <<arr[j]<<' ';
            if(ch==cmp1) flag=1;
            
            if((ch-cmp1)>0){
                if(min1==(ch-cmp1)){
                    cmp1digit = cmpdigit(cmp1);
                    cmp2digit = cmpdigit(cmp2);

                    if(cmp1digit<cmp2digit){
                       min1 = (ch-cmp1);
                       cmp2 = cmp1;
                    }
                    
                }
                if(min1>(ch-cmp1)){ 
                    
                       min1 = (ch-cmp1);
                       cmp2 = cmp1;
                    
                }
            }

            if((ch-cmp1)<0){
                if(min1>(cmp1-ch)) {
                       
                            min1 = (cmp1-ch);
                            cmp2 = cmp1;
                        

                }
            }
        }
        //cout <<"cmp1: "<<cmp1;
        cmp1=0;
        //cout <<'\n';
        return;
    }
    
    
    for(int i=0; i<vArr.size(); i++){

            arr[cnt]=vArr[i];
            //cout <<arr[cnt]<<' ';
            func(cnt+1);
    }
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);



    cin >>ch;
    cin >>bn;
    for(int i=0; i<bn; i++){
        cin >> n;
        btn[n]=1;
    }

    for(int i=0; i<6; i++){
        chArr[5-i]=(ch/(100000/a))%10; // 자리수 찾기
        a=a*10;
        if(chArr[5-i]!=0&&!fix) {
            digit= (5-i)+1; //채널 자리 수 저장
            fix=1;
        }
    }

    for(int i=0; i<10; i++){
        if (btn[i]==0) vArr.push_back(i);    
    }
    sort(vArr.begin(),vArr.end());
    
    if(vArr.empty()) noBtn=1;
    else func(0);
        /*
        for(int j=0; j<digit; j++){
        arr[j]=j;
        cmp1= cmp1+(arr[j]*b);
        b=b*10;

            
        }
        cout <<"cmp1:"<<cmp1;
        cout <<'\n';


    */
    

    
    cmp2digit=cmpdigit(cmp2);
    /*
    cout << "digit: "<<digit<<'\n';
    cout << "cmp2digit: "<<cmp2digit<<'\n';
    cout << "ch: "<<ch<<'\n';
    cout << "cmp2: "<< cmp2<<'\n';
    cout << "flag: "<< flag<<'\n';
    for(int i=0; i<vArr.size(); i++) cout << vArr[i]<<' ';
    cout << "\nnumber of click :"; 
    */
    if(ch>100){
        cmp3=ch-100;
    }
    else if(ch<=100){
        cmp3=100-ch;
    }
    
    
    if(ch==100){
        cout <<0;
    }
    else if(noBtn==1) cout <<cmp3;
    else if(flag) {
        if(cmp3<=digit) cout <<cmp3;
        else cout <<digit;
    }
    else{
        if(cmp2>ch) {

            if(cmp3<((cmp2-ch)+digit)) cout <<cmp3;
            else cout <<(cmp2-ch)+cmp2digit;
        }
        else if(cmp2<=ch){
            if(cmp3<((ch-cmp2)+digit)) cout <<cmp3;
            else cout <<(ch-cmp2)+cmp2digit;
        }
    }



    //입력 확인
    /*
    cout << "digit: "<<digit<<'\n';
    for(int i=0; i<digit; i++){
        cout<< chArr[(digit-1)-i]<<' ';
    }
    cout <<'\n';
    
    for(int i=0; i<10; i++){
        cout << i<<": "<< btn[i]<<'\n';    
    }*/


    return 0;
}

/*
예제 입력 1 
5457
3
6 7 8
예제 출력 1 
6
예제 입력 2 
100
5
0 1 2 3 4
예제 출력 2 
0
예제 입력 3 
500000
8
0 2 3 4 6 7 8 9
예제 출력 3 
11117

힌트
5455++ 또는 5459--
*/