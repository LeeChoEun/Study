// 프로그래머스 모의고사, 완전탐색 (Level 1)
// 문제를 찍었을 때 가장 정답을 많이 맞춘 사람
// 1. 1 2 3 4 5
// 2. 2 1 2 3 2 4 2 5
// 3. 3 3 1 1 2 2 4 4 5 5 
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    vector<int> a = {1, 2, 3, 4, 5};
    vector<int> b = {2, 1, 2, 3, 2, 4, 2, 5};
    vector<int> c = {3, 3, 1, 1, 2, 2, 4, 4, 5 ,5};
    
    vector<int> cnt(3, 0);
    
    for(int i = 0; i < answers.size(); ++i)
    {
        if(answers[i] == a[i % a.size()]) cnt[0]++;
        if(answers[i] == b[i % b.size()]) cnt[1]++;
        if(answers[i] == c[i % c.size()]) cnt[2]++;
    }
    
    int max = *max_element(cnt.begin(), cnt.end());
    for(int i = 0; i < 3; ++i)
    {
        if(max == cnt[i])
            answer.push_back(i + 1);
    }
    
    
    
    
    return answer;
}