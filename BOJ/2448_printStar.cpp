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