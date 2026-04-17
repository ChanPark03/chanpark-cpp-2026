#include <iostream>
using namespace std;


bool equals(string x = "", string y = "", int n=0, string z= "")

int main() {

    string x = "Prof. Hwang";
    string y = "Prof. Kim";
    string z = "Prof. Lee";

    if(equals(x, y)) cout << "같음" << endl;
    if(equals(x, y, 3 )) cout << "앞 3글자 같음 " << endl;
    if(equals(x, y, 5, z)) cout << "앞 5글자 같음" <<endl; 


}

// 실행결과 :앞 3글자 같음
        // 앞 5글자 같음 