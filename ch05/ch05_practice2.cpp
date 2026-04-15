#include <iostream>
using namespace std;

bool compare(int a, int b, int& min, int &max){
   if (a !=b ){
    if (a > b){    
    max = a ;
    min = b ;
    }
     else {
    max = b;
    min = a;
     }
     return false ;
   }
    
   else 
    return true ;
}


int main() {
    int a, b, min, max;
    cout << "두 수 입력 >>";
    cin >> a >> b;
    bool res = compare (a, b, min, max);
    if (res == true ) cout << "두 수는 같습니다.";

    else 
        cout << "작은 수는" << min << ", 큰수는" << max ;
    

    return 0;
}
