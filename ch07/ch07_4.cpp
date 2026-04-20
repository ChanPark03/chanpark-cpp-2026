#include <iostream>
using namespace std;

class Power
{
private:
    int kick;
    int punch; 
public:
    Power(int kick = 0, int punch = 0);
    void show();
    Power operator+(Power op2);
    bool operator == (Power op2);
    Power& operator +=(Power op2);

};

Power::Power(int kick, int punch)
{
    this-> kick = kick;
    this-> punch = punch;
}

void Power :: show(){
    cout << "kick =" << kick << ',' << "punch =" << punch << endl;
}

Power Power :: operator+(Power op2){
    Power tmp;
    tmp.kick = this -> kick + op2.kick;
    tmp.punch = this -> punch + op2.punch;
    return tmp;
}

bool Power::operator==(Power op2){
    if (kick == op2.kick && punch == op2.punch) 
        return true;
    
    else   
        return false;
}
 Power& Power::operator +=(Power op2){
    kick = kick + op2.kick;
    punch = punch + op2.punch;
    return *this;
 }
int main() {
    Power a(3,5), b(4,6), c;
    c = a.operator+(b);
    a.show();
    b.show();
    c.show();

    if (a == b) cout << "두 파워가 같다." << endl;
    else cout << "두 파워가 같지 않다." << endl;
    
    c= a+=b;
    c.show();

    
  
}   