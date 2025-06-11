// boj 1018 체스판 다시 칠하기, 브루트 포스 알고리즘 (실버4)
// M * N 크기의 보드에 검은색 흰색이 무작위로 칠해져 있음
// 체스판처럼 만들 때 다시 칠해야 하는 정사각형의 최소 개수
// 8 * 8 크기로 잘라내서 칠하는 것

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main ()
{
    // 체스판이 흰색으로 시작하는 것, 검은색으로 시작하는 것 2가지 존재
    vector<string> WB = {
        "WBWBWBWBWB",
        "BWBWBWBWBW",
        "WBWBWBWBWB",
        "BWBWBWBWBW",
        "WBWBWBWBWB",
        "BWBWBWBWBW",
        "WBWBWBWBWB",
        "BWBWBWBWBW"
    };

    vector<string> BW = {
        "BWBWBWBWBW",
        "WBWBWBWBWB",
        "BWBWBWBWBW",
        "WBWBWBWBWB",
        "BWBWBWBWBW",
        "WBWBWBWBWB",
        "BWBWBWBWBW",
        "WBWBWBWBWB",
    };

    int M, N;
    cin >> N >> M;

    vector<string> board(N);
    for(int i = 0; i < N; ++i)
        cin >> board[i];

    int minChange = 64;
    for(int y = 0; y < N - 8; ++y)
    {
        for(int x = 0; x < M - 8; ++x)
        {
            int whiteMiss = 0;
            int blackMiss = 0;
            
            for(int i = 0; i < 8; ++i)
            {
                for(int j = 0; j < 8; ++j)
                {
                    char current = board[y + i][x + j];
                    if(current != WB[i][j]) whiteMiss++;
                    if(current != BW[i][j]) blackMiss++;
                }
            }
            int curr_Min = min(whiteMiss, blackMiss);
            minChange = min(minChange, curr_Min);
        }   
    }
    cout << minChange << '\n';
    return 0;
}