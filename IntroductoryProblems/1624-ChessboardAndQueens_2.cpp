// 6:17 - 6:23
#include <iostream>
using namespace std;

char board[8][8];
bool col[8], diag1[15], diag2[15];
int ans = 0;

void backtracking(int row)
{
    if (row == 8)
    {
        ans++;
        return;
    }
    for (int i = 0; i < 8; i++)
        if (int d1 = row + i, d2 = row - i + 7;
            board[row][i] == '.' && !col[i] && !diag1[d1] && !diag2[d2])
        {
            col[i] = diag1[d1] = diag2[d2] = true;
            backtracking(row + 1);
            col[i] = diag1[d1] = diag2[d2] = false;
        }
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++)
            cin >> board[i][j];
    backtracking(0);
    cout << ans << endl;
}