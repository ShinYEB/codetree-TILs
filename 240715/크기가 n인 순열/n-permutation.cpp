#include <iostream>
using namespace std;

int N;
int *list;
int *visited;

void recursion(int cnt)
{
    if (cnt == N)
    {
        for (int i=0; i<N; i++)
            cout << list[i] << " ";
        cout << "\n";
    }
    else
    {
        for (int i=1; i<=N; i++)
            if (visited[i-1] == 0)
            {
                list[cnt] = i;
                visited[i-1] = 1;
                recursion(cnt+1);
                visited[i-1] = 0;
            } 
    }
}

int main() {

    cin >> N;
    
    list = new int[N];
    visited = new int[N];
    
    recursion(0);
    
    return 0;
}