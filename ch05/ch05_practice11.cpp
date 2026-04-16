#include <iostream>
using namespace std;
class MyStack
{
    int *p;
    int size = 0;
    int tos = 0;

public:
    MyStack();
    MyStack(int size);
    MyStack(const MyStack &src);
    ~MyStack();
    bool push(int n);
    bool pop(int &n);
}; 
MyStack::MyStack(){
    p = NULL;
    size = 0;
    tos = 0;
}
MyStack::MyStack(int size){
    this-> p = new int [size];
    this -> size = size;

}
MyStack::MyStack(const MyStack &src){
    this -> size = src.size;
    this -> tos = src.tos;
    this -> p = new int [this -> size];
    
    for (int i = 0; i < this -> size; i++)
    {
        this -> p[i] = src.p[i];
    }
    
}


MyStack::~MyStack(){
    if (p)
        delete[] p;
}

bool MyStack ::push(int n)
{
    if (tos > size-1)
        return false;

    else
    {
        this->p[tos] = n;
        tos++;
        return true;
    }
}

bool MyStack ::pop(int &n)
{
    if (tos < 1)
        return false;
    else
    {
        tos--;
        n = p[tos];
        return true;
    }
}
int main()
{
    MyStack a(10);
    a.push(10); a.push(20);

    MyStack b = a;
    b.push(30);
    int n;
    a.pop(n);
    cout << "스택 a에서 팝한 값" << n << endl;
    
    b.pop(n);
    cout << "스택 b에서 팝한 값" << n << endl;

}

/* 예시 실행결과
스택 a에서 팝한 값 20
스택 b에서 팝한 값 30
*/