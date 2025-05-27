// 평범한 배낭, DP (골드5)
// 배낭에 N개의 물건을 넣어갈 때
// 각각의 무게 W와 가치 V를 지님
// 가치의 최댓값 구하기

// 0-1 Knapsack에서 각 물건은 1번만 선택 가능
// 경우의 수는 선택하거나, 하지 않거나
// 중요 포인트는 최대 무게에서부터 물건의 무게를 제외하는 방식으로

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main(void)
{
    int N, K;
    cin >> N >> K;

    vector<pair<int, int>> items(N + 1); //1번째부터 사용하기 위해 +1
    for(int i = 1; i <= N; ++i)
        cin >> items[i].first >> items[i].second; // weight, value
    
    // 최댓값 구할 1차월 배열 선언
    vector<int> dp(K+1, 0); //최대 무게 +1 만큼 선언하고 0으로 초기화

    for(int i = 1; i <= N; ++i) //1 ~ N번째 물건까지 탐색
    {
        int weight = items[i].first; // i번째 물건 무게
        int value = items[i].second; // i번째 물건 가치

        for(int j = K; j >= weight; --j) //최대무게 배열부터 최대가치 찾기
            dp[j] = max(dp[j], dp[j - weight] + value);
    }
    cout << dp[K] << "\n";

    return 0;
}