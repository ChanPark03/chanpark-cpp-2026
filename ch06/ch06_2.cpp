#include <iostream>
using namespace std;

int printMatrix(int row = 2, int col = 2, char s = '*') {
    for (int i = 0; i < row; i++) {      // 행만큼 반복
        for (int j = 0; j < col; j++) {  // 열만큼 반복
            cout << s;                    // 문자 출력
        }
        cout << endl;                     // 한 행이 끝나면 줄바꿈
    }
    return 0;
}

int main() {
    printMatrix();          // row=2, col=2, s='*' (전부 디폴트)
    printMatrix(2, 5, 'a'); // row=2, col=5, s='a'
    printMatrix(1, 10);     // row=1, col=10, s='*' (s만 디폴트)

    return 0;
}