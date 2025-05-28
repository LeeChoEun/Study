// 백준 1927 최소힙 (실버2)
// 배열에 자연수 X를 넣고 
// 배열에서 가장 작은 값을 출력하고 그 값을 제거

#include <iostream>
#include <queue>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N;
    cin >> N; // 연산의 개수
    priority_queue<int, vector<int>, greater<int>> pq; // 최소힙
    int count = 0;

    while(count < N)
    {
        int X;
        cin >> X;

        if (X == 0)
        {
            // 배열에서 가장 작은 값을 출력
            if(!pq.empty())
            {
                cout << pq.top() << '\n';
                // 그 값을 제거
                pq.pop();
            }
            else
                cout << "0" << '\n';
            
            count++;
        }
        else
        {
            // 배열에 x를 추가하는 연산
            pq.push(X);
            count++;
        }
    }

    return 0;
}
