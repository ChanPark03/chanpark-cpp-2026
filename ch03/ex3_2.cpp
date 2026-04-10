#include <iostream>
using namespace std;

// 직사각형을 나타내는 클래스
class Rectangle {
public:
    int width;   // 가로 길이
    int height;  // 세로 길이

    int getArea();           // 넓이 반환 함수 선언

    Rectangle();             // 기본 생성자 (가로, 세로 모두 1)
    Rectangle(int w);        // 가로, 세로를 동일한 값으로 초기화 (정사각형)
    Rectangle(int w, int h); // 가로, 세로를 각각 초기화
};

// 기본 생성자: 가로, 세로를 1로 초기화
Rectangle::Rectangle() {
    width = 1;
    height = 1;
    cout << "width= " << width << ", height = " << height << endl;
}

// 인자 1개 생성자: 가로, 세로중 둘중하나를 초기화 (정사각형)  생성자에서는 인자를 구분하지 못함.
Rectangle::Rectangle(int w) {
    width = w;
    height = 8;
}

// 인자 2개 생성자: 가로, 세로를 각각 초기화
Rectangle::Rectangle(int w, int h) {
    width = w;
    height = h;
}

// 직사각형의 넓이(가로 * 세로)를 반환
int Rectangle::getArea() {
    return width * height;
}

int main() {
    Rectangle rect;                  // 기본 생성자 호출 (1x1)
    double area = rect.getArea();
    cout << "사각형의 면적은 " << area << endl;

    Rectangle rect2(7);              // 7xh의 초기화값 정사각형
    area = rect2.getArea();          // rect2의 넓이 계산
    cout << "사각형의 면적은 " << area << endl;

    Rectangle rect3(3, 5);           // 3x5 직사각형
    area = rect3.getArea();          // rect3의 넓이 계산
    cout << "사각형의 면적은 " << area << endl;

    return 0;
}
