// boj 15649 N과 M (1), 백트래킹 (실버 3)
// 자연수 N과 M이 주어짐 (1 <= M <= N <= 8)
// 1부터 N까지 자연수 중에서 중복 없이 M개 고른 수열

#include <iostream>
#include <vector>

using namespace std;

void getAllNumber(vector<int>& Num, int M, vector<int>& curr_num, vector<bool>& used)
{
    if(curr_num.size() == M)
    {
        for(int n : curr_num)
            cout << n << " ";
        cout << '\n';
        return;
    }

    for(int i = 0; i < Num.size(); ++i)
    {
        if(!used[i])
        {
            used[i] = true;
            curr_num.push_back(Num[i]);
            getAllNumber(Num, M, curr_num, used);
            curr_num.pop_back();
            used[i] = false;
        }
    }
}

int main()
{
    int N, M;
    cin >> N >> M;

    vector<int> Num(N);
    for(int i = 1; i <= N; ++i)
        Num[i-1] = i;
    
    vector<int> curr_num;
    vector<bool> used(N, false);

    getAllNumber(Num, M, curr_num, used);

    return 0;
}