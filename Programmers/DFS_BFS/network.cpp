// 프로그래머스 네트워크, DFS (Level 3)

// A, B, C 컴퓨터가 있을 때, A와 B가 연결되어 있고, B와 C가 연결되어 있다면
// A와 C도 간접적으로 연결되어 있으므로 네트워크는 1개임(모두 같은 네트워크)
// n개의 컴퓨터와 각 컴퓨터에 대한 연결정보가 주어질 때,
// 네트워크의 개수 return

#include <string>
#include <vector>

using namespace std;

void Network(vector<vector<int>>& computers, vector<bool>& visited, int current)
{
    visited[current] = true;
    
    for(int next = 0; next < computers.size(); ++next)
    {   // 자기 자신이 아니고, 연결되어 있으며, 아직 방문하지 않은 노드일 경우
        if(current != next && computers[current][next] == 1 && !visited[next])
            Network(computers, visited, next);
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    
    vector<bool> visited(n, false); // 컴퓨터 방문여부 저장
    
    for(int i = 0; i < n; ++i)
    {
        if(!visited[i])
        {
            Network(computers, visited, i);
            answer++;
        }
    }
    
    return answer;
}