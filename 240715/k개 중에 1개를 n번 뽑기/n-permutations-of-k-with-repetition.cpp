#include <iostream>
using namespace std;

void recursion(int idx, int n, int k, int *li)
{
    if (idx == n)
    {
        for (int i=0; i<n; i++)
            cout << li[i] << " ";
        cout << "\n";
    }
    else
    {
        for (int i=1; i<=k; i++)
        {
            li[idx] = i;
            recursion(idx+1, n, k, li);
        }
    }
}

int main() {

    int K, N;
    cin >> K >> N;
    int *list = new int[N];
    
    recursion(0, N, K, list);
    
    return 0;
}