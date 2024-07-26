#include <iostream>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    string str1, str2;
    cin >> str1 >> str2;
    
    int str1_size = str1.length();
    int str2_size = str2.length();

    int **dp = new int*[str1_size+1];
    for(int i=0; i<=str1_size; i++)
        dp[i] = new int[str2_size+1];
    
    for(int i=0; i<=str1_size; i++)
        dp[i][0] = i;

    for(int i=0; i<=str2_size; i++)
        dp[0][i] = i;

    for(int i=0; i<str1_size; i++)
        for(int j=0; j<str2_size; j++)
        {
            if(str1[i] == str2[j])
                dp[i+1][j+1] = dp[i][j];
            else
                dp[i+1][j+1] = min(dp[i][j+1], dp[i+1][j]) + 1;
        }

    cout << dp[str1_size][str2_size];

    return 0;
}