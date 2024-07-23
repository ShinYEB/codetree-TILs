#include <iostream>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int N;
    cin >> N;

    int *dp = new int[46];
    dp[0] = 1;
    dp[1] = 1;

    for(int i=2; i<N; i++)
        dp[i] = dp[i-1] + dp[i-2];

    cout << dp[N-1];
    return 0;
}