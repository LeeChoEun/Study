// 2143 두 배열의 합, 누적합 + 이분탐색 or 투 포인터 (골드3)
// 두 배열의 부배열(전체가 아닌 부분 배열)의 합을 더해서
// T를 만들 수 있는 경우의 수

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
    int T;
    cin >> T; // 합한 값

    int n;
    cin >> n; // 배열의 개수
    
    vector<int> A(n);
    for(int i = 0; i < n; ++i)
        cin >> A[i]; // 1번 배열
    
    int m;
    cin >> m;

    vector<int> B(m);
    for(int i = 0; i < m; ++i)
        cin >> B[i]; // 2번 배열

    // T값을 만드는 배열을 찾는것이므로
    // 각 배열을 오름차순으로 정렬하고
    // 이분탐색으로 가는 것이 제일 적절할 듯
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    for(int i = 0; i < n; ++i) // 일단 배열1을 기준으로 탐색
    {
        
    }
    



    return 0;
}