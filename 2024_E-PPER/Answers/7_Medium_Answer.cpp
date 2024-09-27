#include <vector>
using namespace std;

// 백트래킹 함수 
// 파라미터: row, n, columns, diag_up, diag_down
int backtracking(int row, int n, vector<bool>& columns, vector<bool>& diag_up, vector<bool>& diag_down) {
    // n개의 퀸을 모두 배치한 경우
    if (row == n) {
        // 해답 1개 찾음
        return 1;
    }

    // 정답 0으로 설정
    int answers = 0;

    // n개의 col 뒤지면서 탐색!!
    for (int col = 0; col < n; ++col) {
        // 퀸 못 놓으면 지나가기. 
        // columns[col]: 해당 열에 이미 퀸을 내려놨는가
        // diag_up[row + col]: 상향 대각선에 퀸이 있는가
        // diag_down[row - col + n - 1]: 하향 대각선에 퀸이 있는가
        if (columns[col] || diag_up[row + col] || diag_down[row - col + n - 1]) {
            continue;
        }

        // continue에 걸리지 않았다면!!
        // colums[col], diag_up[row+col], diag_down[row-col+n-1] 다 내려두기
        columns[col] = true;
        diag_up[row + col] = true;
        diag_down[row - col + n - 1] = true;

        // 재귀로 호출, row만 +1, answer에다가 호출된 결과
        answers += backtracking(row + 1, n, columns, diag_up, diag_down);

        // 다시 원상복귀! colums, diag_up, ...
        columns[col] = false;
        diag_up[row + col] = false;
        diag_down[row - col + n - 1] = false;
    }

    // 마지막에 return
    return answers;
}

// 정답 함수
int solution(int n) {
    // 열 체크
    vector<bool> columns(n, false); 
    // 상향 대각선 체크 (길이 2 이상의 대각선 개수는 2n-1)
    vector<bool> diag_up(2 * n - 1, false); 
    // 하향 대각선 체크 (길이 2 이상의 대각선 개수는 2n-1)
    vector<bool> diag_down(2 * n - 1, false); 

    // 백트래킹 함수 호출 (0번째 row, n, colums, diag_up, diag_down)
    return backtracking(0, n, columns, diag_up, diag_down);
}
