#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main(){
    int n;
    cin >> n;
    
    vector<int> heights(n);
    vector<int> answer(n, 0);
    stack<int> s; 
    
    for(int i = 0; i < n; i++) {
        cin >> heights[i];
    }

    for(int i = 0; i < n; i++) {
        while(!s.empty() && heights[s.top()] < heights[i]) {
            s.pop();
        }
        if(!s.empty()) {
            answer[i] = s.top() + 1;
        }

        s.push(i);
    }
    
    for(int i = 0; i < n; i++) {
        cout << answer[i] << " ";
    }
    
    return 0;
}
