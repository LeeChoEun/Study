// 9184 신나는 함수 실행, DP(메모이제이션 + 재귀) (실버2)
// 여러가지 조건이 걸려있는 재귀함수
// a <= 0 or b <= 0 or c <= 0 -> w(a, b, c) = 1
// a > 20 or b > 20 or c > 20 -> w(20, 20, 20)
// a < b and b < c -> w(a, b, c-1) + w(a, b-1, c-1) - w(a, b-1, c)
// else w(a-1, b, c) + w(a-1, b-1, c) + w(a-1, b, c-1) - w(a-1, b-1, c-1)

#include <iostream>

using namespace std;

// 메모이제이션용 3차원 배열
int dp[21][21][21];

int W(int a, int b, int c)
{

    //1. a <= 0 or b <= 0 or c <= 0 -> w(a, b, c) = 1
    if(a <= 0 || b <= 0 || c <= 0)
        return 1;
    
    //2. a > 20 or b > 20 or c > 20 -> w(20, 20, 20)
    if(a > 20 || b > 20 || c > 20)
        return W(20, 20, 20);

    // 3.
    if(dp[a][b][c] != 0) // 이미 계산이 끝난 경우
        return dp[a][b][c];

    // 4. 점화식
    //4-1. a < b and b < c -> w(a, b, c-1) + w(a, b-1, c-1) - w(a, b-1, c)
    if(a < b && b < c)
        dp[a][b][c] = W(a, b, c-1) + W(a, b-1, c-1) - W(a, b-1, c);
    //4-2. else w(a-1, b, c) + w(a-1, b-1, c) + w(a-1, b, c-1) - w(a-1, b-1, c-1)
    else
        dp[a][b][c] = W(a-1, b, c) + W(a-1, b-1, c) + W(a-1, b, c-1) - W(a-1, b-1, c-1);

    return dp[a][b][c];
}

int main()
{
    int a, b, c;
    
    while(true){
        cin >> a >> b >> c;

        //종료조건건
        if(a == -1 && b == -1 && c == -1)
            break;

        cout << "w(" << a << ", " << b << ", " << c << ") = " << W(a, b, c) << "\n";
    }

    return 0;
}