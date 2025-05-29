// 프로그래머스, K번째 수(정렬), level 1
// i ~ j 번째까지 배열을 자르고
// 오름차순으로 정렬한 뒤
// K번째에 있는 수를 구하기
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    
    int index = 0;
    
    while(index < commands.size())
    {
        vector<int> K;
        int start = commands[index][0] - 1; // i
        int end = commands[index][1] - 1; // j
        int num = commands[index][2] - 1; // k
        
        for(int i = start; i <= end; ++i)
        {
            K.push_back(array[i]);
            // cout << array[i] << '\n';
        }
        
        sort(K.begin(), K.end()); // 오름차순 정렬
        
        // for(auto k : K)
        //     cout << k << '\n';
        
        answer.push_back(K[num]);
        
        index++;
    }
    
    
    return answer;
}