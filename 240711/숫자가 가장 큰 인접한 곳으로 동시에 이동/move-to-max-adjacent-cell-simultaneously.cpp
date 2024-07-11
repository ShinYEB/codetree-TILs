#include <iostream>
#include <vector>

using namespace std;

bool ismove(int n, int y, int x)
{
    return x>=0 && y>=0 && x<n && y<n;
}

pair<int, int> move(vector<vector<int>> A, int n, int y, int x)
{
    int ans = 0;
    
    if (ismove(n, y-1, x) && A[y-1][x] > ans)
    {
        ans = A[y-1][x];
        y = y-1;
    }
    else if (ismove(n, y+1, x) && A[y+1][x] > ans)
    {
        ans = A[y+1][x];
        y = y+1;
    }
    else if (ismove(n, y, x-1) && A[y][x-1] > ans)
    {
        ans = A[y][x-1];
        x = x-1;
    }
    else if (ismove(n, y, x+1) && A[y][x+1] > ans)
    {
        ans = A[y][x+1];
        x = x+1;
    }       
    return make_pair(y, x);
}

int main() {
    // 여기에 코드를 작성해주세요.
    int n, m, t, tempi;
    int r, c;
    int ans;
    bool is_continue = true;
    vector<vector<int>> A, board;
    vector<pair<int, int>> start, tempv;
    vector<int> temp, tempb;

    cin >> n >> m >> t;
    
    for (int i=0; i<n; i++)
    {
        temp.clear();
        for (int j=0; j<n; j++)
        {
            cin >> tempi;
            temp.push_back(tempi);
            tempb.push_back(0);
        }
        A.push_back(temp);
        board.push_back(tempb);
    }
    
    for (int i=0; i<m; i++)
    {
        cin >> r >> c;
        start.push_back(make_pair(r-1, c-1));
    }


    for (int i=0; i<t; i++)
    {
        tempv.clear();
        
        for (int j=0; j<start.size(); j++)
        {
            pair<int, int> tempp = move(A, n, start[j].first, start[j].second);
            r = tempp.first;
            c = tempp.second;
            
            board[r][c] = board[r][c] + 1;
        }

        for (int y=0; y<n; y++)
            for (int x=0; x<n; x++)
                {
                    if (board[y][x] == 1)
                        tempv.push_back(make_pair(y, x));
                    board[y][x] = 0;
                }
        start.clear();
        start = tempv;
    }

    cout << start.size();
    return 0;

}