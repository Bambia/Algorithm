/*
별 찍기 - 11 성공
시간 제한	메모리 제한	제출	정답	맞은 사람	정답 비율
1 초	256 MB	16034	5957	4175	36.004%
문제
예제를 보고 규칙을 유추한 뒤에 별을 찍어 보세요.

입력
첫째 줄에 N이 주어진다. N은 항상 3×2k 수이다. (3, 6, 12, 24, 48, ...) (k ≤ 10)

출력
첫째 줄부터 N번째 줄까지 별을 출력한다.

*/
#include <iostream>

using namespace std;
char star[3073][6145];
int basic_stars(int Height, int x_axis, int y_axis);

int main()
{
	int input;
	cin >> input;

	int x = input-1,y=0;

	for (int j = 0; j < 3*(input/3); j++)
		for (int i = 0; i <6*(input/3); i++) 
			star[j][i]= ' ';

	basic_stars(input,x,y);
	for (int j = 0; j < 3 * (input / 3); j++) {
		for (int i = 0; i < 6 * (input / 3); i++) 
			cout <<star[j][i];
		cout <<"\n";
	}

    system("pause");
}

int basic_stars(int Height,int x_axis, int y_axis ) {
	if (Height == 3) {
		star[y_axis][x_axis] = '*';
		
		star[y_axis+1][x_axis - 1] = '*';
		star[y_axis+1][x_axis + 1] = '*';

		star[y_axis+2][x_axis - 2] = '*';
		star[y_axis+2][x_axis - 1] = '*';
		star[y_axis+2][x_axis] = '*';
		star[y_axis+2][x_axis + 1] = '*';
		star[y_axis+2][x_axis + 2] = '*';

	}

	if (Height < 3) {
		return 0;
	}

	int n =Height / 2;
	basic_stars(n, x_axis, y_axis);
	basic_stars(n, x_axis -n, y_axis +n);
	basic_stars(n, x_axis +n, y_axis +n);

}
/*
예제 입력 1 
24
예제 출력 1 
                       *                        
                      * *                       
                     *****                      
                    *     *                     
                   * *   * *                    
                  ***** *****                   
                 *           *                  
                * *         * *                 
               *****       *****                
              *     *     *     *               
             * *   * *   * *   * *              
            ***** ***** ***** *****             
           *                       *            
          * *                     * *           
         *****                   *****          
        *     *                 *     *         
       * *   * *               * *   * *        
      ***** *****             ***** *****       
     *           *           *           *      
    * *         * *         * *         * *     
   *****       *****       *****       *****    
  *     *     *     *     *     *     *     *   
 * *   * *   * *   * *   * *   * *   * *   * *  
***** ***** ***** ***** ***** ***** ***** *****
*/