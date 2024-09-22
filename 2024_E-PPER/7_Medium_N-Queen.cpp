#include <vector>
using namespace std;

// row: 현재 놓는 행
// n: 체스판 크기
// columns: 열에 퀸이 배치되었는가?
// diag_up: 오른쪽 위 왼쪽 아래에 퀸이 있는가?
// diag_down: 오른쪽 아래 왼쪽 위에 퀸이 있는가?

/*
일일히 체크해서 찾아가는 방식!!
일단 첫 행에 내려놓고 재귀로 계속 찾음. 
끝에 도달했고 놓을 수 있는 경우의 수가 있다?? 그럼 +1.
for문 돌면서 모든 경우의 수 돌기.
*/

/*
체크 포인트! 
대각선 체크가 까다로우니 배열 따로 생성해서 관리
*/

int backtracking(int row, int n, vector<bool>& columns, vector<bool>& diag_up, vector<bool>& diag_down) {
    // n개의 퀸을 모두 배치한 경우
    if (row == n) {
        return 1; // 가능한 배치 하나를 찾음! 리턴
    }

    int answers = 0;
    // 현재 행에서 모든 열 탐색
    for (int col = 0; col < n; ++col) {
        // 퀸을 현재 위치에 놓을 수 없으면 건너뜀 
        if (columns[col] || diag_up[row + col] || diag_down[row - col + n - 1]) {
            continue;
        }

        // 퀸을 (x, y)에 배치
        columns[col] = true; // 해당 열 사용 표시
        diag_up[row + col] = true; // '/' 방향 대각선 사용 표시
        diag_down[row - col + n - 1] = true; // '\' 방향 대각선 사용 표시

        // 다음 행으로 넘어가 퀸을 배치하며 가능한 배치 방법을 재귀적으로 찾음
        answers += backtracking(row + 1, n, columns, diag_up, diag_down);

        // 백트래킹: 다른 경로 탐색을 위해 퀸을 회수 (상태 복원)
        columns[col] = false;
        diag_up[row + col] = false;
        diag_down[row - col + n - 1] = false;
    }

    return answers; // 가능한 배치의 총 수 반환
}

// n-Queens 문제 해결을 위한 함수
// n: 체스판의 크기 (n x n)
int solution(int n) {
    vector<bool> columns(n, false); // 열 사용 여부 체크 배열
    vector<bool> diag_up(2 * n - 1, false); // '/' 방향 대각선 사용 여부 체크 배열
    vector<bool> diag_down(2 * n - 1, false); // '\' 방향 대각선 사용 여부 체크 배열

    // 백트래킹을 시작하여 가능한 배치 수를 반환
    return backtracking(0, n, columns, diag_up, diag_down);
}
