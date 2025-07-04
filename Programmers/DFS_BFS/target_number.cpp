// 프로그래머스 타겟 넘버, DFS (Level 2)

// n개의 음이 아닌 정수와 타겟 넘버가 주어졌을 때
// n개의 수에 + - 를 붙여 타겟 넘버를 만들 수 있는 경우의 수

#include <string>
#include <vector>

using namespace std;

void get_target_num(vector<int>& numbers, int index, int sum, int target, int& answer)
{
    if(index == numbers.size())
    {
        if(sum == target)
            answer++;
        
        return;
    }
    
    get_target_num(numbers, index + 1, sum + numbers[index], target, answer);
    get_target_num(numbers, index + 1, sum - numbers[index], target, answer);
}

int solution(vector<int> numbers, int target) {
    int answer = 0;
    
    get_target_num(numbers, 0, 0, target, answer);
    
    return answer;
}