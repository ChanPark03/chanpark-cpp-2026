#include <iostream>
using namespace std;

class MyPipe {
    int size = 0;
    int putIndex = 0;
    int *p;
public:
    MyPipe();
    MyPipe(int size);
    MyPipe(const MyPipe &src);
    ~MyPipe();
    bool put(int n);
    bool get(int &n);
    int getSize() { return putIndex; }
};

MyPipe::MyPipe() {
    size = 0;
    putIndex = 0;
    p = NULL;
}

MyPipe::MyPipe(int size) {
    this->p = new int[size];
    this->size = size;
}

MyPipe::MyPipe(const MyPipe &src) {
    this->size = src.size;
    this->putIndex = src.putIndex;
    this->p = new int[this->size];
    for (int i = 0; i < this->size; i++)
        this->p[i] = src.p[i];
}

MyPipe::~MyPipe() {
    if (p)
        delete[] p;
}

bool MyPipe::put(int n) {
    if (putIndex > size - 1) return false;  // 꽉 찼으면 실패
    p[putIndex] = n;   // 현재 위치에 값 저장
    putIndex++;        // 다음 자리로 이동
    return true;
}

bool MyPipe::get(int &n) {
    if (putIndex < 1) return false;  // 비어있으면 실패
    n = p[0];                        // 맨 앞 값 꺼냄
    for (int i = 0; i < putIndex - 1; i++)
        p[i] = p[i + 1];             // 앞으로 한 칸씩 당김
    putIndex--;                      // 크기 줄임
    return true;
}

int main() {
    MyPipe a(5);
    a.put(10);
    a.put(20);

    MyPipe b(a);
    b.put(30);

    cout << "파이프 a에 저장된 개수: " << a.getSize() << endl;
    cout << "파이프 b에 저장된 개수: " << b.getSize() << endl;

    int n;
    a.get(n);
    cout << "파이프 a에서 꺼낸 값: " << n << endl;
    b.get(n);
    cout << "파이프 b에서 꺼낸 값: " << n << endl;
}