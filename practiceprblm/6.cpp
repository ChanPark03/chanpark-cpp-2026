#include <iostream>
using namespace std;
    int n;
    int temp;
    int a;
    int tthplace();

int tthplace()
{
    temp = n % 100 ;
    a = temp / 10 ;

    return a;
}
int main() {
    
    
    cout << "정수를 입력 하세요" << endl;
    cin >> n ; 

    tthplace();

    cout << n <<" 의 10자리 수는"<< a << "입니다 ";

    return 0;
}