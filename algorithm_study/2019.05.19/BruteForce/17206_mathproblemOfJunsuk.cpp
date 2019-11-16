#include <iostream>

using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N[100001],sum[80001],tc;
    cin >> tc;

    for(int j=0; j<tc; j++){
        int s=0;
        cin >> N[j];
        if(sum[N[j]] !=0) {
            //cout <<"N="<<N[j]<<" sum:"<<sum[N[j]] <<'\n';
            //cout <<"fater \n";
            cout <<sum[N[j]] <<'\n';
            continue;
        }
        for(int k=N[j]-1; k>=0; k--){
            if(sum[k]!=0) {
                s=k+1;
                sum[N[j]] = sum[k];
                //cout <<"near value "<<k<<"\n";
                //cout <<"Start:"<<s<<'\n';
                //cout <<"start value:"<<sum[N[j]]<<'\n';
                break;
            }
        }

        for(int i =s; i<=N[j]; i++){
            
            if(i%3 ==0 ) sum[N[j]]+=i;
            else if(i%7 ==0) sum[N[j]]+=i;
            //if(i%3 ==0 && i%7 ==0) sum-=i;
        }
        //cout <<"N="<<N[j]<<" sum:"<<sum[N[j]] <<'\n';
        cout <<sum[N[j]] <<'\n';

    }
    return 0;
}