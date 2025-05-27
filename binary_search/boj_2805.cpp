// 2805 나무 자르기, 이분탐색 (실버2)
// 높이 H를 지정하면 H보다 높은 나무만 잘림
// 필요한 길이 만큼 맞춰서 잘라가기
//  이때 높이의 최댓값

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool can_cut(const vector<int>& A, int height, long long M)
{
    long long sum = 0;
    for(int i = 0; i < A.size(); i++)
    {
        if(A[i] > height)
            sum += A[i] - height; 
    }
    return sum >= M;
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    long long M;   // N = 나무 개수, M = 필요한 길이
    cin >> N >> M;

    vector<int> A(N);
    for(int i = 0; i < N; i++)
        cin >> A[i];

    int left = 0, right = *max_element(A.begin(), A.end());
    int max_height = 0;

    while(left <= right)
    {
        int mid = (left + right) / 2;
        if(can_cut(A, mid, M))
        {
            max_height = mid;
            left = mid + 1;
        }
        else
            right = mid -1;
    }

    cout << max_height << "\n";
    return 0;
}
