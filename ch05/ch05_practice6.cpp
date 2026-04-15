#include <iostream>
#include <string>
using namespace std;
class Polygon{
    int size = 0;
    int *xList, *yList;

public:
    Polygon(int size); //생성자. size는 점의개수 
    ~Polygon(); //소멸자
    void read(); // read() 멤버함수
    bool get(int n, int &x, int &y); // get() 멤버함수 

};
    Polygon :: Polygon(int size){
        this->size = size;
        xList = new int[size];  // size만큼 동적 배열 생성
        yList = new int[size];
}
    void Polygon :: read(){
        int x;
        int y;

        for (int i = 0; i < size; i++)
        {
            cin >> x;
            cin >> y; 
            xList[i] = x;
            yList[i] = y;
        }
        
    }

    bool Polygon :: get(int n, int &x, int &y){
        if(n > size || n < 1){
           
        return false;
        }
        else {
             x = xList[n-1];
             y = yList[n-1];   
            
            return true;
        };
    }
    Polygon::~Polygon() {
    delete[] xList;  // 동적 배열 해제
    delete[] yList;
}


int main() {
    Polygon poly(6);
    poly.read();
    int n=3, x, y;
    bool res = poly.get(n, x, y);

    if(res == true)
        cout << n << "번째 점은 " << "(" << x << ", " << y << ")" << endl;
    
    else 
        cout << n << "번쨰 점은 없습니다." << endl; 
    

    return 0;
}