#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
using namespace std;

struct AB{
    int A,B;
};

vector < pair<int,int> > score;

int tc;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> tc;

    while(tc--){
        int ans=0,N=0,best;

        cin >> N;
        for(int i=0; i<N; i++) {
            pair <int , int> x;
            cin >> x.first >> x.second;
            score.push_back(x);
        }
        sort(score.begin(),score.end());
        //for(int i=0; i<N; i++)  cout << score[i].first <<' '<< score[i].second <<'\n';
        
        best = score[0].second; 
        ans = 1;
        for(int i=1; i<N; i++){
            if(score[i].second < best ){
                ans++;
                best = score[i].second;
            }  
        }
        cout <<ans <<'\n';
        score.clear();
    }

    return 0;
}