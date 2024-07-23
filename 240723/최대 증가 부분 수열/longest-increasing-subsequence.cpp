#include <iostream>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int N, temp;
    cin >> N;

    int *dp = new int[N];

    for(int i=0; i<N; i++)
    {
        cin >> temp;

        for(int j=0; j<N; j++)
        {
            if(dp[j] == 0)
            {
                dp[j] = temp;
                break;
            }
            else if(dp[j] >= temp)
            {
                dp[j-1] = temp;
                break;
            }
        }
    }

    for(int i=0; i<N; i++)
        if(dp[i] == 0)
        {
            cout << i;
            break;
        }

    if (dp[N-1] != 0)
        cout << N;

    return 0;
}