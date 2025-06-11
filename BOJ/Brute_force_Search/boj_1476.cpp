// boj 1476 날짜 계산, 부르트 포스 (실버5)
// 1 <= E <= 15, 1 <= S <= 28, 1 <= M <= 19
// 1년마다 1씩 모두 증가하고 범위를 넘어가면 다시 1로 돌아감
// E S M의 값이 주어졌을 때 몇년인지 출력하는 문제

#include <iostream>

using namespace std;

int main()
{
    int E, S, M;
    cin >> E >> S >> M;

    int year = 1;
    while(true)
    {
        if((year - E) % 15 == 0 &&
            (year - S) % 28 == 0 &&
            (year - M) % 19 == 0)
        {
            cout << year << '\n';
            break;
        }
        year++;
    }
    return 0;
}