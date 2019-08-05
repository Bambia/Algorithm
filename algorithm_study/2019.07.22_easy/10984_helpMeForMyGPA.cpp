#include <iostream>

using namespace std;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int semester=0;

    cin >> semester;
    while(semester--){
        int numOfClass =0,tCredits=0;
        double tGrade = 0.0;
        cin >> numOfClass;
        for(int i=0; i<numOfClass; i++){
            int credits =0;
            double grade =0;
            cin >> credits >> grade;
            tCredits += credits;
            tGrade += grade*credits;
        }
        cout << tCredits << " "<< tGrade/tCredits <<'\n';
    }

    return 0;
}
