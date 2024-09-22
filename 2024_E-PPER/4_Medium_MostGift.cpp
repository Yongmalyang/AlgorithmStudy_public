/*
* 23회(24-2) E-PPER 기출문제 난이도 중 4번
* 프로그래머스: 가장 많이 받은 선물
* https://school.programmers.co.kr/learn/courses/30/lessons/258712?language=cpp
*/

#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

// 공백으로 분리된 이름 끊어주는 함수
vector<string> splitNameString(string s){
    vector<string> GiverTaker;
    istringstream iss(s);
    string word;
    
    // 공백을 기준으로 문자열을 하나씩 분리
    while (iss >> word) {
        GiverTaker.push_back(word);
    }
    return GiverTaker;
}

// 해당 이름의 인덱스 반환
int returnNameIndex(vector<string> friends, string name){
    for(int i=0; i<friends.size(); i++){
        if(friends[i] == name) return i;
    }
    return 0;
}

int solution(vector<string> friends, vector<string> gifts) {
    int answer = 0;
    int n = friends.size();
    
    vector<int> gift_tmp(n, 0);
    vector<vector<int>> gift_exchange(n, gift_tmp);
    vector<int> gift_factor(n, 0);
    
    // 각각 주고받은 선물 기록
    for(int i=0; i<gifts.size(); i++){
        vector<string> s = splitNameString(gifts[i]);
        int giver = returnNameIndex(friends, s[0]);
        int taker = returnNameIndex(friends, s[1]);
        
        gift_exchange[giver][taker]++;
    }
    
    // 각각의 총 준, 받은 선물과 선물 지수 기록
    for(int i=0; i<n; i++){
        int gifts_given = 0;
        int gifts_taken = 0;
        for(int j=0; j<n; j++){
            // 준 선물
            gifts_given += gift_exchange[i][j];
            gifts_taken += gift_exchange[j][i];
        }
        gift_factor[i] = gifts_given - gifts_taken;
    }
    
    vector<int> total_received_gifts(n, 0);
    
    // 최종적으로 각자가 받은 선물의 수
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(i<j){
                int itoj = gift_exchange[i][j];
                int jtoi = gift_exchange[j][i];
                
                // 둘이 선물을 주고받은 기록이 있고 수가 같지 않다면
                if(itoj+jtoi > 0 && itoj != jtoi){
                    if(itoj > jtoi) total_received_gifts[i]++;
                    else total_received_gifts[j]++;
                }
                // 그 이외 (기록 없거나 수가 같음)
                else{
                    if(gift_factor[i] > gift_factor[j]) total_received_gifts[i]++;
                    else if(gift_factor[i] < gift_factor[j]) total_received_gifts[j]++;
                }
            }
        }
    }
    
    answer = *max_element(total_received_gifts.begin(), total_received_gifts.end());
    return answer;
}