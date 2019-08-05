#include <iostream>

using namespace std;

const int MAX = 1000000;

int _stack[MAX];
int sPos;
void s_push(int data){
	_stack[sPos++] = data;
}a

void s_pop(){aaaaaa
	if(sPos > 0) sPos--;
}

int s_top(){
	if(sPos == 0) return -1;
	return _stack[sPos-1];
}
bool s_empty(){
	if (sPos == 0 ) return true;
	else return false;

}

int _queue[MAX];
int head,tail;

void q_push(int data){
	_queue[tail++] = data;
}

void q_pop(){
	head++;
}

int q_front(){
	return _queue[head];
}
int q_back(){
	return _queue[tail];

}
bool q_empty(){
	if (head == tail) return true;
	else return false;
}


int main(){
	int N,M;

	cin >> N;
	for(int i=0; i<N; i++) {
		int q;
		cin >> q;
		q_push(q);
	}
	cin >> M;
	for(int i=0; i<N; i++) {
		int s;
		cin >> s;
		s_push(s);
	}

	cout <<"q contents: ";
	while(!q_empty()) {
		cout << q_front()<<' ';
		q_pop();
	}
	cout <<"\ns contents: ";
	while(!s_empty()){
		cout << s_top()<<' ';
		s_pop();
	}
	return 0;
}