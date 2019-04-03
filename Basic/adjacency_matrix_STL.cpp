#include <iostream>
#include <vector>
using namespace std;

vector<int> adj[100];

int main()
{
	int v, n;

	cin >> v >> n;

	for (int i = 0; i <n; i++) {
		int x, y;  cin >> y >> x;
		adj[y].push_back(x);
		adj[x].push_back(y); 
	}

	for (int i = 0; i < v; i++) {
		int a = adj[i + 1].size();
		cout << "size:" << adj[i + 1].size();
		cout << "[" << i + 1 <<"] ";
		
		for(int j=0; j< a;  j++ )
			//cout << "??";
			cout << adj[i+1][j] <<" ";
			 
		
		
		cout << "\n";
	}
	cout << "Hello World!\n"; 

	return 0;
}