// boj 9095 1, 2, 3 더하기, 재귀 (실버3)
// 정수 n이 주어졌을 때, n을 1, 2, 3의 합으로
// 나타낼 수 있는 방법의 수

#include <iostream>
#include <vector>

using namespace std;

void getNumberofSum(int sum, int n, int& count)
{
    if(sum == n)
    {
        count++;
        return;
    }
    if(sum > n)
        return;

    for(int i = 1; i <= 3; ++i)
        getNumberofSum(sum+i, n, count);
}

int main()
{
    int T;
    cin >> T;
    for(int i = 0; i < T; ++i)
    {
        int n;
        cin >> n; // n 입력

        int sum = 0;
        int count = 0;

        getNumberofSum(sum, n, count);

        cout << count << '\n';
    }

    return 0;
}