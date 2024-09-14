/*
* 23회(24-2) E-PPER 기출문제 난이도 중 5번
* 백준 19941번: 햄버거 분배
*/

#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std; 

int n, k;
string arr;

int main(){
    cin >> n >> k;
    cin >> arr;

    vector<int> person;
    vector<int> hamburger;

    for(int i=0; i<n; i++){
        if(arr[i] == 'P') person.push_back(i);
        else if(arr[i] == 'H') hamburger.push_back(i);
    }

    int answer = 0;
    for(int i=0; i<person.size(); i++){
        for(int j=0; j<hamburger.size(); j++){
            if(hamburger[j] != -1 && abs(hamburger[j]-person[i]) <= k){
                answer++;
                hamburger[j] = -1;
                break;
            }
        }
    }

    cout << answer;
    return 0;
}