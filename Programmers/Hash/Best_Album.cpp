// 가장 많이 재생된 장르 찾기
// 장르 내에서 많이 재생된 순서
// 2곡 고르기, 재생횟수가 같다면 고유 번호가 낮은 순으로
// 고유 번호 return
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    // 많이 재생된 장르 순으로 내림차순 하기 위한 map
    unordered_map<string, int> genre_total; // 장르명, 전곡의 play 수
    unordered_map<string, vector<pair<int, int>>> music_total; // 장르명, (play 수, 고유번호)
    
    // unordered_map에 저장
    for(int i = 0; i < genres.size(); ++i)
    {
        genre_total[genres[i]] += plays[i];
        music_total[genres[i]].push_back({plays[i], i});
    }
    
    // 장르 별 재생 많이 된 순으로 내림차순 정렬
    vector<string> sort_genre;
    for(const auto& num : genre_total)
        sort_genre.push_back(num.first);
    
    sort(sort_genre.begin(), sort_genre.end(), [&](const string& a, const string& b){
        return genre_total[a] > genre_total[b];
    }); // 비교는 숫자로, 반환은 장르명으로
    
    // 장르별 많이 들은 순으로 내림차순
    // 재생 횟수가 같으면 고유 번호가 낮은 순으로(오름차순)
    for(const string& num : sort_genre)
    {
        auto& songs = music_total[num];
        
        sort(songs.begin(), songs.end(), [](const pair<int, int>& a, const pair<int, int>& b){
           
            if(a.first == b.first)
                return a.second < b.second;
            
            return a.first > b.first; 
        });
        
        for(int i = 0; i < 2 && i < songs.size(); ++i)
            answer.push_back(songs[i].second);
    }
    
    return answer;
}