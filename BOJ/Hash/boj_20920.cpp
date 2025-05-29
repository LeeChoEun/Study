// 20920 영단어 암기는 괴로워, 해시 (실버 3)
// 영어단어장을 만들 때 순서
// 자주 나오는 단어일수록 앞으로 배치
// 단어의 길이가 길수록 앞에
// 알파벳 사전순으로 앞에 있는 단어일 때 앞에
// 길이 M 이상의 단어로만 구성하기

// unordered_map으로 구성해서 단어명, 빈출 횟수
// 횟수로 그룹 나누기
// unordered_map<int, vector<pair<string, int>>> 
// 빈출 횟수, (단어명, 단어 길이)

#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    int N, M;
    cin >> N >> M; // 단어의 개수, 단어 길이 기준

    unordered_map<string, int> word_num;
    vector<string> Total;

    for(int i = 0; i < N; ++i)
    {
        string word = "";
        cin >> word;

        if(word.length() >= M) // 길이가 M이상일 때에만
        {    
            if(word_num[word] == 0)
                Total.push_back(word);
            word_num[word]++;
        }
    }
    // 빈도수 -> 길이 -> 사전
    sort(Total.begin(), Total.end(), [&](const string& a, const string& b){
        if(word_num[a] != word_num[b]) // 빈도수가 같지 않다면
            return word_num[a] > word_num[b]; // 더 높은 빈도수
        if(a.length() != b.length()) // 길이가 다르다면
            return a.length() > b.length(); // 더 긴 단어
        return a < b; // 사전 순
    });

    for(const auto& w : Total)
        cout << w << '\n';
        
    return 0;
}