// 프로그래머스, 가장 큰 수 (정렬), level 2
// 숫자 여러개가 주어졌을 때
// 붙여서 만들 수 있는 가장 큰 수 구해서 문자열로 반환
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

bool compare(string a, string b)
{
    return a + b > b + a;
}

string solution(vector<int> numbers) {
    string answer = "";
    
    vector<string> strNum;
    
    for(int num : numbers)
        strNum.push_back(to_string(num));
    
    sort(strNum.begin(), strNum.end(), compare);
    
    for(const string& s : strNum)
        answer += s;
    
    if(answer[0] == '0')
        answer = "0";
    
    return answer;
}