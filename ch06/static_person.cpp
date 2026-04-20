#include <iostream>
using namespace std;

class Person
{
    private:
    /* data */
    public:
    int money;
    void addMoney(int money);
    
    static int sharedMoney;
    static void addShared(int n);
    
    Person(/* args */);
    ~Person();
};


void Person::addMoney(int money){
    this -> money += money;
}

int Person::sharedMoney = 10;

void Person::addShared(int n){
    sharedMoney += n;
    
}

Person::Person(/* args */)
{}

Person::~Person()
{}

int main() {
    Person han;
    han.money = 100;
    han.sharedMoney = 200;

    Person lee;
    lee.money = 150;
    lee.addMoney (200);
    lee.addShared (200);
    

    cout << han.money << ' '
        << lee.money << endl;
       
    cout << han.sharedMoney << ' '
        << lee.sharedMoney << endl; 

    return 0;
}
