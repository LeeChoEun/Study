// 1806 부분합, 투 포인터 (골드4)
// 길이가 N인 수열에서 연속된 수의 부분합 중에 
// S 이상이 되는 것 중 가장 짧은 것의 길이
// 만약 S이상이 불가하다면 0 출력

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main(void)
{
    int N, S;
    cin >> N >> S;

    vector<int> A(N);
    for(int i = 0; i < N; i++)
        cin >> A[i];
    
    int length = INT_MAX;
    int left = 0, right = 0 ;
    int sum = 0;
    while(true)
    {
        if(sum >= S)
        {
            length = min(length, right - left);
            sum -= A[left++];
        }
        else if (right == N)
            break;
        else
            sum += A[right++];
    }

    if(length == INT_MAX)
        cout << 0 << "\n";
    else
        cout << length << "\n";

    return 0;
}