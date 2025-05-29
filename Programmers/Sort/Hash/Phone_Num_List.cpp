// 프로그래머스, 전화번호 목록 (해시), level 2
// 전화번호부에서 한 번호가 다른 번호의 접두어인지 확인
// 접두어가 존재하면 false, 그렇지 않으면 true
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    
    //일단 정렬
    sort(phone_book.begin(), phone_book.end());
    
    for(int i = 0; i < phone_book.size() -1; ++i)
    {
        if(phone_book[i+1].substr(0, phone_book[i].size()) == phone_book[i])
           return false;
    }
    return answer;
}