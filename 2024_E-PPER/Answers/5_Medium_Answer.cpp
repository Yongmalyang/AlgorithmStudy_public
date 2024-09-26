#include <iostream>
#include <string>

using namespace std;

bool canEat(int start, int end, string& hamburger) {
    for (int j = start; j <= end; j++) {
        if (j >= 0 && j < hamburger.length() && hamburger[j] == 'H') {
            hamburger[j] = 'E'; // 먹은 햄버거를 E로 표시
            return true;
        }
    }
    return false;
}

int solution(int n, int k, string hamburger) {
    int ans = 0;
    for (int i = 0; i < hamburger.length(); i++) {
        if (hamburger[i] != 'P') { // 사람이 아니라면 패스
            continue;
        }
        // 먼저 왼쪽에서부터 햄버거를 먹을 수 있는지 확인
        if (canEat(i - k, i - 1, hamburger)) {
            ans++;
        } else if (canEat(i + 1, i + k, hamburger)) {  // 오른쪽에서 먹을 수 있는지 확인
            ans++;
        }
    }
    return ans;
}

int main() {
    int n, k;
    cin >> n >> k;
    string hamburger;
    cin >> hamburger;

    cout << solution(n, k, hamburger);
    return 0;
}
