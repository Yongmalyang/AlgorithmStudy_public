#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k; // 아이템 개수(n)와 최대 무게(k) 입력받기
    vector<pair<int, int>> items(1, {0, 0}); // (무게, 가치) 아이템 저장할 벡터
    int w, v;

    // 각 아이템의 무게(w)와 가치(v)를 입력받아 벡터에 추가
    for (int i = 1; i <= n; i++) {
        cin >> w >> v;
        items.push_back({w, v});
    }

    // 무게에 따라 정렬 (굳이 정렬 안해도 되는데 그냥 써놨음)
    sort(items.begin(), items.end());

    // DP 배열 초기화 (n+1 x k+1 크기의 2차원 배열)
    vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));

    // 냅색 알고리즘 (DP로 해결)
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= k; j++) {
            // 현재 아이템을 넣을 수 있는 경우
            if (j - items[i].first >= 0) {
                dp[i][j] = max(dp[i - 1][j - items[i].first] + items[i].second, dp[i - 1][j]); // 아이템 넣은 경우 vs 안 넣은 경우 중 최대값
            } else {
                dp[i][j] = dp[i - 1][j]; // 아이템 못 넣으면 이전 값 그대로
            }
        }
    }

    // 최종 결과 출력 (최대 가치)
    cout << dp[n][k] << "\n";

    return 0;
}
