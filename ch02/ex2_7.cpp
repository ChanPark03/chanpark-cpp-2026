#include <iostream>
#include <cstring>

using namespace std;

int main() {
    char password[11];
    cout << "암호를 입력하세요."<< endl;

    while (true)
    {
        cout << "암호>>";
        cin >> password; 
        if(strcmp(password, "C++")==0){
            cout << "올바른 암호입니다.\n";
            break;
        }
        else
            cout << "암호가 틀립니다" << endl;
    }
    


    return 0;
}