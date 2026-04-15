#include <iostream>
using namespace std;

class Color{
    int r, g, b; //현재 색을 나타내는 성분 값

public:
    Color(int r, int g, int b); //생성자 
    void get(int &red, int &green, int &blue){
       red = r ;
       green = g ;
       blue = b ;
    }
};

Color :: Color(int r, int g, int b){
    this->r = r;
    this->g = g;
    this->b = b;
}

int main() {
    Color fore( 255, 0 ,0) , back( 15, 128, 200);
    int r, g ,b;
    fore.get(r, g, b);
    cout << "red= " << r << ", green= " << b << ",blue= " << b << endl;
    back.get(r, g, b);
    cout << "red= " << r << ", green= " << b << ",blue= " << b << endl;


    return 0;
}

//실행 결과 red= 255, green= 0, blue=0
//         red = 15, green =200, blue= 200