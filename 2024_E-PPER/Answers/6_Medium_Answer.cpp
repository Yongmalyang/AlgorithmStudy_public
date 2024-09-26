#include<vector>
using namespace std;

int dp(int n, int m, vector<vector<int>> &board) {
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (board[i - 1][j - 1]) {
                dp[i][j] = min(min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]) + 1;
            }
            ans = max(ans, dp[i][j]);
        }
    }
    return ans;
}

int solution(vector<vector<int>> board) {
    int n = board.size();
    int m = board[0].size();
    int square_len = dp(n, m, board);
    return square_len * square_len;
}