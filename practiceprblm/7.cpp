#include <iostream>
using namespace std;
double n[5];
double onlypos();
double sum = 0;
double onlypos()
{

    for (int i = 0; i < 5; i++)
{
    
    if(n[i] > 0 )
    sum += n[i];

    
}
    return sum;
}
int main() {
    cout << "실수 5개를 입력하세요" << endl;
    
    for (int i = 0; i < 5; i++)
    {
        cin >> n[i];
    }
    

    onlypos();

    cout << "양수의 합은" << sum << "입니다" ;

    return 0;
}