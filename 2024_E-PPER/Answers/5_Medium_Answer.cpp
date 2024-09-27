#include <iostream>
#include <string>

using namespace std;

// 먹을 수 있는가? bool 반환, start, end, hamburger를 파라미터로 받음
bool canEat(int start, int end, string& hamburger) {
    // start부터 end까지 돌리기
    for (int j = start; j <= end; j++) {
        // j가 배열 범위 내에 있으면서!! 햄버거가 존재한다면?
        if (j >= 0 && j < hamburger.length() && hamburger[j] == 'H') {
            // 햄버거는 ~Eaten~
            hamburger[j] = 'E'; // 먹은 햄버거를 E로 표시
            // true 반환
            return true;
        }
    }
    // 머 없으면 false
    return false;
}

// 솔루션 함수. 
// n은 햄버거와 사람의 총 개수
// k는 사람이 햄버거를 먹을 수 있는 거리
// hamburger는 햄버거와 사람의 배열
int solution(int n, int k, string hamburger) {
    // 정답 0 초기화
    int ans = 0;

    // for문 돌면서 (햄버거배열 길이만큼)
    for (int i = 0; i < hamburger.length(); i++) {
        // 햄버거면 그냥 지나가기
        if (hamburger[i] != 'P') { 
            continue;
        }

        // 사람이라면?
        // 먼저 왼쪽에서부터 햄버거를 먹을 수 있는지 확인
        // 팔 닿는 i-k부터 바로 왼쪽인 i-1까지
        if (canEat(i - k, i - 1, hamburger)) {
            // 먹을 수 있다면 ++
            ans++;
        // 오른쪽도!
        } else if (canEat(i + 1, i + k, hamburger)) {  // 오른쪽에서 먹을 수 있는지 확인
            // 먹을 수 있다면 ++
            ans++;
        }
    }
    // 정답 return!
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
