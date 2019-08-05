#include <iostream>
#include <string>
using namespace std;

struct Node{
    char data;
    Node* next;
    Node* prev;

}nodePool[1000000];
int currentNodePointer;

Node *head = NULL;
Node *tail = NULL;
int _size;
Node * createNode(char data){
    Node* newNode = &nodePool[currentNodePointer++];
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;

    return newNode;
}
void init(){
    head = createNode(0);
    tail = createNode(0);
    head->next =tail;
    head->prev =NULL;

    tail->next = NULL;
    tail->prev = head;
    _size =0;
}

Node* Begin(){return head->next;}
Node* End(){return tail->prev;}
Node* Find(int key){
    for(Node*p = Begin(); p!=End(); p=p->next){
        if(p->data==key)
            return p;
    }
    return NULL;
}

void insert(struct Node* Where, char data){
    Node* newNode = createNode(data);

    newNode->next = Where->next;
    newNode->prev = Where;
    Where->next->prev = newNode;
    Where->next = newNode;
    _size++;

}
void push_back(char data) {insert(End(),data);}
void push_front(char data) {insert(Begin(),data); }

void erase(Node* Where){

    if(Begin()->prev == End()->next) return;

    Where->next->prev = Where->prev;
    Where->prev->next = Where->next;
    _size--;
}

void pop_front(){erase(Begin());}
void pop_back(){erase(End());}
int size() {
    return _size;
}

string str;
int main(){
    init();
    cin >> str;
    cout <<"str.length:"<<str.length()<<'\n';
    for(int i=0; i<str.length(); i++) push_back(str[i]);
    int Size = size();
    cout <<"Size:"<<Size<<'\n';
    for(int i=0; i<Size; i++) {
        cout <<Begin()->data;
        pop_front();
    }
    

    return 0;
}