#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
    string s, input;
    int n;

    cin >> s >> n;

    stack<char> left, right;  // 왼쪽 커서 부분과 오른쪽 커서 부분을 각각 스택으로 관리

    // 초기 문자열을 왼쪽 스택에 넣기
    for (char c : s) {
        left.push(c);
    }

    for (int i = 0; i < n; i++) {
        cin >> input;

        if (input == "L") {
            if (!left.empty()) {
                right.push(left.top());  // 왼쪽 스택에서 오른쪽 스택으로 커서 왼쪽으로 이동
                left.pop();
            }
        }
        else if (input == "D") {
            if (!right.empty()) {
                left.push(right.top());  // 오른쪽 스택에서 왼쪽 스택으로 커서 오른쪽으로 이동
                right.pop();
            }
        }
        else if (input == "B") {
            if (!left.empty()) {
                left.pop();  // 왼쪽 스택에서 문자를 삭제
            }
        }
        else if (input == "P") {
            char tmp;
            cin >> tmp;
            left.push(tmp);  // 왼쪽 스택에 문자 삽입
        }
    }

    // 결과 출력: 왼쪽 스택에 있는 문자와 오른쪽 스택에 있는 문자를 합쳐서 출력
    while (!left.empty()) {
        right.push(left.top());
        left.pop();
    }

    while (!right.empty()) {
        cout << right.top();
        right.pop();
    }

    return 0;
}

/*
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(){
    string s, input;
    int n;

    cin >> s >> n;

    int cursor = s.length();

    for(int i=0; i<n; i++){
        cin >> input;

        if(input == "L"){
            if(cursor>0) cursor--;
        }
        else if(input == "D"){
            if(cursor<s.length()) cursor++;
        }
        else if(input == "B") {
            if (cursor > 0){
                s.erase(cursor-1, 1);
                cursor--;
            }
        }
        else if(input == "P"){
            string tmp;
            cin >> tmp;
            s.insert(cursor, tmp);
            cursor++;
        }
    }

    cout << s;
    return 0;
}
*/