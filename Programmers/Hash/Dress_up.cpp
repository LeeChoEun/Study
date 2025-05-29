// 프로그래머스, 의상 (해시) level 2
// 의상의 종류와 여러가지 아이템이 있을 때
// 같은 종류에서는 1가지만 사용해서 
// 조합할 수 있는 최대 가짓수

#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    // 의상의 이름, 종류 이런식으로 구성되어 있으므로
    // 같은 종류 찾아서 묶기
    unordered_map<string, int> clothes_type; //의상 이름, 가짓수
    
    for(const auto& item : clothes) // 같은 의상 이름일 때 +1
    {
        string type = item[1];
        clothes_type[type]++;
    }
    
    for(const auto& entry : clothes_type)
        answer *= (entry.second + 1);
        
    
    return answer -1; // 아무것도 안입었을 때 제외
}