// 프로그래머스 게임 맵 최단거리, BFS (Level 2)

// n*m 게임판에서 우리팀은 1행 1열에 위치, 상대팀은 n행 m열에 위치
// 벽(0)과 갈 수 있는 길(1)이 주어질 때 최단 경로의 길이 return
// 상대 진영으로 도착할 수 없을 때에는 -1 return

// DFS로 모든 경로 탐색 -> 시간 복잡도가 커서 x
// BFS 사용 (최단 경로 구할 땐 항상!)

#include <vector>
#include <queue>

using namespace std;

// 상 하 좌 우 이동 벡터
int dx[4] = {-1, 1, 0, 0}; // 행 이동
int dy[4] = {0, 0, -1, 1}; // 열 이동

int solution(vector<vector<int>> maps)
{
    int n = maps.size();    // 행 길이
    int m = maps[0].size(); // 열 길이

    // 방문 여부 및 거리 저장 배열(maps와 같은 크기)
    vector<vector<int>> visited(n, vector<int>(m, 0));

    // BFS를 위한 큐 (좌표 저장)
    queue<pair<int, int>> q; // x, y
    q.push({0, 0}); // 시작점
    visited[0][0] = 1; // 시작점 방문 처리 (거리 1)

    while(!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        // 도착 지점에 도착하면 거리 리턴
        if(x == n - 1 && m == m - 1)
            return visited[x][y];
        
        // 4방향 이동
        for(int dir = 0; dir < 4; ++dir)
        {
            int nx = x + dx[dir];
            int ny = y + dy[dir];

            // 범위 체크
            if(nx >= 0 && ny >= 0 && nx < n && ny < m)
            {   // 길이 있고, 아직 방문하지 않았다면
                if(maps[nx][ny] == 1 && visited[nx][ny] == 0)
                {
                    visited[nx][ny] = visited[x][y] + 1;
                    q.push({nx, ny});
                }
            }
        }
    }
    // 도착할 수 없는 경우
    return -1;
}