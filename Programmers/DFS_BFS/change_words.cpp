// 프로그래머스 단어 변환, BFS (Level 3)
// 주어진 단어 begin을 words vector에 있는 단어로
// target 단어로 변환시키는 가장 짧은 과정 return
// 규칙- 한 번에 한 개의 알파벳만 바꿀 수 있고,
// words에 있는 단어로만 변환할 수 있음
// 변환 불가 시 0 return

#include <vector>
#include <string>
#include <queue>

using namespace std;

bool isOneLetterDiff(string& a, string& b)
{
    int diffcount = 0;
    for(int i = 0; i < a.size(); ++i)
    {
        if(a[i] != b[i])    diffcount++;
        if(diffcount > 1)   return false;
    }
    return diffcount == 1;
}

int solution(string begin, string target, vector<string> words)
{
    int answer = 0;

    // words안에 target 단어 없으면 변환 불가
    bool canTransform = false;
    for(const string& word : words)
    {
        if(word == target)
        {
            canTransform = true;
            break;
        }
    }
    if(!canTransform) return 0;

    // BFS
    queue<pair<string, int>> q; // words, depth
    vector<bool> visited(words.size(), false);

    q.push({begin, 0});

    while(!q.empty())
    {
        auto [curr, depth] = q.front();
        q.pop();

        if(curr == target) return depth;

        for(int i = 0; i < words.size(); ++i)
        {   // 쓴적 없는 단어이고, 한글자만 다르다면
            if(!visited[i] && isOneLetterDiff(curr, words[i]))
            {
                visited[i] = true;
                q.push({words[i], depth});
            }
        }
    }

    return 0;
}