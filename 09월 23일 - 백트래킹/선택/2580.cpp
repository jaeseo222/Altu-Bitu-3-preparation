#include <iostream>
using namespace std;

const int MAX = 9; //스도쿠 한 행 사이즈

int sudoku[MAX][MAX]; //스도쿠
bool row[MAX][MAX + 1]; //x행에 숫자 y가 있으면 row[x][y] = true
bool col[MAX][MAX + 1]; //x열에 숫자 y가 있으면 col[x][y] = true
bool square[MAX][MAX + 1]; //x번째 작은 정사각형에 숫자 y가 있으면 true

/* 스도쿠 각 칸들을 넘버링하자
 * 0 1 2 3 4 5 6 7 8
 * 9 ............. 17
 * .
 * .
 * .
 * 72 ............ 80
 * */

/* 3x3 정사각형을 다음과 같이 넘버링하자
 * 0 1 2
 * 3 4 5
 * 6 7 8
 * */

// row행 col열의 숫자가 위치한 3x3 정사각형 구하는 함수
int getSquare(int row, int col){
    return (row/3)*3 + (col/3);
}


// num번째 칸에 숫자 채우는 함수
bool fillSudoku(int num){

    if(num == 81) { //80번째 칸까지 다 돌았으면 종료
        return true;
    }

    //num번째 칸의 행, 열 구하기
    int x = num / 9; int y = num % 9;

    if(sudoku[x][y]){ //빈칸이 아닌 경우-> 다음 칸으로 넘어가기
        return fillSudoku(num+1);
    }

    for(int i=1; i<=9; i++){ //빈칸인 경우-> 숫자 채우기
        //가로줄, 세로줄, 3x3정사각형에 모두 없는 숫자이면 채운다
        if(!row[x][i] && !col[y][i] && !square[getSquare(x, y)][i]){
            row[x][i] = true;
            col[y][i] = true;
            square[getSquare(x, y)][i] = true;
            sudoku[x][y] = i;

            if(fillSudoku(num+1)){
                return true;
            }

            // 다시 돌려놓기
            row[x][i] = false;
            col[y][i] = false;
            square[getSquare(x, y)][i] = false;
            sudoku[x][y] = 0;
        }
    }

    return false;
}

int main(void){

    //입력
    for(int i=0; i<9; i++){
        for(int j=0; j<9; j++){
            cin >> sudoku[i][j];

            if(sudoku[i][j]){ // 빈칸이 아닌 경우 -> row, col, square 초기화
                row[i][sudoku[i][j]] = true;
                col[j][sudoku[i][j]] = true;
                square[getSquare(i, j)][sudoku[i][j]] = true;
            }
        }
    }

    //연산
    fillSudoku(0);

    //출력
    for(int i=0; i<9; i++){
        for(int j=0; j<9; j++){
            cout << sudoku[i][j] << ' ';
        }
        cout << '\n';
    }

    return 0;

}
