// 프로그래머스, 완주하지 못한 선수 (해시), level 1
// 마라톤에서 완주하지 못한 1명의 이름 찾기

#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    unordered_map<string, int> name;
    for(const auto& num : participant) // 이름 별로 카운트
        name[num]++;
    
    for(const auto& num : completion)
        name[num]--;
    
    for(const auto& num : name)
        if(num.second > 0)
            return num.first;
    
    return "";
}