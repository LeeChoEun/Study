//  1966 프린터 큐, 큐 (실버3)
//  프린터에서 문서들을 인쇄할 때
//  각 문서의 중요도에 따라 우선순위를 두고 인쇄

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main()
{
    int T;
    cin >> T;

    while(T--) //test case 전체를 다 돌 때 까지
    {
        int N, M;
        cin >> N >> M;

        queue<pair<int, int>> q;
        priority_queue<int> pq;

        for(int i = 0; i < N; ++i)
        {
            int import;
            cin >> import; // 중요도

            q.push({i, import}); //문서 번호, 중요도
            pq.push(import);
        }

        int count = 0;

        while(!q.empty())
        {
            int idx = q.front().first;
            int val = q.front().second;
            q.pop();

            if(val  == pq.top())
            {
                pq.pop();
                count++;

                if(idx == M)
                    cout << count << "\n";
            }
            else
                q.push({idx, val});
                
        }
    }

    return 0;
}