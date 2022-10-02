// 4:21 - 4:35
#include <iostream>
#include <iomanip>
using namespace std;

long long n, k, adj[45], cliqueSize = 0, x;
void dfs(long long mask, long long used)
{
    if (mask == 0)
        cliqueSize = max(cliqueSize, used);
    else
        while (mask)
        {
            long long ct = 0, last = -1;
            for (long long i = 0; i < n; i++)
                if (mask & (1ll << i))
                    ct++, last = i;
            mask ^= (1ll << last);
            if (used + ct > cliqueSize)
                dfs(mask & adj[last], used + 1);
        }
}

int main(void)
{
    cin >> n >> k;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            cin >> x;
            adj[i] |= x << j;
        }
    dfs((1ll << n) - 1, 0);
    double ans = (double)k * k * (cliqueSize - 1) / cliqueSize / 2;
    cout << setprecision(12) << ans << endl;
}