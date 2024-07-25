#include <iostream>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n, temp;
    cin >> n;

    int *coin = new int[n];
    for(int i=0; i<n; i++)
    {
        cin >> temp;
        coin[i] = temp;
    }

    int **dp = new int*[4];
    for(int i=0; i<4; i++)
        dp[i] = new int[n+1];

    
    for(int i=2; i<=n; i+=2)
        dp[0][i] = dp[0][i-2] + coin[i-1];
    
    dp[1][1] = coin[0];
    for(int i=2; i<=n; i++)
        dp[1][i] = max(dp[0][i-1], dp[1][i-2]) + coin[i-1];
    
    for(int i=2; i<=n; i++)
        dp[2][i] = max(dp[1][i-1], dp[2][i-2]) + coin[i-1];

    int answer = 0;
    for(int i=0; i<3; i++)
        if(answer < dp[i][n])
            answer  = dp[i][n];
    
    cout << answer;
    return 0;
}