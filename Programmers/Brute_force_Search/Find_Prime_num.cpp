// 프로그래머스 소수 찾기, 완전 탐색 (Level 2)
// 주어진 숫자로 만들 수 있는 소수의 총 개수
#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <cmath>

using namespace std;

bool isPrime(int n)
{
    if(n <= 1)  return false; // 1이하 숫자는 소수 아님
    for(int i = 2; i <= sqrt(n); ++i)
    {
        if(n % i == 0)  return false;
    }
    return true;
}

void generateNums(string numbers, string current, vector<bool>& visited, set<int>& result)
{
    if(!current.empty())
    {
        result.insert(stoi(current)); //만들어진 숫자를 점수로 바꿔서 저장
    }
    
    for(int i = 0; i < numbers.size(); ++i)
    {
        if(!visited[i])
        {
            visited[i] = true;
            generateNums(numbers, current + numbers[i], visited, result);
            visited[i] = false; //백트래킹
        }
    }
}

int solution(string numbers) {

    // 먼저 중복 없이 모든 숫자의 조합을 만들어 저장
    set<int> result;
    vector<bool> visited(numbers.size(), false); // 주어진 숫자의 개수만큼 false로 초기화
    
    generateNums(numbers, "", visited, result);
    
    // 소수의 개수 세기
    int count = 0;
    for(int num : result)
    {
        if(isPrime(num))
            count++;
    }
    
    return count;
}