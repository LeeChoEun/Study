// 프로그래머스 조이스틱, 그리디 (Level 2)
// 조이스틱과 완성해야 할 알파벳이 주어짐
// 조이스틱으로 주어진 알파벳을 완성할 수 있는 최소 조작 횟수 return
// 처음에 완성해야 하는 알파벳 개수만큼 'A'로 선언되어 있다고 가정

// 조이스틱 조작 설명
// 위 : 다음 알파벳
// 아래 : 이전 알파벳
// 좌 : 커서를 왼쪽으로 이동
// 우 : 커서를 오른쪽으로 이동

#include <string>
#include <algorithm>

using namespace std;

int solution(string name)
{
    int answer = 0;
    int n = name.length();

    // 1. 세로 조작 ( A -> 원하는 문자로 바꾸기)
    for(int i = 0; i < n; ++i)
    {
        char c = name[i];
        // 위로 가는 경우 vs 아래로 가는 경우
        int upDown = min(c - 'A', 'Z' - c + 1);
        answer += upDown;
    }

    // 2. 가로 조작 (커서 이동 최소화)
    int move = n - 1; // 일단 오른쪽 끝까지 가는 경우를 최악으로 설정

    for(int i = 0; i < n; ++i)
    {
        int next = i + 1;

        // 연속된 'A' 구간 찾기 (skip)
        while(next < n && name[next] == 'A')
            next++;
        
        // case 1: 오른쪽으로 갔다가 왼쪽으로 돌아옴
        int case1 = i + i + (n - next);
        
        // case 2: 왼쪽으로 갔다가 오른쪽으로 돌아옴
        int case2 = i + 2 * (n - next);

        // i : 현재까지 오른쪽으로 이동한 지점
        // next : A구간을 넘어서 처음 나오는 문자 위치
        move = min({move, case1, case2});

    }
    
    answer += move;
    return answer;
}