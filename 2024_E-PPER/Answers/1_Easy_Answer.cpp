#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 솔루션 함수
// 파라미터: times
int solution(vector<int>& times) {
    // 알고리즘으로 정렬하기
    sort(times.begin(), times.end());

    // 정답
    int answer = 0;
    // 누적할 변수
    int prev = 0; 

    // times 길이만큼 반복
    for (int t : times) {
        // 누적할 변수에 iter 더해주기
        prev += t;
        // 정답에 누적값 더해주기
        answer += prev;
    }

    // 정답 반환
    return answer;
}

int main() {
    int n;
    cin >> n;
    vector<int> times(n);
    for (int i = 0; i < n; ++i) {
        cin >> times[i]; 
    }

    cout << solution(times) << '\n';

    return 0;
}