#include <iostream>
#include <string>
using namespace std;
void my_strcat(const string str1, const string str2, string *str3);


void my_strcat(const string str1, const string str2, string *str3){
   *str3 = str1 + str2;
   
    
    
}

int main() {

    string firstname;
    string lastname;
    string fullname;

    

    cout << "이름을 입력하세요>>";
    cin >> firstname;

    cout << "성을 입력하세요>>";
    cin >> lastname;

    my_strcat( firstname,  lastname, &fullname);

    cout << fullname << endl;
    return 0;
}