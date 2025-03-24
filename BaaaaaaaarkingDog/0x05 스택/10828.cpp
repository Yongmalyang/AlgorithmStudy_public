#include <iostream>
#include <stack>
using namespace std; 

int main(){
    int n;
    stack<int> s;

    cin >> n; 

    for(int i=0; i<n; i++){
        string input; 
        cin >> input;

        if(input == "push"){
            int tmp;
            cin >> tmp;
            s.push(tmp);
        }
        else if(input == "pop"){
            if(!s.empty()){
                cout << s.top() << endl;
                s.pop();
            }
            else cout << -1 << endl;
        }
        else if(input == "size"){
            cout << s.size() << endl;
        }
        else if(input == "empty"){
            if(s.empty()) cout << 1 << endl;
            else cout << 0 << endl;
        }
        else if(input == "top"){
            if(s.empty()) cout << -1 << endl;
            else cout << s.top() << endl; 
        }
    }

    return 0;
}