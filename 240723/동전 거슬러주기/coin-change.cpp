#include <iostream>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int N, M, temp;
    cin >> N >> M;

    int *coins = new int[M+1];

    for(int i=0; i<N; i++)
    {
        cin >> temp;
        coins[temp] = 1;
    }

    for (int i=1; i<=M; i++)
    {
        for(int j=1; j<(int)(i/2); j++)
        {
            if (coins[j] != 0 && coins[i-j] != 0)
            {
                if (coins[i] == 0)
                    coins[i] = coins[j] + coins[i-j]; 
                else
                    coins[i] = min(coins[i], coins[j] + coins[i-j]);
            }
            
        }
    }

    if (coins[M] == 0)
        cout << -1;
    else
        cout << coins[M];

    return 0;
}