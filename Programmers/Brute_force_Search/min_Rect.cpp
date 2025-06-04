//프로그래머스 최소 직사각형, 완전탐색 (Level 1)
// 주어진 명함들의 크기에 맞는 가장 작은 지갑 만들기 (w, h)
// 각각 명함의 가로, 세로 크기를 비교해서 큰 쪽을 앞에
// 작은 쪽을 뒤에 두고, 가장 큰 수를 결과값으로
#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int answer = 0;
    
    vector<pair<int, int>> wallet;
    for(int i = 0; i < sizes.size(); ++i)
    {
        if(sizes[i][0] < sizes[i][1]) // 가로보다 세로가 크다면
        {
            wallet.push_back({sizes[i][1], sizes[i][0]});
        }
        else // 가로가 더 길다면
        {
            wallet.push_back({sizes[i][0], sizes[i][1]});
        }
    }
    
    int max_width = 0;
    int max_height = 0;
    
    for(auto w : wallet)
    {
        max_width = max(max_width, w.first);
        max_height = max(max_height, w.second);
    }
    
    answer = max_width * max_height;
    
    return answer;
}