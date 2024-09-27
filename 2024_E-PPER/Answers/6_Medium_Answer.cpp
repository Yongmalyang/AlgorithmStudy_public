#include<vector>
using namespace std;

// dp 함수. 파라미터: n, m, board
int dp(int n, int m, vector<vector<int>> &board) {
    // 2차원 배열 dp, 크기는 n+1 x m+1
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    // 정답 answer
    int ans = 0;

    // 반복하면서 찾기!! 1부터 n까지
    for (int i = 1; i <= n; i++) {
        // 또 반복. 1부터 m까지
        for (int j = 1; j <= m; j++) {
            // board[i-1][j-1]이 1이면 거기에 놓을 수 있다는 뜻!
            if (board[i - 1][j - 1]) {
                // i-1, j
                // i, j-1
                // i-1, j-1중에 최솟값에 1 더해서 i, j에 넣어주기
                dp[i][j] = min(min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]) + 1;
            }
            // ans에 최댓값 갱신
            ans = max(ans, dp[i][j]);
        }
    }
    // 정답 return
    return ans;
}

// 솔루션 함수
int solution(vector<vector<int>> board) {
    // n은 board의 크기
    int n = board.size();
    // m은 board[0]의 크기
    int m = board[0].size();

    // dp 돌려서 변수에 넣기
    int square_len = dp(n, m, board);
    // 해당 변수로 넓이 구하기
    return square_len * square_len;
}