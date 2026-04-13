#include <iostream>
using namespace std;

int main() {

    int n = 0;
    int min=0;
    int max=0;

    cout << "물품의 갯수를 입력하시오" << endl;

    cin >> n;

    cout << "물품 " << n <<"개의 가격 입력";

    int *p = new int [n];

    
    for (int i = 0; i < n; i++)
    {
        cin >> p[i];
    }
    
    min = p[0];
    max = p[0];

    for (int i = 0; i < n; i++)
    {
        if(p[i] < min ) min = p[i];
        if(p[i] > max ) max = p[i];
    }
     
    cout << "제일 싼 가격은 " << min << endl;
    cout << "제일 비싼 가격은 " << max << endl;

    delete []p; 

    return 0;
}