/*
문제
임한수와 임문빈은 서로 사랑하는 사이이다.

임한수는 세상에서 팰린드롬인 문자열을 너무 좋아하기 때문에, 둘의 백일을 기념해서 임문빈은 팰린드롬을 선물해주려고 한다.

임문빈은 임한수의 영어 이름으로 팰린드롬을 만들려고 하는데, 임한수의 영어 이름의 알파벳 순서를 적절히 바꿔서 팰린드롬을 만들려고 한다.

임문빈을 도와 임한수의 영어 이름을 팰린드롬으로 바꾸는 프로그램을 작성하시오.

입력
첫째 줄에 임한수의 영어 이름이 있다. 알파벳 대문자로만 된 최대 50글자이다.

출력
첫째 줄에 문제의 정답을 출력한다. 만약 불가능할 때는 "I'm Sorry Hansoo"를 출력한다. 정답이 여러 개일 경우에는 사전순으로 앞서는 것을 출력한다.
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int SIZE = 26;    // 알파벳의 수

vector<int> countAlphabet(string text) {
	// text에 있는 각 알파벳의 개수를 세어 리턴하는 함수
	vector<int> count(SIZE, 0); // A-Z까지 문자의 개수를 저장할 리스트
	for (int i = 0; i < text.size(); i++) {
		// 각 문자를 인덱스로 바꿔주기 위해 'A'의 인덱스를 빼줌
		count[text[i] - 'A']++;
	}
	return count;
}

string makePalindrome(vector<int>& count) {
	// 팰린드롬을 만들어 리턴하는 함수.
	string part1 = "", part2 = "", part3 = "";

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
			part1 += (char)(i + 'A');
			part3 = (char)(i + 'A') + part3;
		}
	}

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