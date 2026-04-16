#include <iostream>
using namespace std;


class Rectangle {
public:
    int width;
    int height;
    Rectangle();
    Rectangle(int w, int h);
    Rectangle (int length);
    bool isSquare();
    Rectangle (const Rectangle &rect);
};

Rectangle :: Rectangle(){
    width = 1;
    height = 1;
}
Rectangle :: Rectangle(int w, int h){
    width = w;
    height = h;
}
Rectangle :: Rectangle( int length)
{
 width = height = length ;
}
bool Rectangle :: isSquare(){
    if(width == height){
        return true;
    }
    else {
        return false;
    }
}

Rectangle :: Rectangle(const Rectangle &rect)
{
    this -> width = rect.width;
    this -> height = rect.height; 
}
int main() {
    Rectangle rect1;
    Rectangle rect2(3, 5);
    Rectangle rect3(3);
    Rectangle dest(rect1); 

   if(rect1.isSquare()){
        cout << "rect1은 정사각형입니다." << endl;
    }
    if (rect2.isSquare()){
        cout << "rect2는 정사각형입니다." << endl;
    }
    if (rect3.isSquare()){
        cout << "rect3은 정사각형입니다." << endl;
    }
    

  
}