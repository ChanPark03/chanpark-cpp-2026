#include <iostream>
using namespace std;

class Circle
{
public:
    int radius;
    
    double getArea();
    
    Circle();
    Circle(int r);

};

double Circle :: getArea(){
    return 3.14 * radius * radius;
    }

Circle :: Circle(){
    radius = 1;
    cout << "반지름" << radius << "원생성" <<endl;

}

Circle :: Circle(int r){
    radius = r;
    cout << "반지름" << radius << "원생성" <<endl;


}


int main() {
    Circle donut;
    double area = donut.getArea();
    cout << "donut 면적은" << area << endl;

    Circle pizza(30);
    area = pizza.getArea();
    cout << "pizza 면적은" << area << endl;
    
    return 0;
}