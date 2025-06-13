// boj 10819 차이를 최대로, 백트래킹 (실버 2)
// N개의 정수로 이루어진 배열 A가 주어짐
// |A[0] - A[1]| + |A[1] - A[2]| +...+ |A[N-2] - A[N-1]|
// 식처럼 배열A를 계산했을 때 얻을 수 있는 최댓값 출력
// 3 <= N <= 8    -100 <= A[i] <= 100

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int calcDiffSum(const vector<int>& arr)
{
    int sum = 0;
    for(int i = 0; i < arr.size() -1; ++i)
        sum += abs(arr[i] - arr[i+1]);
    return sum;
}

int main()
{
    int N;
    cin >> N;

    vector<int> A(N);
    for(int i = 0; i < N; ++i)
        cin >> A[i];
    
    sort(A.begin(), A.end());

    int maxSum = 0;
    do{
        int currSum = calcDiffSum(A);
        maxSum = max(maxSum, currSum);
    } while (next_permutation(A.begin(), A.end()));

    cout << maxSum << '\n';

    return 0;
}