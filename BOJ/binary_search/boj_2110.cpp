// 2110 공유기 설치, 이분 탐색 (골드4)
// 집이 N개 존재하는데 공유기 C개 설치할거임
// 한정된 공유기 개수로 공유기 사이의 거리를 최대로 하는 프로그램

#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, C;
    cin >> N >> C;

    vector<int> A(N);
    for(int i = 0; i < N; i++)
        cin >> A[i];
    
    int distance = 0; // 가장 인접한 두 공유기 사이의 최대 거리

    cout << distance << "\n";

    return 0;
}