#include <iostream>
using namespace std;
int add (int arr[] , int n, int c=0 ){
    for (int i = 0; i < n; i++)
    {
        c += arr[i]; 
    }
    return c;
}


int main() {
    int a[] = { 1, 2, 3, 4,5 };
    int b[] = { 6, 7, 8, 9, 10 };
    int c = add(a, 5);
    int d = add(b , 3, c);

    cout << c << endl;
    cout << d << endl;
    

    return 0;
}
/* 실행결과 :15
            13 
*/
