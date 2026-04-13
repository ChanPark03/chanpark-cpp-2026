#include <iostream>
using namespace std;

class myArray
{

private :
     int *p;
    int size;
public:
    
    
    myArray* this_point(){return this;};
    void sum();
    void print();
   
    myArray(/* args */);
    myArray(int num);
    ~myArray();
};  
myArray::myArray(int num)
{
   p = new int [num];
   size = num;
    
}
void myArray::sum()
{
    int total = 0;
    for (int i = 0; i < size; i ++)
    {
      
        total += p[i];
    }
    cout << total << endl;

}

void myArray::print()
{
   
   
    for (int i = 0; i < size; i++)
    {
        cout << p[i] << endl;
    }
   
}

myArray::~myArray()
{
       if(p != nullptr)      //  null 체크 후 해제
        delete[] p;

}

int main() {
    myArray test[3] = {myArray(3), myArray(3), myArray(3)}; // {3,3,3}이렇게 작성해도 무방함.

    myArray* p = test[0].this_point();

   

    // int val = 1;
    // for (int i = 0; i < 3; i++)
    // {
    //     for (int j = 0; j < test[i].size; j++){

    //         test [i].p[j] = val++;
    //         cout << test[i].p[j] << " ";
    //     }
    //     cout << endl;
        
    // }
    // cout << endl;
    
    
    
}