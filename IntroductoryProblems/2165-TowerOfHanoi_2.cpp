// 2:13 - 2:15
#include <iostream>
using namespace std;

void move(int block, int A, int B, int C)
{
    if(block == 0) return;
    move(block - 1, A, C, B);
    cout << A << ' ' << C << '\n';
    move(block - 1, B, A, C);
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n;
    cout << ((1 << n) - 1) << endl;
    move(n, 1, 2, 3);
}