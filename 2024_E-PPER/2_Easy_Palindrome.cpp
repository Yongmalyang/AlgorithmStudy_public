/*
* 23회(24-2) E-PPER 기출문제 난이도 하 2번
* 백준 1213번: 팰린드롬 만들기
*/

#include <iostream>
#include <vector>
#include <stack>
using namespace std;
#define ALPHABET_COUNT 26

string name;
vector<int> alphabet(ALPHABET_COUNT);

void SaveAlphabet(char a){
    alphabet[(int)a - (int)'A']++;
}

bool CheckIfPalindrome(){
    int count_odds = 0;

    for(int i=0; i<alphabet.size(); i++){
        if(alphabet[i]%2 != 0) count_odds++;
        if(count_odds > 1){
            return false;
        }
    }

    return true;
}

void PrintPalindrome(){
    stack<int> s;
    int odd = -1;

    for(int i=0; i<alphabet.size(); i++){
        int count = alphabet[i];
        for(int j=0; j<count/2; j++){
            cout << (char) (i + (int)'A');
            s.push(i);
        }

        if(count%2 != 0) odd = i;
    }

    if(odd != -1) cout << (char) (odd + (int)'A');

    int iter = s.size();
    for(int i=0; i<iter; i++){
        cout << (char) (s.top() + (int)'A');
        s.pop();
    }
}

int main(){
    cin >> name;    

    for(int i=0; i<name.length(); i++){
        SaveAlphabet(name[i]);
    }

    if(!CheckIfPalindrome())
        cout << "I'm Sorry Hansoo";
    else
        PrintPalindrome();

    return 0;
}