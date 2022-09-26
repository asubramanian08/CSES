// 1:45 - 2:09
#include <iostream>
using namespace std;

void move(int ct, int from, int to)
{
    if (ct == 0)
        return;
    int other = 6 - from - to;
    move(ct - 1, from, other);
    cout << from << ' ' << to << '\n';
    move(ct - 1, other, to);
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    cout << ((1 << n) - 1) << endl;
    move(n, 1, 3);
}