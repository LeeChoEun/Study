// 프로그래머스 카펫, 완전 탐색 (Level 2)
// 카펫의 테두리 1줄은 갈색, 나머지는 노란색으로 칠해져 있음
// 각 색의 격자의 수를 가지고 카펫의 가로, 세로 크기 구하기
// 가로 길이 >= 세로 길이

#include <iostream>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    
    // 가로 * 세로 - 노란색 격자의 수 = 갈색 격자의 수
    int total_size = brown + yellow; // 전체 격자의 수
    
    // total_size의 최대 공약수 중 가장 큰 수
    // (가로 -2) * (세로 -2) = yellow
    // 가로가 3 이상이어야 노란 격자가 있을 수 있음
    for(int height = 3; height <= total_size / height; ++height)
    {
        if(total_size % height != 0)    continue;
        
        int width = total_size / height;
        if((width - 2) * (height - 2) == yellow)
            return {width, height};
    }
    
    
    
    return {};
}