#include <iostream>
#include <vector>
#include <string>

using namespace std;

//string bin[] = {"0000","0001","0010","0011","0100","0101","0110","0111","1000","1001","1010","1011","1100","1101","1110","1111"};
string bin[] = {"0000","0001","0010","0011","0100","0101","0110","0111","1000","1001","1010","1011","1100","1101","1110","1111"};
string targetRate[10] = {"211","221","122","411","132","231","114","312","213","112"};
int n,m,ans;
int findMin(int a,int b, int c){
    int min=0,temp=0;
    if(a<b) temp = a;
    else temp = b;

    if(temp >c) min = c;
    else min = temp;

    return min;
}
string conv(string str){
    string conv ="";
    for(int i=0; i<str.size(); i++){
        if(str[i] >= 'A') conv += bin[(str[i]-'A')+10]; 
        else conv += bin[str[i]-'0'];
    }
    return conv;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int test_case;
    cin >> test_case;

    for(int tc = 1; tc<=test_case; tc++){
        vector <string> alreadyStoredOrgCodes;
        vector <string> alreadyHasEncryptedNum;
        cin >> n >> m;
        ans = 0;
        for(int i=0; i<n; i++){
            string orgCode;
            cin >> orgCode;
            // 중복제거
            int orgFlag = 1;
            for(int j=0; j<alreadyStoredOrgCodes.size(); j++){
                if(orgCode == alreadyStoredOrgCodes[j]) {
                    orgFlag = 0;
                    break;
                }
            }
            if(!orgFlag) continue;

            alreadyStoredOrgCodes.push_back(orgCode);
            //cout <<"orgCode: "<<orgCode <<'\n';
            string binCode = conv(orgCode);
            //cout <<"binCode: "<<binCode <<'\n';
            // 암호패턴 비율 추출 
            vector <int> encryptedPattern;
            int zeroLen=0,oneLen=0;
            
            for(int j=0; j<binCode.size(); j++){
                //cout <<"a";
                if(binCode[j] != '0'){
                    encryptedPattern.push_back(zeroLen);
                    zeroLen = 0;
                    while(j < binCode.size() && binCode[j] != '0') {
                        oneLen++;
                        j++;
                    }
                    encryptedPattern.push_back(oneLen);
                    oneLen = 0;
                    zeroLen++;
                }
                else {
                    zeroLen++;
                } 
            }
            if(encryptedPattern.empty()) continue;
            // cout <<"encryptedPattern: ";
            //for(int j=0; j<encryptedPattern.size(); j++) cout << encryptedPattern[j]<<' ';

            vector <int> numbers;
            for(int j=0; j<=encryptedPattern.size(); j+=4){
                
                if( (j !=0 && j%32 == 0 ) || (j == encryptedPattern.size()) ){ // 마지막도 봐야함 왜 ?  
                    //암호코드 검증부분
                    string finalNum = "";
                    for(int k=0; k<numbers.size(); k++ ){
                        finalNum += to_string(numbers[k]);
                    }
                    int flag =1;
                    for(int k=0; k<alreadyHasEncryptedNum.size(); k++){
                        if(finalNum == alreadyHasEncryptedNum[k]) {
                            flag =0;
                            break;
                        }
                    }
                    if(flag){
                        alreadyHasEncryptedNum.push_back(finalNum);
                        //cout <<"numbers: ";
                        //for(int u=0; u<numbers.size(); u++) cout << numbers[u] <<' ';
                        //cout <<'\n';
                        int oddSum =0;
                        int evenSum = 0;
                        int lastNum = numbers[7];

                        for(int k=0; k<7; k++){
                            if(k %2 == 0){
                                oddSum += numbers[k];
                            }
                            else{
                                evenSum += numbers[k];
                            }
                        }
                        int totalSum = oddSum*3 + evenSum + lastNum;
                        if( totalSum % 10 == 0) {
                            ans += oddSum + evenSum + lastNum;
                        } 
                    }
                    if (j == encryptedPattern.size()) break;
                    numbers.clear();
                }
                
                
                int a = encryptedPattern[j+1];
                int b = encryptedPattern[j+2];
                int c = encryptedPattern[j+3];

                int min = findMin(a,b,c);
                //cout <<"min: "<< min <<'\n'; 
                a /= min;
                b /= min;
                c /= min;

                string find = "";
                find += '0'+a;
                find += '0'+b;
                find += '0'+c;
                for(int k =0; k<10; k++){
                    if(find == targetRate[k]) {
                        numbers.push_back(k);
                        //cout <<"["<<k<<"]"<<' ';
                        break;
                    }
                    
                }
            }

        }
        cout<<"# " << tc <<" "<<ans<<'\n';
    }

    return 0;
}