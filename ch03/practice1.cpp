#include <iostream>
using namespace std;

class Picture {

private: 
    
    int width;
    int height;
    string mountain;

public:
    int getWidth();
    int getHeight();
    string getPlace();

    Picture();
    Picture(int w, int h, string m);

};

int Picture :: getWidth(){
    return width;
}

int Picture :: getHeight(){
    return height;
}

string Picture :: getPlace(){
    return mountain;
}

 Picture :: Picture() {
    width = 5;
    height = 7;
    mountain = "모름";
}

Picture :: Picture(int w, int h, string m){
    width = w;
    height = h;
    mountain = m;
}


int main() {


    Picture pic; // 5x7 크기, 촬영 장소 "모름"
    Picture mt(10, 14 ,"한라산"); //10x14 크기, 촬영장소 "한라산"
    cout << pic.getWidth() << "x" << pic.getHeight() << " " << pic.getPlace() << endl;
    cout << mt.getWidth() << "x" << mt.getHeight() << " " << mt.getPlace() << endl;


    
}