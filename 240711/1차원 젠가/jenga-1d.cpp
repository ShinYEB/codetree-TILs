#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N, temp, p;
    int s, e;
    vector<int> A, B;
    cin >> N;
    
    for (int i=0; i<N; i++) 
    {
        cin >> temp;
        A.push_back(temp);
    }

    for (int i=0; i<2; i++)
    {
        cin >> s >> e;
        for (int j=0; j<A.size(); j++)
            if (j+1 < s || j >= e)B.push_back(A[j]);
        A.clear();
        A = B;
        B.clear();
    }
    
    cout << A.size() << "\n";
    for (int i=0; i<A.size(); i++)
        cout << A[i] << "\n";

    return 0;
}