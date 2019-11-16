#include <iostream>
#include <vector>
using namespace std;

template <class T>
class Vector{
    public:
        int _size, _capacity;
        T *arr;
        Vector(){
            _size = 0;
            _capacity = 32;
            arr = new T[_capacity];
        }
        Vector(int k){
            _size = k;
            _capacity = k;
            arr = new T[_size];
        }
        Vector(int k, int val){
            _size = _capacity = k;
            arr = new T[_size];
            for(register int i =0; i<_size; i++){
                arr[i] = val;
            }
        }
        ~Vector(){
            delete[] arr;
        }
        void clear(){
            delete[] arr;
            _size =0;
            _capacity =32;
            arr = new T[_capacity];
        }
        void resize(int k){
            T *temp;
            temp = new T[k];
            for(int i=0; i< _size; i++)
                temp[i] = arr[i];
            delete[] arr;
            arr = temp;
            _capacity = k;
        }
        int size() const{
            return _size;
        }
        T* begin() const{
            return &arr[0];
        }
        T* end() const{
            return &arr[0]+ _size;
        }
        void push_back(T val){
            if(_size == _capacity){
                resize(_size*2);
            }
            arr[_size++] = val;
        }
        void pop_back(){
            _size--;
        }
        T& operator [](int idx){
            return arr[idx];
        }
        T operator [](int idx) const{
            return arr[idx];
        }
};
int main(){
    int N,arr[500];
    vector <int> v(32,-1);
    cin>> N;
    for(int i =0; i<v.size(); i++) cout << v[i]<< ' ';
    cout <<'\n';
    
    for(int i=0; i < N; i++) {
        int arr;
        cin >> arr ;
        v.push_back(arr);
    
    }
    for(int i =0; i<v.size(); i++) cout << v[i]<< ' ';
    cout <<'\n';
      
    
    
    return 0;
}