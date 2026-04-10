#include <iostream>
#include <string>
using namespace std;

class Account {
private:
    string name;
    int balance;

public:
    Account(string name);
    string getOwner();
    void deposit(int d);
    int withdraw(int w);
    int inquiry();
};

Account :: Account(string n) {
    name = n;
    balance = 0;
}

string Account :: getOwner() {
    return name;
}

void Account :: deposit(int d) {
    balance += d;
    
}

int Account :: withdraw(int w) {
    if(w > balance) {     // 출금액이 잔액보다 크면
        w = balance;      // 잔액만큼만 출금
        balance = 0;
    } else {
        balance -= w;
    }
    return w;
}

int Account :: inquiry() {
    return balance;
}

int main() {
    Account a("황수희");
    a.deposit(20000);
    cout << a.getOwner() << " 잔액은 " << a.inquiry() << endl;

    int money = a.withdraw(15000);
    cout << money << "원 출금, ";
    cout << a.getOwner() << " 잔액은 " << a.inquiry() << endl;

    money = a.withdraw(8000);
    cout << money << "원 출금, ";
    cout << a.getOwner() << " 잔액은 " << a.inquiry() << endl;
}