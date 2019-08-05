#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;
char n[3][100005];
int len=0,c,sign[2];

int charToInt(char val){
    return val == '\0' ? '\0' : (val -'0');
}

void reverse(char *arr,int len){
    for(int i=0; i<len/2; i++){
        char temp = arr[i];
        arr[i] = arr[len-1-i];
        arr[len-1-i] = temp;
    }
}

char* func(char *arr1 , char *arr2, int len1 , int len2){
    
    int len = len1 > len2 ? len1 : len2;
    int sign1=0,sign2=0;

    if( arr1[0] == '-' ) sign1 = 1;

    if( arr2[0] == '-' ) sign2 = 1;

    if(sign1 == sign2){ // + +
        reverse(n[0],strlen(n[0]));
        reverse(n[1],strlen(n[1]));

        if(sign1 == 1) arr1[len1-1] = '\0';
        if(sign2 == 1) arr2[len2-1] = '\0';

        for(int i=0; i<=len; i++){
            n[2][i] = (charToInt(arr1[i]) + charToInt(arr2[i]) +c)%10+'0';

            if(charToInt(arr1[i]) + charToInt(arr2[i]) + c >9 ){
                c =1;
            }
            else c =0;
            
        }

        if(n[2][len] == '0')  {
            if(sign1 == 1 && sign2 == 1) n[2][len] = '-';
            else n[2][len] = 0; 
        }

        if(n[2][len-1] == '0'){
           }
        
        
    }

    else{ // - + or + -
       if(sign1 == 0 && sign2 == 1){

       }
       else{

       }
    }
    cout <<"n[2]: "<<n[2]<<'\n';

    reverse(n[2],strlen(n[2]));

    return n[2];
}
int main(){
        ios::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        
        cin >> n[0] >> n[1];
        //if(n[0][0] == '-') sign[0] =1;
        //if(n[0][1] == '-') sign[1] =1;

        cout <<n[0] <<" "<< n[1]<<'\n';


        cout << func(n[0], n[1], strlen(n[0]), strlen(n[1]) );
        //cout <<n[2];
        //cout << charToInt(n[0][0]);

        return 0;
}
