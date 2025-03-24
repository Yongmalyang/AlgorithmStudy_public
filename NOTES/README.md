# AlgorithmStudy

1. int / int를 float로 표현하기
float div = static_cast<float>(a) / b;

2. 반올림, 올림, 내림
- #include <cmath> 불러오기
- 올림: ceil
- 내림: floor
- 반올림: round
- 소수점 3째자리?? round(a*1000)/1000 이렇게 해야함..
- 추가적으로!! 12.4 말고 12.400 하려면 
answer = round(answer*1000) / 1000;
cout << fixed << setprecision(3) << answer;
 

3. 정렬
 #include <algorithm>
 #include <vector>

 vector<int> a;
 sort(a.begin(), a.end());

4. int: 10자리 정도
float: 소수 위아래 합쳐서 6~7자리
double: 소수 위아래 합쳐서 15~16자리

5. 내림차순 tip: 음수를 붙이고 오름차순 정렬을 한다..

6. #include <tuple>
vector<tuple<int, int, int> > tup;
tup.push_back(make_tuple(a, b, c)); 
이런식으로 써먹기
tuple을 sort하면 맨앞 원소(a)에 대해 정렬된다.

7. tuple의 tie 기능. 
tuple의 a, b를 따로 x, y에 써먹고 싶다면
tie(x, y, ignore) = tup[i]; 
이런 식으로 가능

8. set
multiset
사용하려면 #include <set>
set: 정렬상태 자동으로 유지해줌, index로는 접근 불가능, 중복 불가
multiset: 정렬상태 자동으로 유지해줌, index로는 접근 불가능, 중복 가능
접근 시 ms.begin()은 반복자 (인덱스와 유사한 개념)이므로
int a = ms.begin()   (X)
int a = *ms.begin()  (O)

9. sort(arr, arr+n, cmp);
이런 식으로 cmp함수를 추가해주면 cmp에 조건을 달아 내림차순 정렬을 만들 수 있음.
다음과 같이 작성한다: 
bool cmp(int a, int b) {
    if(a > b)
        return true;
    else
        return false;
}

10. map<string, int>
map이 존재하는지 안하는지 알고싶다면..
map.find("어쩌구키값") == map.end()로 확인!! 
=> find에서 존재하지 않을 시 map의 맨 끝 접근자를 반환한다.

11. cin 숫자 자릿수로 받는 법??