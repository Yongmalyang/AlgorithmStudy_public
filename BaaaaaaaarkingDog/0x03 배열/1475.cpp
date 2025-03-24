#include <iostream>
#include <vector>

using namespace std; 

int main(){
    int room;
    vector<int> num_plates;
    num_plates.assign(10, 0);

    cin >> room;

    while(room>0){
        int tmp = room%10;
        num_plates[tmp]++;
        room /= 10;
    }

    int six_nine = (num_plates[6] + num_plates[9] + 1) / 2;
    int max = six_nine;

    for(int i=0; i<num_plates.size(); i++){
        if(i==6 || i==9) continue;
        if(num_plates[i] > max) max = num_plates[i];
    }

    cout << max;
    return 0;
    
}