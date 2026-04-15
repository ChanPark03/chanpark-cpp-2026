#include <iostream>
using namespace std;

class Bubble{
    int radius;

public: 
    Bubble(int radius) { this -> radius = radius;}
    int getRadius() { return radius;}
    void setRadius(int n) { radius = n;}
};

    bool combineBubble(Bubble &a, Bubble &b){
      
      if(a.getRadius() != b.getRadius()){
        
        if(a.getRadius() > b.getRadius())
            //b=a ;
            b.setRadius(a.getRadius());
        
        else
            //a=b;
            a.setRadius(b.getRadius()); 

        return true;
        
    }
        return false;
    }

int main() {
    Bubble a(30), b(10);
    if (combineBubble(a, b) == false)
        cout << "두 버블의 크기가 같음" << endl;
        
    else 
        cout << "큰 쪽으로 병합됨" <<endl;
    
    cout << "버블 a의 반지름" << a.getRadius() << endl;
    cout << "버블 b의 반지름" << b.getRadius() << endl;

        
    

    return 0;
}