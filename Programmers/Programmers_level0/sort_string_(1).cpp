// 프로그래머스 입문 (문자열 정렬하기(1))

/*문제 설명
문자열 my_string이 매개변수로 주어질 때, 
my_string 안에 있는 숫자만 골라 오름차순 정렬한 리스트를 return 하도록 solution 함수를 작성해보세요.
*/

/*제한사항
1 ≤ my_string의 길이 ≤ 100
my_string에는 숫자가 한 개 이상 포함되어 있습니다.
my_string은 영어 소문자 또는 0부터 9까지의 숫자로 이루어져 있습니다. - - -
*/

/*문제 풀이*/
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(string my_string) {
    vector<int> answer;
    
    for(char c : my_string)
    {
        if('0' <= c && c <= '9')
            answer.push_back(c - '0'); // 문자로 선언되어 있는 숫자에서 -'0' 하면 int 형 숫자로 변환
    }
    
    sort(answer.begin(), answer.end());
    
    return answer;
}