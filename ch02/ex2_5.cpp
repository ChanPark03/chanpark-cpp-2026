#include <iostream>
#include <cstring>
using namespace std;
int main() {

    char firstname[10] = {};
    char lastname[10] = {};
    char fullname[20] = {};
    int i = 0;
    int j = 0;
    


    cout << "이름을 입력하세요>>";
    cin >> firstname;

    cout << "성을 입력하세요>>";
    cin >> lastname;
    while( firstname[i]!='\0'){
        
        fullname[i]= firstname[i];
        i++;
        
    } 
    
    while(lastname[j] != '\0'){
        
    
       fullname[i+j]= lastname[j];
       j++;
        
    }

  cout << fullname << "\n";
   
    //cout <<"이름은"<< lastname <<firstname<< "입니다\n";

    }
