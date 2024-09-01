# AlgorithmStudy

1. int / int를 float로 표현하기
float div = static_cast<float>(a) / b;

2. 반올림, 올림, 내림
- #include <cmath> 불러오기
- 올림: ceil
- 내림: floor
- 반올림: round
- 소수점 3째자리?? round(a*1000)/1000 이렇게 해야함..
 

 정렬
 #include <algorithm>
 #include <vector>

 vector<int> a;
 sort(a.begin(), a.end());