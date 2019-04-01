#include <iostream>

using namespace std;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
const int numStudents = 5;
int scores[numStudents] ={92,99,96,89,91};
int maxScore = 0;
for(auto &score: scores)
    if(maxScore < score)
    maxScore = score;

cout<<"The best score is " << maxScore << "\n";

return 0;
  system("pause");
}