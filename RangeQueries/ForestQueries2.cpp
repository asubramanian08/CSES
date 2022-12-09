// 7:53 - 8:15 + 10:15 - 10:53
#include <iostream>
using namespace std;

// data
int n, q;

// BIT
int bTree[1010][1010] = {{0}};
int query(int x, int y)
{
    if (x == -1 || y == -1)
        return 0;
    int sum = 0;
    for (int i = x + 1; i > 0; i -= (i & -i))
        for (int j = y + 1; j > 0; j -= (j & -j))
            sum += bTree[i][j];
    return sum;
}
int query(int x1, int y1, int x2, int y2)
{
    return query(x2, y2) - query(x2, y1 - 1) -
           query(x1 - 1, y2) + query(x1 - 1, y1 - 1);
}
void updt(int x, int y, int cng)
{
    for (int i = x + 1; i <= n; i += (i & -i))
        for (int j = y + 1; j <= n; j += (j & -j))
            bTree[i][j] += cng;
}

int main(void)
{
    cin >> n >> q;
    char ch;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            cin >> ch;
            if (ch == '*')
                updt(i, j, 1);
        }
    int type, x1, y1, x2, y2;
    for (int i = 0; i < q; i++)
    {
        cin >> type >> x1 >> y1;
        x1--, y1--;
        if (type == 1)
        {
            updt(x1, y1, query(x1, y1, x1, y1) ? -1 : +1);
            continue;
        }
        cin >> x2 >> y2;
        x2--, y2--;
        cout << query(x1, y1, x2, y2) << endl;
    }
    return 0;
}