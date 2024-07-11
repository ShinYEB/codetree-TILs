#include <iostream>
#include <vector>

using namespace std;

bool ismove(int n, int y, int x)
{
    return x>=0 && y>=0 && x<n && y<n;
}

pair<pair<int, int>, char> move(int n, int y, int x, char d)
{
    if (d == 'L')
        if (ismove(n, y, x-1))
            x = x-1;
        else
            d = 'R';

    else if (d == 'R')
        if (ismove(n, y, x+1))
            x = x+1;
        else
            d = 'L';
        
    else if (d == 'U')
        if (ismove(n, y-1, x))
            y = y-1;
        else
            d = 'D';
        
    else if (d == 'D')
        if (ismove(n, y+1, x))
            y = y+1;
        else
            d = 'U';
        
    return make_pair(make_pair(y, x), d);
}

int main() {
    // 여기에 코드를 작성해주세요.
    int T, N, M;
    int x, y;
    char d;
    vector<vector<int>> grid;
    vector<vector<char>> dir_grid;
    vector<pair<pair<int, int>, char>> start, temps;

    cin >> T;

    for (int z=0; z<T; z++)
    {
        cin >> N >> M;
        
        grid.clear();
        start.clear();
        temps.clear();
        
        for (int i=0; i<N; i++)
        {
            vector<int> tempv(N);
            vector<char> temp_dir_v(N);
            grid.push_back(tempv);
            dir_grid.push_back(temp_dir_v);
        }

        for (int i=0; i<M; i++)
        {
            cin >> x >> y >> d;
            start.push_back(make_pair(make_pair(y-1, x-1), d));
        }        

        for (int i=0; i<=2*N+2; i++)
        {
            temps.clear();
            for (int j=0; j<start.size(); j++)
            {
                pair<pair<int, int>, char> tempp = move(N, start[j].first.first, start[j].first.second, start[j].second);
                grid[tempp.first.first][tempp.first.second]++;
                dir_grid[tempp.first.first][tempp.first.second] = tempp.second;
            }
            
            for (int yy=0; yy<N; yy++)
                for (int xx=0; xx<N; xx++)
                {
                    if (grid[yy][xx] == 1)
                        temps.push_back(make_pair(make_pair(yy, xx), dir_grid[yy][xx]));
                    grid[yy][xx] = 0;
                }
            start.clear();
            start = temps;
        }
        cout << start.size() << endl;
    }
    return 0;
}