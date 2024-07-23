#include <iostream>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int N;
    cin >> N;

    int *dp = new int[1000];
    dp[1] = 1;
    dp[2] = 1;

    for(int i=3; i<N; i++)
    {
        dp[i] = (dp[i-2] + dp[i-3]) % 10007;
    }

    cout << dp[N-1];

    return 0;
}