// 6:25 - 6:38
#include <iostream>
using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long q, k;
    cin >> q;
    while (q--)
    {
        cin >> k;
        long long digits = 1, mult = 1;
        while (k > digits * 9 * mult)
        {
            k -= digits * 9 * mult;
            digits++;
            mult *= 10;
        }
        long long x = mult + (k - 1) / digits;
        long long y = (k - 1) % digits;
        while (y < digits - 1)
        {
            x /= 10;
            y++;
        }
        cout << x % 10 << endl;
    }
}