#include <iostream>
#include <vector>

using namespace std;

bool ismove(int n, int y, int x)
{
    return x>=0 && y>=0 && x<n && y<n;
}

int main() {
    // 여기에 코드를 작성해주세요.
    int n, r, c, t;
    int ans;
    bool is_continue = true;
    vector<vector<int>> A;
    vector<int> temp;

    cin >> n >> r >> c;
    
    for (int i=0; i<n; i++)
    {
        temp.clear();
        for (int j=0; j<n; j++)
        {
            cin >> t;
            temp.push_back(t);
        }
        A.push_back(temp);
    }

    r--; c--;
    ans = A[r][c];
    int cnt = 0;
    while (is_continue)
    {
        cout << A[r][c] << " ";
        is_continue = false;
        if (ismove(n, r-1, c) && A[r-1][c] > ans)
        {
            ans = A[r-1][c];
            is_continue = true;
            r = r-1;
        }
        else if (ismove(n, r+1, c) && A[r+1][c] > ans)
        {
            ans = A[r+1][c];
            is_continue = true;
            r = r+1;
        }
        else if (ismove(n, r, c-1) && A[r][c-1] > ans)
        {
            ans = A[r][c-1];
            is_continue = true;
            c = c-1;
        }
        else if (ismove(n, r, c+1) && A[r][c+1] > ans)
        {
            ans = A[r][c+1];
            is_continue = true;
            c = c+1;
        }        
            
    }

    return 0;

}