#include <iostream>
#include <string>
using namespace std;
class WordUtility
{
private:
    
public:
    static int wordCount(string);
    static string getWord(string str, int n);
   
};

int WordUtility::wordCount(string str){
    int count = 0;
    for ( int i = 0; i < str.length(); i++)
    {
        
        if(str[i] == ' ')
        count ++;

        
    }
    return count+1;
}

string WordUtility::getWord(string str, int n){
    
     
     string word;
     int ea = 0;
           
        for (int i = 0; i < str.length(); i++)
        {
            if (str[i] == ' ')
                ea++;
            if(ea == n-1 && str[i] != ' ')
            word += str[i];
        }
        
      return word;
}


int main()
{
    int n = WordUtility ::wordCount("I love C++ and C"); // 단어 갯수 리턴
    cout << "단어 개수는 " << n << endl;
    string word = WordUtility ::getWord("I love C++ and C", 6); // 3번째 단어 리턴
    if (word == "")                                       // 해당 번째 단어가 없는경우
        cout << "3번째 단어는 없습니다." << endl;

    else
        cout << "3번째 단어는" << word << endl;

    return 0;
}