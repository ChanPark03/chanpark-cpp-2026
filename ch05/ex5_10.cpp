#include <iostream>
using namespace std;

class Circle
{
    int radius;

public:
    Circle() { radius = 1; }
    Circle(int radius) { this -> radius = radius; }
  
    double getArea() {return 3.14 *radius *radius; }
    Circle(const Circle &c); //복사 생성자에서 &c 로 받을 때 원본을 실수로 변경하지 못하도록 관례적으로 const 를 붙인다.


};

Circle :: Circle(const Circle &c){
    this->radius = c.radius; 
    cout << "복사 생성자 실행 radius =" << radius << endl;
}
int main()
{
   Circle src(30);
   Circle dest(src);

   cout << "원본의 면적 =" << src.getArea() << endl;
   cout << "사본의 면적 =" << dest.getArea() << endl;
}