#include <iostream>
using namespace std;

int K, N, temp;
int *list;

void recursion(int idx, int prior, int cnt)
{
    if (idx == N)
    {
        for (int i=0; i<N; i++)
            cout << list[i] << " ";
        cout << "\n";
    }
    else
    {
        for (int i=1; i<=K; i++)
        {
            if (i == prior)
            {
                temp = cnt + 1;
                if (temp >= 3)
                   continue;
            }
            else
                temp = 1;
            list[idx] = i;
            recursion(idx+1, i, temp);
        }
    }
}

int main() {

    cin >> K >> N;
    
    list = new int[N];
    
    recursion(0, -1, 0);
    
    return 0;
}