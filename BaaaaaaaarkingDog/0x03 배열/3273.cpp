#include <iostream>
#include <vector>
#include <algorithm>

using namespace std; 

int main(){
    int n, x;
    vector<int> arr;

    cin >> n;
    arr.assign(n, 0);

    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    cin >> x; 

    sort(arr.begin(), arr.end());

    int left = 0;
    int right = n-1;
    int answer = 0;

    while(left<right){
        int sum = arr[left] + arr[right];

        if(sum==x){
            answer++;
            left++;
            right--;
        }
        else if(sum<x){
            left++;
        }
        else{
            right--;
        }
    }

    cout << answer;
    return 0;
}