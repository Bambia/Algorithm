#include "main.cpp"

#define N 4

typedef struct {

	int strike;
	int ball;
	
} Result;



// API

extern Result query(int guess[]);


static Result Trial[20];
static int g[10000], check[10000];
static int flag = 1, cnt = 0;

void init() {
	//printf("user init !!\n");

	for (int i = 0; i < 10; ++i) {
		for (int j = 0; j < 10; ++j) {
			for (int k = 0; k < 10; ++k) {
				for (int l = 0; l < 10; ++l) {
					if (i == j || j == k || k == l || i == k || i == l || j == l) continue;
					g[cnt++] = (i * 1000 + j * 100 + k * 10 + l);
				}
			}
		}
	}
	//printf("cnt:%d \n",cnt);
	for (int i = 0; i < cnt; i++) {
		//printf("%d ",g[i]);
		//if (i % 20 == 0) printf("\n");
	}
	for (int i = 0; i < cnt; i++) check[g[i]] = 0;

}

Result cmp(int a, int b) {
	int count[10] = { 0, };
	Result result = { 0,0 };
	for (int i = 0; i < N; i++) {
		++count[a % 10];
		++count[b % 10];
		if (a % 10 == b % 10) ++result.strike;
		a /= 10;
		b /= 10;
	}
	for (int i = 0; i < 10; i++) if (count[i] == 2)result.ball++;

	result.ball -= result.strike;
	//printf("cmp result : strike:%d ball:%d\n",result.strike,result.ball);
	return result;


}


void doUserImplementation(int guess[]) {
	int Possibility = 5000, num = 0;
	Result result, po;
	init();
	int key;
	while (1) {
		//printf("check sequence 1\n");
		for (int i = 0; i < cnt; ++i) {
			if (check[g[i]] == 0) {
				key = g[i];
				//printf("trial number : %d ",key);
				//printf("check sequence 2\n");
				guess[3] = g[i] % 10;
				guess[2] = (g[i] / 10) % 10;
				guess[1] = (g[i] / 100) % 10;
				guess[0] = (g[i] / 1000) % 10;
				//printf("your guessing number is :%d%d%d%d\n",guess[0],guess[1],guess[2],guess[3]);
				result = query(guess);
				//printf("strike:%d ball:%d\n",result.strike,result.ball);
				break;
			}
		}

		if (result.strike == 4) break;

		for (int j = 0; j < cnt; j++) {
			if (check[g[j]] == 0) {
				//printf("cmp key: %d g:%d\n",key,g[j]);
				po = cmp(key, g[j]);
				if (po.ball == result.ball && po.strike == result.strike) continue;
				check[g[j]] = 1;
			}
		}
	}

}