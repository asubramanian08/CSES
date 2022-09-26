// 3:30 - 3:59
#include <iostream>
using namespace std;

char board[8][8];
int ans = 0;

bool inRange(int x) { return 0 <= x && x < 8; }
void mini_updt(int x, int y, bool add, int queenNum)
{
    if (inRange(x) && inRange(y) &&
        (board[x][y] == '.' || board[x][y] == '0' + queenNum))
        board[x][y] = add ? '0' + queenNum : '.';
}
void update(int x, int y, bool add, int queenNum)
{
    board[x][y] = add ? 'Q' : '.';
    for (int i = x + 1; i < 8; i++)
    {
        mini_updt(i, y, add, queenNum);
        mini_updt(i, y + (i - x), add, queenNum);
        mini_updt(i, y - (i - x), add, queenNum);
    }
}
void recursive(int row)
{
    if (row == 8)
    {
        ans++;
        return;
    }
    for (int i = 0; i < 8; i++)
        if (board[row][i] == '.')
        {
            update(row, i, true, row);
            recursive(row + 1);
            update(row, i, false, row);
        }
}
string displayboard()
{
    string str = "";
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
            str += board[i][j];
        str += '\n';
    }
    return str;
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++)
            cin >> board[i][j];
    recursive(0);
    cout << ans << endl;
}