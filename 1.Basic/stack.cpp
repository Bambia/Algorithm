#include <iostream>
using namespace std;

template <class T>
class _stack{
    public : 
        struct Node{
            T val;
            Node *next;
            Node (){}
            Node (T val) : val(val), next(0) {}
        };

        Node *head;
        int _size;
        _stack(){
            head = 0;
            _size = 0;
        }
        
        void push(T val){
            Node *temp = new Node(val);
            if(head == 0) head = temp;
            else{
                temp->next = head;
                head = temp;
            }
            _size++;
        }

        void pop(){
            Node *temp = head;
            head = temp->next;
            _size--;
        }

        bool empty() const {
            return _size == 0;
        }

        int top() const{
            return head->val;
        }

        int size() const{
            return _size;
        }
};



int main(void){
    _stack <int> st;
    int N;
    cin >> N;
    for(int i=0; i<N; i++) {
        int A;
        cin >> A;
        st.push(A);
    }

    cout <<"size:" << st.size() << "IsEmpty ?: " << st.empty()<<'\n';

    while(!st.empty()){
        cout <<st.top() <<'\n';
        st.pop();
    }

    return 0;
}




/* 
void push(int val);
int top(void);
void pop();
bool empty();

const int MAX  = 10000007;
int dat[MAX];
int pos;

using namespace std;

int main(void){
    int input;

    cin >> input;
    push(input);
    cin >> input;
    push(input);

    cout << top();
    pop();
    cout << top();

    return 0;
}

void push(int val){
    dat[pos++]= val;
}
int top(void){
    if(pos == 0) return -1;
    return dat[pos-1];
}
bool empty(){
    if(pos == 0) return true;
    return false; 
}
void pop(){
    if(pos == 0) return;
    pos--;
}*/