#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <sstream>

using namespace std;

// 솔루션 함수
// friends: 친구들 이름
// gifts: 선물교환 배열
int solution(vector<string> friends, vector<string> gifts) {
    // n: 친구 수
    int n = friends.size();
    // map으로 gift_dict 만들기. 이름->인덱스 정해주는거임!
    map<string, int> gift_dict;
    // 선물 교환 테이블
    vector<vector<int>> gift_table(n, vector<int>(n, 0));
    // 각 친구의 선물 점수
    vector<int> gift_score(n, 0);
    // 각 친구의 총 선물 수
    vector<int> total_gift(n, 0);
    
    for (int i = 0; i < n; ++i) {
        // dict에 순서대로 인덱스 부여!
        gift_dict[friends[i]] = i;
    }
    
    // 선물교환 내역을 받아서
    for(string gift : gifts) {
        // a, b 선언한다음
        string a, b;
        
        stringstream ss (gift);
        // stringstream이라는 걸 만들어서 a, b에 순서대로 넣어주기
        ss >> a >> b;
        
        // 선물 주->받 사람의 교환 테이블 업데이트
        gift_table[gift_dict[a]][gift_dict[b]]++;
        // 주는 사람 점수 업, 받는 사람 점수 다운
        gift_score[gift_dict[a]]++;
        gift_score[gift_dict[b]]--;
    }
    
    // n번만큼 이중 for문 반복
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            // 자기 자신에게 준 경우 패스
            if (i == j) continue;
            // i가 j에게 준 선물 많으면 i 총선물 증가
            if (gift_table[i][j] > gift_table[j][i]) {
                total_gift[i] += 1;
            } 
            // 같으면??
            else if (gift_table[i][j] == gift_table[j][i]) {
                // 점수가 높으면 i 총 선물 증가
                if (gift_score[i] > gift_score[j]) {
                    total_gift[i] += 1;
                }
            }
        }
    }
    
    // total 중에서 최대 gift 찾기
    int max_gift = total_gift[0];
    for (int i = 1; i < total_gift.size(); ++i) {
        if (total_gift[i] > max_gift) {
            max_gift = total_gift[i];
        }
    }
    // 최댓값 반환
    return max_gift;
}