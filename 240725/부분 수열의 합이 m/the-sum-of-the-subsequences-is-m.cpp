#include <iostream>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.

    int n, m, temp;
    cin >> n >> m;
    
    int *coins = new int[n];
    for(int i=0; i<n; i++)
    {
        cin >> temp;
        coins[i] = temp;
    }

    int *dp = new int[m+1];
    dp[0] = 0;
    for(int i=1; i<m+1; i++)
        dp[i] = -1;

    for(int c=0; c<n; c++)
    {
        for(int i=m; i>=coins[c]; i--)
        {
            if(dp[i-coins[c]] > -1)
            {
                if(dp[i] == -1)
                    dp[i] = dp[i-coins[c]] + 1;
                else
                    dp[i] = min(dp[i-coins[c]]+1, dp[i]);
            }
        }
    }

    cout << dp[m];

    return 0;
}