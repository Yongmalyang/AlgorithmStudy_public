/*
* 23회(24-2) E-PPER 기출문제 난이도 하 3번
* 프로그래머스: 크레인 인형뽑기
* https://school.programmers.co.kr/learn/courses/30/lessons/64061
*/

#include <string>
#include <stack>
#include <vector>

using namespace std;

vector<vector<int>> myBoard;

int PickDollOnTop(int move){
    for(int i=0; i<myBoard.size(); i++){
        int cur_doll = myBoard[i][move];
        if(cur_doll != 0){
            myBoard[i][move] = 0;
            return cur_doll;
        }
    }
    return 0;
}

int solution(vector<vector<int>> board, vector<int> moves) {
    stack<int> s;
    myBoard = board;
    
    int answer = 0;
    
    for(int i=0; i<moves.size(); i++){
        // 몇 번 위치에서 집었는가
        int this_move = moves[i] - 1;
        int this_doll = PickDollOnTop(this_move);
        
        if(this_doll != 0){
            if(!s.empty() && s.top()==this_doll){
                s.pop(); 
                answer += 2;
            }
            else s.push(this_doll);
        }
    }

    return answer;
}