#include <iostream>
using namespace std;

class Coffe
{
private:
    int water, espresso, sugar, cream;
public:
    Coffe(int water = 1, int coffe = 1, int sugar = 0, int cream = 0){
        this -> water = water; this -> espresso = coffe;
        this -> sugar = sugar; this -> cream = cream;
    }
    void show(){
        cout << "물 " << water << ", 커피" << espresso;
        cout << ", 설탕" << sugar << ", 크림 " << cream << endl;
    }
    Coffe operator +(Coffe op2){
        Coffe tmp;
        tmp.water = this -> water + op2.water;
        tmp.espresso = this -> espresso + op2.espresso;
        tmp.sugar = this -> sugar + op2.sugar;
        tmp.cream = this -> cream +op2.cream;
        
        return tmp;
     }
    
    Coffe operator +(int n){
        Coffe tmp;
        tmp.water = this -> water;
        tmp.espresso = this -> espresso + n;
        tmp.sugar = this -> sugar;
        tmp.cream = this -> cream;
        
        return tmp;
    }

};





int main() {
    Coffe black(2, 5, 0, 0), dabang(2, 2, 2, 2), c, d;
    c = black + dabang;
    d = c + 1;
    c.show(); 
    d.show();

    

    return 0;
}