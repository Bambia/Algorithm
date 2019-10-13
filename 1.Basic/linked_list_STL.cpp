#include <iostream>
#include <list>

using namespace std;

list <int> L = {1,2};

//list<int>::iterator t = L.begin();
auto t = L.begin();

int main(void)
{
		
	L.push_front(10);
	L.insert(t,6);
	
	L.push_back(5);

	for(auto i : L) cout << i<< ' ';
	
	cout<<'\n';
	cout << *t <<'\n';
	t++;
	cout << *t <<'\n';
	t=L.erase(t);
	cout << *t <<'\n';
	t=L.begin();
	cout << *t <<'\n';
	t=L.end()--
	;
	cout << *t <<'\n';


	for(auto i : L) cout << i<< ' ';
	return 0;
}