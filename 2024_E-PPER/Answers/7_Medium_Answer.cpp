#include <vector>
using namespace std;

int backtracking(int row, int n, vector<bool>& columns, vector<bool>& diag_up, vector<bool>& diag_down) {
    // n개의 퀸을 모두 배치한 경우
    if (row == n) {
        return 1;
    }

    int answers = 0;
    for (int col = 0; col < n; ++col) {
        // 퀸을 놓을 수 있으면
        if (columns[col] || diag_up[row + col] || diag_down[row - col + n - 1]) {
            continue;
        }

        // 퀸 배치
        columns[col] = true;
        diag_up[row + col] = true;
        diag_down[row - col + n - 1] = true;

        answers += backtracking(row + 1, n, columns, diag_up, diag_down);

        // 다음 탐색을 위해 퀸 회수
        columns[col] = false;
        diag_up[row + col] = false;
        diag_down[row - col + n - 1] = false;
    }

    return answers;
}

int solution(int n) {
    vector<bool> columns(n, false); // 열 체크
    vector<bool> diag_up(2 * n - 1, false); // 상향 대각선 체크
    vector<bool> diag_down(2 * n - 1, false); // 하향 대각선 체크

    return backtracking(0, n, columns, diag_up, diag_down);
}
