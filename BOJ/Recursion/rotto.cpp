// boj 6603 로또, 재귀 (실버 2)
// 1~49 중 6개의 수를 고른다. 
// k(k>6)개와 집합 S가 주어졌을 때 
// 6개를 골라 집합을 만들어 print
// 테스트 케이스 사이에는 빈줄이 출력되어야 함

#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

void getAllNumber(vector<int>& s, vector<int>& comb, int start)
{
    if(comb.size() == 6)
    {
        for(int i = 0; i < 6; ++i)
            cout << comb[i] << " ";
        cout << '\n';
        return;
    }

    for(int i = start; i < s.size(); ++i)
    {
        comb.push_back(s[i]);
        getAllNumber(s, comb, i+1);
        comb.pop_back(); // backtracking
    }

}

int main()
{
    string line;
    bool first = true;

    while(getline(cin, line))
    {
        if(line == "0")  break;

        if(!first)  cout << '\n';
        first = false;
        
        stringstream ss(line); // int로 추출
        int k;
        ss >> k;

        vector<int> s(k);
        for(int i = 0;  i < k; ++i)
            ss >> s[i];
        
        vector<int> comb;
        int start = 0;

        getAllNumber(s, comb, start);
    }

    return 0;
}