/*문자열 파싱 + 숫자 변환 기초*/

/*예시 상황*/
// 문자열로 숫자가 공백으로 구분되어 주어졌을 때,
// 숫자로 변환해서 벡터에 각각 넣는 방법

#include <iostream>
#include <vector>
#include <string>
#include <sstream> // stringstream 사용하기 위해 필수 헤더

using namespace std;

int main(){
    vector<string> records = {
        "100 120 90",
        "110 110 95",
        "95 120 130",
        "80 100 150",
        "100 100 100"
    };

    vector<int> actuals, predicts, consumptions;

    for (string line : records) {
        stringstream ss(line);
        int a, b, c;
        ss >> a >> b >> c;
        actuals.push_back(a);
        predicts.push_back(b);
        consumptions.push_back(c);
    }
}

