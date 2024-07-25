#include <iostream>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int N, temp;
    int result = 0;
    cin >> N;

    int *list = new int[N];
    for(int i=0; i<N; i++)
    {
        cin >> temp;
        list[i] = temp;
    }

    int *dp = new int[N+1];
    for(int i=1; i<=N; i++)
        dp[i] = -1;

    for(int i=1; i<=N; i++)
    {
        dp[i] = max(dp[i-1] + list[i-1], list[i-1]);
        if(result < dp[i])
            result = dp[i];
    }

    cout << result;

    return 0;
}