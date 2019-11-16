#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;


template <typename It>
void _swap(It &a, It &b){
	It c(a);a=b;b=c;
}
template <typename It, typename Comp>
void _sort(It begin, It end, Comp comp){
	if(begin==end)
		return;
	_swap(*begin, *((end-begin)/2+begin));
	It pi = begin;
	It le = begin + 1;
	It ri = end - 1;
	while( le <= ri ) {
		while(le <= ri && !comp(*pi, *le))
			le++;
		while(le <= ri && !comp(*ri, *pi))
			ri--;
		if(le<=ri)
			_swap(*le, *ri);
	}
	_swap(*pi, *ri);
	_sort(begin, ri, comp);
	_sort(ri + 1,  end, comp);
}

bool cmp(const int& a, const int& b){
	return a<b;
}


int main(){
	int arr[5000];
	int n;
	scanf("%d", &n);
	for(int i=0;i<n;i++){
		int a;
		scanf("%d", &a);
		arr[i] = a;
	}
	_sort(arr, arr+n, cmp);
	for(int i=0;i<n;i++)
		printf("%d ", arr[i]);
	return 0;
}

5 
66 5 32 11 1