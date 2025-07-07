// 프로그래머스 체육복, 그리디 (Level 1)
// 체육복을 도난 맞음
// 체육 시간에 체육복이 있어야 수업 참여가 가능함
// 여분의 체육복을 가져온 사람은 앞뒤 번호의 사람에게만 빌려줄 수 있음
// 이 때 체육 수업에 참여할 수 있는 학생의 최대 수

#include <vector>
#include <algorithm>

using namespace std;

// lost : 도난당한 학생의 번호, reserve : 여벌옷이 있는 학생의 번호
int solution(int n, vector<int> lost, vector<int> reserve)
{
    sort(lost.begin(), lost.end());
    sort(reserve.begin(), reserve.end());

    // 1. 도난당했지만 여벌옷을 가지고 있는 학생 제외
    vector<int> realLost;
    vector<int> realReserve;

    for(int l : lost)
    {
        if(find(reserve.begin(), reserve.end(), l) == reserve.end())
            realLost.emplace_back(l);
    }

    for(int r : reserve)
    {
        if(find(lost.begin(), lost.end(), r) == lost.end())
            realReserve.emplace_back(r);
    }

    // 2. 앞 번호부터 순차적으로 여벌옷을 빌려주기
    for(int r : realReserve)
    {
        auto it = find(realLost.begin(), realLost.end(), r - 1);
        if(it != realLost.end())
        {
            realLost.erase(it);
            continue;
        }

        it = find(realLost.begin(), realLost.end(), r + 1);
        if(it != realLost.end())
        {
            realLost.erase(it);
        }
    }

    return n - realLost.size();
}   