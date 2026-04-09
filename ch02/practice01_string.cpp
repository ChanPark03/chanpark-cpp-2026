#include <iostream>
using namespace std;

void my_strcat(char *str1, char *str2, char *str3); //함수선언 

void my_strcat(char *str1, char *str2, char *str3){
    int temp = 0;
    // 1. str1
       for (int i = 0; i < 10; i++)
    {
        if(str1[i] != '\0')
            str3[i] = str1[i];
        
            else{
            str3[i] = '\0';
            temp = i;
            break;
        }
        }


    for( int j = 0; j < 10 ; j++)
    {
        if(str2[j] != '\0')
        
            str3[temp+j] = str2[j];

        
        else{
            str3[temp+j] = '\0';
            break;
    }
    }
    
}

int main() {

    char firstname[10] = {};
    char lastname[10] = {};
    char fullname[20] = {};
    
    


    cout << "이름을 입력하세요>>";
    cin >> firstname;

    cout << "성을 입력하세요>>";
    cin >> lastname;

    my_strcat( firstname,  lastname,  fullname);

    cout << fullname << endl;
    return 0;
}