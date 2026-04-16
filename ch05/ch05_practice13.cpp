#include <iostream>
using namespace std;

class Collector{
    int *p;
    int size = 0;
public:
    Collector(int size, int values[]);
    void show();
    int getSize() { return size; }
    int get(int index) { return p[index]; }
};
    
Collector::Collector(int size, int values[]){
    this -> size = size;
    this -> p = new int [size];
    for (int i = 0; i < size; i++)
    {
        this -> p[i] = values[i];
    }
 }
void Collector::show(){

    cout << "데이터 수 " << size << ": ";
    for (int i = 0; i < size; i++)
    {
        cout << p[i] << " ";
    }
    
}
double calcAvg(const Collector &c){

}
int main() {

    int temp[] = {69, 70, 71, 72, 73, 74};
    Collector weight(4, temp);
    double avg = calcAvg(weight);
    weight.show();
    cout << "평균 몸무게는 " << avg << "kg 입니다." << endl;
    

    
}

/*
실행결과
데이터수 4: 69 70 71 72
평균 몸무게는 70.5kg 입니다.
*/