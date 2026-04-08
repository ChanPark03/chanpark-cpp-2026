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
   

    for ( i = 0; i < 10; i++)
    {
        if(firstname[i] != '\0')
            fullname[i] = firstname[i];
        
            else{
            fullname[i] = '\0';
            break;
        }
        }


    for( j = 0; j < 10 ; j++)
    {
        if(lastname[j] != '\0')
        
            fullname[i+j] = lastname[j];

        
        else{
            fullname[i+j] = '\0';
            break;
    }
    }

    cout << fullname << "\n";
   
  

    }
