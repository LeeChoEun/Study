// 프로그래머스 코딩테스트 입문 (제곱수 판별하기)

/*문제 설명
어떤 자연수를 제곱했을 때 나오는 정수를 제곱수라고 합니다. 
정수 n이 매개변수로 주어질 때, n이 제곱수라면 1을 아니라면 2를 return하도록 solution 함수를 완성해주세요.
*/

/*제한사항
1 ≤ n ≤ 1,000,000
*/

/*문제 풀이*/
#include <string>
#include <vector>
#include <cmath>

// 제곱근인지 판별하는 방법은 sqrt(루트함수) 사용했을 때 나오는 값

using namespace std;

int solution(int n) {
    int answer = 0;
    
    double num = sqrt(n);
    
    if(num == (int)num)
        answer = 1;
    else
        answer = 2;
    
    return answer;
}