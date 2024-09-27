#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;
// 솔루션 함수
// 파라미터: board, moves
int solution(vector<vector<int>> board, vector<int> moves) {
    // 뽑은 인형 개수
    int answer = 0; 
    // 통 높이
    int height = board.size(); 
    // 크레인 움직인 횟수
    int moves_cnt = moves.size(); 
    // 바구니 stack으로 구현
    stack<int> basket;

    // moves 개수만큼 크레인 작동시키기
    for(int i = 0; i < moves_cnt; i++) {
        // pos: 크레인 작동 위치
        int pos = moves[i] - 1;  

        // 현재 열에서 가장 위에 있는 칸부터 차례대로 탐색 (코드상에서는 작은숫자부터)
        for(int j = 0; j < height; j++) { 
            // 인형 없으면 넘어가기
            if(board[j][pos] == 0) { 
                continue;
            }

            // 있으면 집기
            // 이건 무슨 인형인가?
            int doll = board[j][pos];
            // 남은 자리는 0으로
            board[j][pos] = 0;

            // 바구니 확인. 
            // 바구니가 텅 비지 않았고 방금 넣은 인형이 바구니 위에 있는거랑 같은 인형이면
            if(!basket.empty() && doll == basket.top()) { 
                // 인형 빼기!
                basket.pop(); 
                // 두 개의 인형 뽑음
                answer += 2;
            }
            // 안 겹치면
            else { 
                // 그냥 인형 넣기
                basket.push(doll); 
            }
            // 해당 열에서 인형 뽑았으니까 넘어가.
            break;
        }

    }
    // 정답 출력.
    return answer;
}
