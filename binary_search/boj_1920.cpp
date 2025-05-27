// 1920 수 찾기, 이분 탐색 (실버 4)
// N개의 정수가 주어졌을 때, X라는 정수가 존재하는지 알아내는 프로그램
// 존재하면 1, 존재하지 않으면 0

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool binary_search(const vector<int>& A, int target)
{
    int left = 0; int right = A.size() - 1;
    while(left <= right)
    {
        int mid = (left + right) / 2;
        if(A[mid] == target)
            return true;
        else if(A[mid] < target)
            left = mid + 1;
        else 
            right = mid -1;
    }
    return false;
}

int main(void)
{
    int N;
    cin >> N;

    vector<int> A(N);   // 주어진 정수들
    for(int i = 0; i < N; i++)
        cin >> A[i];
    
    sort(A.begin(), A.end());
    
    int M, x;
    cin >> M;

    while(M--)
        cin >> x;
        cout << binary_search(A, x) << "\n";

    return 0;
}