// 1654 랜선 자르기, 이분탐색 (실버2)
// K개의 서로 길이가 다른 랜선을 잘라서
// 필요한 개수 N개 만큼 만들 때
// 만들 수 있는 랜선의 최대 길이

#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int K, N;
    cin >> K >> N;

    vector<int> A(K);
    for(int i = 0; i < K; i++)
        cin >> A[i] >> "\n";

    int max_len = 0;
    
    cout << max_len << "\n";
    return 0;
}

