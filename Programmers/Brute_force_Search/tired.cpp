// 던전을 탐험할 때 각 던전마다 최소 필요 피로도(1)와 소모 피로도(2)가 있음
// (1)은 던전을 탐험하기 위해 필요한 최소 피로도
// (2)는 던전을 탐험하고 나면 소모되는 피로도
// 던전은 하루에 한 번 탐험이 가능할 때
// 하루에 탐험할 수 있는 던전의 최대 수

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int answer = 0;

void Explore(vector<vector<int>> &dungeons, int k, int depth, vector<bool>& visited)
{
    answer = max(answer, depth);
    
    for(int i = 0; i < dungeons.size(); ++i)
    {
        if(!visited[i] && k >= dungeons[i][0])
        {
            visited[i] = true;
            Explore(dungeons, k - dungeons[i][1], depth + 1, visited);
            visited[i] = false;
        }
    }
    
}

int solution(int k, vector<vector<int>> dungeons) {
    
    // 순서대로 던전을 돌고 소모 피로도를 k에서 제거
    // 모든 경우의 수만큼 던전을 돌고 던전을 돈 횟수를 비교해서
    // 최댓값을 return
    vector<bool> visited(dungeons.size(), false);
    Explore(dungeons, k, 0, visited);
    
    
    return answer;
}