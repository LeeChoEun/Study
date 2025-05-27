// 3273 두 수의 합 (투 포인터 문항) 실버3
// n개의 수열이 주어지고, x라는 자연수가 주어짐
// 이 때 수열의 두 값을 더했을 때 x가 나오는 쌍의 수를 구하기

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
    int n;
    cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];

    int x;
    cin >> x;

    sort(a.begin(), a.end());   //오름차순 정렬렬

    int result = 0;
    int left = 0;
    int right = n - 1;

    while(left < right)
    {
        int sum = a[left] + a[right];
        if(sum == x)
        {
            result++;
            left++;
            right--;
        }
        else if(sum < x)
            left++;
        else
            right--;
    }

    cout << result << "\n";
    return 0;
}