#include <iostream>
using namespace std;


int main() {
    
    double avg;
    double sum = 0;
    cout << "온도 5개를 입력하시오." << endl;
    
    double *p = new double [5];

    for (int i = 0; i < 5; i++)
    {
        cin >> p[i];
        sum = sum + p[i] ;
        
    }
    avg = sum/5;

    
    
    cout << "평균은 " << avg << endl;

    delete [] p;
    return 0;
}