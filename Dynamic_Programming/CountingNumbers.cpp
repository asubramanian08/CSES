// 7:54 - 8:16 + 9:34 - 10:03
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

long long count(long long x)
{
    long long ans = 1;
    vector<int> v;
    while (x > 0)
    {
        v.push_back(x % 10);
        x /= 10;
    }
    reverse(v.begin(), v.end());
    for (int i = 1; ans && i < v.size(); i++)
        ans = v[i] != v[i - 1];
    for (int i = 0; i < v.size(); i++)
        ans += pow(9ll, i);
    for (int digit = v.size() - 1; digit >= 0; digit--)
    {
        bool works = true;
        for (int i = 1; works && i < digit; i++)
            works = v[i] != v[i - 1];
        if (!works)
            continue;
        long long toAdd = v[digit];
        if (digit != 0 && v[digit - 1] < v[digit])
            toAdd--;
        if (digit == 0)
            toAdd--;
        for (int i = digit + 1; i < v.size(); i++)
            toAdd *= 9;
        ans += toAdd;
    }
    return ans;
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long a, b;
    cin >> a >> b;
    long long ans = count(b);
    if (a != 0)
        ans -= count(a - 1);
    cout << ans << endl;
}