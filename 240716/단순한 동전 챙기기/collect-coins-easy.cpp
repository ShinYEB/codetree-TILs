#include <iostream>
using namespace std;

int N, idx;
int *listx = new int[11];
int *listy = new int[11];
int *list = new int[4];
int result = 1000000;
int **dist; 
string temp;

void recursion(int cnt, int prior)
{
    if (cnt == 4)
    {
        if (prior == 10)
        {
            int t = 0;
            for(int i=0; i<4; i++)
                t += list[i];
            result = min(result, t);
        }
    }
    else
    {
        for(int i=prior+1; i<11; i++)
            if (dist[prior][i] != 0)
            {
                list[cnt] = dist[prior][i];
                recursion(cnt+1, i);
            }
    }
}


int main() {

    cin >> N;

    dist = new int*[10];
    for (int i=0; i<10; i++)
        dist[i] = new int[11];
    

    for (int i=0; i<N; i++)
    {
        cin >> temp;
        for (int j=0; j<N; j++)
            if (temp[j] != '.')
            {
                if (temp[j] == 'S')
                    idx = 0;
                else if (temp[j] == 'E')
                    idx = 10;
                else
                    idx = temp[j] - '0';
                listx[idx] = j;
                listy[idx] = i;
            }
    }

    for (int i=0; i<10; i++)
        if(listx[i] != 0 || listy[i] != 0)
            for (int j=i+1; j<11; j++)
                if(listx[j] != 0 || listy[j] != 0)
                    dist[i][j] = abs(listx[i] - listx[j]) + abs(listy[i] - listy[j]);

    recursion(0, 0);
    if (result == 1000000)
        cout << -1;
    else
        cout << result;

    return 0;
}