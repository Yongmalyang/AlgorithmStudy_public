/*
* 23회(24-2) E-PPER 기출문제 난이도 하 1번
* 백준 11399번: ATM
*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n;

int main(){
    cin >> n;
    vector<int> vec(n);

    for(int i=0; i<n; i++){
        cin >> vec[i];
    }

    sort(vec.begin(), vec.end());

    int answer = 0;
    for(int i=0; i<n; i++){
        answer += vec[i] * (n-i);
    }

    cout << answer;
    return 0;
}

