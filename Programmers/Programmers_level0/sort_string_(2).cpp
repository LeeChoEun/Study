// 프로그래머스 입문 (문자열 정렬하기(2))

/*문제 설명
영어 대소문자로 이루어진 문자열 my_string이 매개변수로 주어질 때, 
my_string을 모두 소문자로 바꾸고 알파벳 순서대로 정렬한 문자열을 return 하도록 solution 함수를 완성해보세요.
*/

/*제한사항
0 < my_string 길이 < 100
*/

/*문제 풀이*/
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 대문자, 소문자 확인 -> isupper, islower
// 대문자 -> 소문자 변환, 소문자 -> 대문자 변환 == tolower, toupper

string solution(string my_string) {
    vector<char> answer;
    
    for(char c : my_string)
    {
        if(isupper(c))
            answer.emplace_back(tolower(c));
        else
            answer.emplace_back(c);
    }
    
    sort(answer.begin(), answer.end());
    
    string r_answer = "";
    for(char c : answer)
        r_answer += c;
    
    
    return r_answer;
}