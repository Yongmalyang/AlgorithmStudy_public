#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int SIZE = 26;    // 알파벳의 수

// 알파벳 개수 세는 함수! 
vector<int> countAlphabet(string text) {
	// 반환할 벡터. a-z까지 개수 저장
	vector<int> count(SIZE, 0);
	// 길이만큼 돌기
	for (int i = 0; i < text.size(); i++) {
		// text[i]-'A' 해줘야함
		count[text[i] - 'A']++;
	}
	return count;
}

// 팰린드롬 만들어 리턴해주는 함수!
string makePalindrome(vector<int>& count) {
	// 앞부분 가운데부분 뒷부분으로 나누기. string 3개 만들기
	string part1 = "", part2 = "", part3 = "";

	// 알파벳 길이만큼 순회
	for (int i = 0; i < SIZE; i++) {
		// 만약 알파벳의 수가 홀수라면
		if (count[i] % 2 == 1) {
			// 이미 가운데 글자가 찼다면 더 이상 불가능
			if (part2.size() == 1) {
				return "I'm Sorry Hansoo";
			}
			// 가운데 글자가 비어있다면 할당
			part2 = (char)(i + 'A');
		}
		// 남은 수의 절반을 나누어 part1과 part3에 이어 붙인다
		for (int j = 0; j < count[i] / 2; j++) {
			// part1은 뒤에다 이어붙이기
			part1 += (char)(i + 'A');
			// part3는 앞에다 이어붙이기
			part3 = (char)(i + 'A') + part3;
		}
	}
	// 합친거 리턴
	return part1 + part2 + part3;
}

string solution(string str) {
	// 연산 + 출력
	vector<int> count = countAlphabet(str);
	return makePalindrome(count);
}

int main() {
	string input;
	cin >> input;

	cout << solution(input);

	return 0;
}