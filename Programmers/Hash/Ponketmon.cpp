// 프로그래머스, 폰켓몬 (해시), level 1
// 전체 폰켓몬 중 1/2만 가져갈 수 있는데
// 최대한 많은 종류를 선택하는 방법 찾아서 종류의 개수 return

//unordered_set을 사용해서 종류의 가짓수를 저장하고
//1/2보다 작으면 가짓수 return, 크다면 1/2값 return

#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;
    
    unordered_set<int> ponketmon(nums.begin(), nums.end());
    int n = nums.size() / 2;
        
        
    return min((int)ponketmon.size(), n);
}