// 프로그래머스 정수 삼각형, DP (level 3)
// 정수로 이루어진 삼각형의 꼭대기에서 바닥으로의 경로 중
// 경로 숫자의 합이 가장 큰 경우

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> triangle)
{
    int answer = 0;
    int height = triangle.size(); // 삼각형의 높이

    // 삼각형 마지막 줄과 그 윗줄을 비교하기 위해 height -2부터 시작
    for(int i = height -2; i >= 0; --i) 
    {  
        for(int j = 0; j < triangle[i].size(); ++j)
            triangle[i][j] += max(triangle[i+1][j], triangle[i+1][j+1]);
    }

    answer = triangle[0][0];
    return answer;
}

int main()
{
    vector<vector<int>> triangle = 
    {
        {7},
        {3, 8},
        {8, 1, 0},
        {2, 7, 4, 4},
        {4, 5, 2, 6, 5},
    };

    int answer = solution(triangle);
    cout << answer << "\n";
    return 0;
}