#include <iostream>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.

    int N, temp;
    cin >> N;

    int **matrix = new int*[N];
    for(int i=0; i<N; i++)
        matrix[i] = new int[N];    

    for(int y=0; y<N; y++)
        for(int x=0; x<N; x++)
        {
            cin >> temp;
            matrix[y][x] = temp; 
        }

    for(int i=1; i<N; i++)
    {
        matrix[0][i] = min(matrix[0][i-1], matrix[0][i]);
        matrix[i][0] = min(matrix[i-1][0], matrix[i][0]);
    }
 
    for(int y=1; y<N; y++)
        for(int x=1; x<N; x++)
        {
            temp = max(matrix[y-1][x], matrix[y][x-1]);
            matrix[y][x] = min(temp, matrix[y][x]);
        }
    cout << matrix[N-1][N-1];

    return 0;
}