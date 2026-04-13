#include <iostream>
#include <string>
using namespace std;

int main()
{
    string line;
    string dest;

    cout << "텍스트 입력";
    getline(cin, line, '\n');

    for (int i = 0; i < line.size(); i++)
    {
        if (line[i] == ' ' || line[i] == '\t')
        {

            if (dest.size() > 0 && dest[dest.size() - 1] != ' ' 
                && dest[dest.size()-1] != '\t')  
            {
                dest.append(1, ' ');
            }
             
        }
        else
        {
            dest.append(1, line[i]);
        }
    }
    cout << dest << endl;
    return 0;
}