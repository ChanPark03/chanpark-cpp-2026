#include <iostream>
using namespace std;

class Storage{
private:
    
    


public:
    //변수
    double data[10];
    int next;

    //함수
    void put(double temp);
    void dump();
    double getAvg();
    Storage(/* args */);
};

// 함수 구현 
void Storage :: put(double temp){
    data[next] = temp;
    next++;
}

void Storage :: dump(){
for (int i = 0; i < next; i++)
{
    cout << data[i] << "  ";
}

}

double Storage :: getAvg(){

    double sum = 0.0;
    double avg = 0;
    
    for (int i = 0; i < next; i++)
    {
       sum = data[i] + sum;
    }
         avg = sum / next;
    return avg;
    }

//생성자 구현
Storage :: Storage(/* args */){

    for (int i = 0; i < 10; i++)
    {
        data[i] = 0;
    }

    next = 0;
}

int main() {

    Storage a;
    a.put(36.7); // 체온 36.7 저장
    a.put(36.9); // 체온 36.9 저장
    a.put(36.4); // 체온 36.4 저장
    a.dump(); // a 에 저장된 모든 체온 값 출력
    cout << "평균 체온은 " << a.getAvg() <<"입니다." << endl;

    return 0;
}