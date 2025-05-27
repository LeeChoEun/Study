// boj 1253 투포인터
// N개의 수 중 어떤 다른 수 2개의 합으로 하나의 수를 
// 나타낼 수 있다면 그 수는 good
// good이 몇개인지 출력하는 문제

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<int> A(N);
    
    for(int i = 0; i < N; i++)
        cin >> A[i];

    // 작은수가 앞으로 오도록 정렬
    sort(A.begin(), A.end());

    int result = 0;
    for(int i = 0; i < N; i++)
    {
        int left = 0;
        int right = N - 1;

        while(left < right)
        {
            //더하려는 숫자와 비교하는 숫자가 같다면 넘어가기
            if(left == i)
            {
                left++;
                continue;
            }
            if(right == i)
            {
                right--;
                continue;
            }

            int sum = A[left] + A[right];

            if(sum == A[i])
            {
                result++;
                break;
            }
            else if(sum < A[i]) //더한 수가 비교할 수보다 작을 때
                left++;
            else
                right--;
        }
    }
    
    cout << result << "\n";
    return 0;
} 