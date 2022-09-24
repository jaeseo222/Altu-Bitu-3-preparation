#include <iostream>
using namespace std;

const int MAX = 9; //스도쿠 한 행 사이즈

int sudoku[MAX][MAX]; //스도쿠
bool row[MAX][MAX + 1]; //x행에 숫자 y가 있으면 row[x][y] = true
bool col[MAX][MAX + 1]; //x열에 숫자 y가 있으면 col[x][y] = true
bool square[MAX][MAX + 1]; //x번째 작은 정사각형에 숫자 y가 있으면 true

/**
 * 가지치기 효율: 80ms
 *
 * 9X9의 스도쿠에서 각 행, 열, 3x3 사각형에 1~9가 존재하는지 체크하는 2차원 배열 활용
 * 각 2차원 배열의 행: 어느 부분에 대한 체크인지(행, 열, 3x3), 0번 인덱스부터 시작
 * 각 2차원 배열의 열: 1 ~ 9 숫자 체크
 *
 * 행과 열은 바로 사용하면 됨
 * (ex) row[3][2] = true;  //3행에 2라는 숫자가 존재한다는 것
 *      col[8][9] = false; //8열에 9라는 숫자가 존재하지 않는다는 것
 *
 * 3x3 사각형 (하나를 각 구역이라고 표현)
 * -> 행을 3으로 나눈 몫과 열을 3으로 나눈 몫으로 구역 0부터 8까지 다음과 같이 나타낼 수 있음
 * (0,0) (0,1) (0,2)
 * (1,0) (1,1) (1,2)
 * (2,0) (2,1) (2,2)
 * -> 1차원 배열 인덱스로 구분하기 위해 각 (행 / 3)값에 3을 곱한 후 (열 / 3)을 더함
 * -> 따라서 3x3 사각형의 구간은 (row / 3) * 3 + (col / 3) = 0 ~ 8인 구간으로 나눌 수 있음
 */

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

    if(num == MAX* MAX) { //80번째 칸까지 다 돌았으면 종료
        return true;
    }

    //num번째 칸의 행, 열 구하기
    int r = num / MAX; int c = num % MAX;

    if(sudoku[r][c]){ //빈칸이 아닌 경우-> 다음 칸으로 넘어가기
        return fillSudoku(num+1);
    }

    int square_num = getSquare(r, c); //3x3 정사각형 번호

    for(int i = 1; i <= MAX; i++){ //빈칸인 경우-> 숫자 채우기
        //가로줄, 세로줄, 3x3정사각형에 모두 없는 숫자이면 채운다
        if(!row[r][i] && !col[c][i] && !square[square_num][i]){
            row[r][i] = true;
            col[c][i] = true;
            square[square_num][i] = true;
            sudoku[r][c] = i;

            if(fillSudoku(num+1)){
                return true;
            }

            // 다시 돌려놓기
            row[r][i] = false;
            col[c][i] = false;
            square[square_num][i] = false;
            sudoku[r][c] = 0;
        }
    }

    return false;
}

int main(void){

    //입력
    for(int i = 0; i < MAX; i++){
        for(int j = 0; j < MAX; j++){
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
    for(int i = 0; i < MAX; i++){
        for(int j = 0; j < MAX; j++){
            cout << sudoku[i][j] << ' ';
        }
        cout << '\n';
    }

    return 0;

}
