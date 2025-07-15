// 프로그래머스 기능 개발, 스택/큐 (Level 2)
// 여러가지 기능을 배포할 때 각 기능의 개발속도는 다름
// 배포되어야 하는 순서대로 진도가 적힌 == progresses
// 각 작업의 개발속도가 적힌 == speeds
// 뒤에 있는 기능이 먼저 개발되더라도 앞 기능이 배포될 때 함께 배포

// 각 배포마다 몇 개의 기능이 배포되는지 return
// 배포는 하루에 한번만 가능, 하루의 끝에 이루어짐

#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds)
{
    vector<int> answer;
    vector<int> days; // 각 작업마다 걸리는 날짜 

    // 각 작업이 완료되기까지 걸리는 날짜 계산
    for(int i = 0; i < progresses.size(); ++i)
    {
        int remain = 100 - progresses[i];
        int day = (remain + speeds[i] - 1) / speeds[i];
        days.emplace_back(day);
    }

    int current = days[0];
    int count = 1;

    // 순서대로 배포 여부 판단
    for(int i = 1; i < days.size(); ++i)
    {
        if(days[i] <= current)
            count++;
        else
        {
            answer.emplace_back(count);
            current = days[i];
            count = 1;
        }
    }
    answer.emplace_back(count);
    
    return answer;
}