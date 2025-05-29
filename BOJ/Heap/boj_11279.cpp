// 백준 11279 최대 힙 (실버2)
// N개의 연산(x)을 차례대로 받을 때
// x가 0보다 크면 배열에 자연수 x를 넣는다 
// x가 0이면 배열에서 가장 큰 값을 출력하고
// 그 값은 배열에서 제거시키니다
// 배열이 비어있는데 출력하라고 하면 0을 출력

#include <iostream>
#include <queue>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N;
    cin >> N;

    priority_queue<int> pq; // 우선순위 큐(최댓값 기준)
    int count = 0;
    
    while(count < N)
    {
        int X;
        cin >> X;

        if(X == 0)
        {
            if(!pq.empty())
            {
                cout << pq.top() << '\n';
                pq.pop();
            }
            else
                cout << "0" << '\n';
            
            count++;
        }
        else
        {
            pq.push(X);
            count++;
        }
    }
    return 0;
}