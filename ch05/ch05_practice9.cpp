#include <iostream>
using namespace std;
class MyStack
{
    int p[10];
    int tos = 0;

public:
    MyStack();
    bool push(int n);
    bool pop(int &n);
};
MyStack ::MyStack()
{
    tos = 0;
}
bool MyStack ::push(int n)
{
    if (tos > 9)
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
    MyStack st;
    for (int i = 0; i < 11; i++) // 11개의 정수 푸사
    {
        if (st.push(i))
            cout << i << ' '; // 푸시된 값 화면 출력
        else
            cout << endl
                 << i + 1 << "번째 푸시 실패! 스택이 차 있음" << endl;
    }
    int n;
    for (int i = 0; i < 11; i++)
    {
        if (st.pop(n))
            cout << n << ' ';
        else
            cout << endl
                 << i + 1 << "번째 팝 실패! 스택이 비어있음" << endl;
    }

    return 0;
}

/* 예시 실행결과
0 1 2 3 4 5 6 7 8 9
9 8 7 6 5 4 3 2 1 0
11번째 팝 실패! 스택이 비어있음
*/