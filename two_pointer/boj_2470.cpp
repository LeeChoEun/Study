// 2470 투 포인터 문제 (골드5)
// 여러 종류의 산성(+), 알칼리성(-) 용액 보유
// 주어진 특성값 중 각각 하나의 수를 더해서 0에 가까운 용액 만들기
// 두 용액의 특성값 출력

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main(void)
{
    int N;
    cin >> N;

    vector<int> A(N);
    for(int i = 0; i < N; i++)
        cin >> A[i];
    
    sort(A.begin(), A.end());
    
    // 두 값의 합을 0과 가장 가까운 값(min)과 비교해서
    // 더 0과 가까운 값이라면 두 값을 저장하고,
    // min값 갱신
    int min_value = 2e9;
    int result1 = 0, result2 = 0;
    int left = 0;
    int right = N - 1;

    while(left < right)
    {
        int sum = A[left] + A[right];
        if(abs(sum) < min_value)  //sum의 절대값이 min보다 작다면
        {
            min_value = abs(sum);
            result1 = A[left];
            result2 = A[right];

        }
        if(sum < 0) 
            left++;
        else
            right--;   
    }
    cout << result1 << " " << result2 << "\n";
    return 0;
}