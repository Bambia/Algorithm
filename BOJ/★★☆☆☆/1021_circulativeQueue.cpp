#include <iostream>
//#include <deque>

//deque <int> DQ;

using namespace std;
const int MAX = 50;

int move1;
int v[MAX];
int N,M;
int list[MAX];
int front=1;
int main(){

    cin >> N >> M;

    for(int i=0; i<M; i++){
        cin >> v[i];
    }

    for(int i=1; i<=N; i++){
        list[i]=i;

    }



    for(int i=0; i<M; i++){
        // for(int i=1; i<=N; i++){
        //     cout << list[i]<<' ';

        // }
        // cout <<"\n";

        int R_move=0,L_move=0;
        int R_stop=0,L_stop=0;
        int R_front=0, L_front=0;
        int R_flag=0,L_flag=0;
        //cout <<"v["<<i<<"] ="<< v[i]<<'\n';
        R_front = front;
        while(!R_stop){
           //cout <<"R\n";
            if(list[R_front]==v[i]){
                //cout <<"if";
                 R_stop =1;
            }
            else {
                //cout <<R_front;
                //cout <<v[i] <<" "<<list[R_front]<<'\n';
                R_front++;
                if(R_front >N ) R_front =1;
                
                if(list[R_front]!=0) R_move++;
            }
        }
        L_front = front;
        while(!L_stop){
            //cout <<"L\n";
            if(list[L_front]==v[i]){
                 L_stop =1;
            }
            else {
                L_front--;
                if(L_front <=0 ) L_front =N;
                
                if(list[L_front]!=0) L_move++;
            }
            
        }
        //cout << "R_move: "<<R_move<< " L_move: "<<L_move<<"\n";
        //cout << "R_front: "<<R_front<< " L_front: "<<L_front<<"\n";
        
        if(R_move <= L_move ) {
            move1 += R_move;
            list[R_front] =0;
            front = R_front+1;
            

        }
        else if(R_move > L_move){
            move1 += L_move;
            list[L_front] =0;

            front = L_front+1;
            
            
        }
        int a = front, stop =0,cnt=0;

        while(!stop){
                if(a> N) a=1;
                
                if(list[a]!=0){
                    front = list[a];
                    stop=1;
                }
                a++;

                cnt++;
                if(cnt>N) stop=1;
        }

        //cout << "front: "<<front<<"\n";

    }

    cout << move1;
    
    return 0;
}