#include <iostream>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int N, M;
    int s, e, v;
    cin >> N >> M;

    int **dp = new int*[N];
    for(int i=0; i<N; i++)
        dp[i] = new int[M];

    int *values = new int[N];
    for(int i=0; i<N; i++)
    {
        cin >> s >> e >> v;
        for(int j=0; j<s-1; j++)
            dp[i][j] = -1;
        for(int j=e; j<M; j++)
            dp[i][j] = -1;
        values[i] = v;
    }

    int **diff = new int*[N];
    for(int i=0; i<N; i++)
    {
        diff[i] = new int[N];
        for(int j=0; j<N; j++)
            diff[i][j] = abs(values[i] - values[j]);
    }

    for(int i=1; i<M; i++)
        for(int j=0; j<N; j++)
        {
            if(dp[j][i] != -1)
            {
                v = -1;
                for(int k=0; k<N; k++)
                    if (dp[k][i-1] != -1 && v < diff[j][k] + dp[k][i-1])
                        v = diff[j][k] + dp[k][i-1];
                dp[j][i] = v;
            }
        }   

    int answer = 0;
    for(int i=0; i<N; i++)
        if (answer < dp[i][M-1])
            answer = dp[i][M-1];
    
    cout << answer;

    return 0;
}