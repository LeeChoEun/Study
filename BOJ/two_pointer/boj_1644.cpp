// 1644 소수의 연속합, 투 포인터 (골드3)
// 하나 이상의 연속된 소수들의 합으로 나타낼 수 있는 자연수
// 경우의 수

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<int>get_prime(int n)
{
    vector<bool> is_prime(n+1, true);
    vector<int> primes;
    is_prime[0] = is_prime[1] = false;

    for(int i = 2; i <= n; i++)
    {
        if(is_prime[i])
        {
            
        }
    }
}

// 에라토스테네스의 체로 소수를 구해야함
vector<int>get_primes(int n)
{
    vector<bool> is_prime(n+1, true);
    vector<int> primes;
    is_prime[0] = is_prime[1] = false;

    for(int i = 2; i <= n; i++)
    {
        if(is_prime[i])
        {
            primes.push_back(i);
            for(int j = 2*i; j <= n; j += i)
                is_prime[j] = false;
        }
    }
    return primes;
}


int main(void)
{
    int N;
    cin >> N;

    vector<int> primes = get_primes(N);
    int left = 0, right = 0, sum = 0;
    int result = 0;

    while(true)
    {
        if(sum >= N)
            sum -= primes[left++];
        else if(right == primes.size())
            break;
        else
            sum += primes[right++];
        

        if(sum == N)
            result++;
    }

    cout << result << "\n";
    return 0;
}