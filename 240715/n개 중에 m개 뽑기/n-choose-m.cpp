#include <iostream>
using namespace std;

int K, N;
int *list;

void recursion(int cnt, int prior)
{
    if (cnt == N)
    {
        for (int i=0; i<N; i++)
            cout << list[i] << " ";
        cout << "\n";
    }
    else
    {
        for (int i=prior; i<=K; i++)
        {
            list[cnt] = i;
            recursion(cnt+1, i+1);
        }
    }
}

int main() {

    cin >> K >> N;
    
    list = new int[N];
    
    recursion(0, 1);
    
    return 0;
}