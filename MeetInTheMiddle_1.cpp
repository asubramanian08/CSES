// https://codeforces.com/problemset/problem/839/E -> Looked at solution
// 10:32 - NA (Coding Time)
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

#define N 45
#define HALF 22
int n, k, adj[N][N], dp[1ll << HALF];
bool isClique(long long mask)
{
    for (int i = 0; i < n; i++)
        if (mask & (1ll << i))
            for (int j = i + 1; j < n; j++)
                if (mask & (1ll << j))
                    if (!adj[i][j])
                        return false;
    return true;
}
int bitCount(long long mask)
{
    int ans = 0;
    for (int i = 0; i < HALF; i++)
        ans += mask & (1ll << i) ? 1 : 0;
    return ans;
}

int main(void)
{
    cin >> n >> k;
    long long mid = n / 2, m1 = 1ll << mid, m2 = 1ll << (n - mid);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> adj[i][j];
    dp[0] = 0;
    for (long long i = 1; i < m1; i++)
        if (isClique(i))
            dp[i] = bitCount(i);
        else
            for (int j = 0; j < mid; j++)
                if (i & (1ll << j))
                    dp[i] = max(dp[i], dp[i ^ (1ll << j)]);
    int maxClique = dp[m1 - 1];
    for (long long i = 0; i < m2; i++)
        if (isClique(i << mid))
        {
            long long mask = m1 - 1;
            for (int j = 0; j < n - mid; j++)
                if (i & (1ll << j))
                    for (int k = 0; k < mid; k++)
                        if (mask & (1ll << k) && !adj[j + mid][k])
                            mask ^= (1ll << k);
            maxClique = max(maxClique, dp[mask] + bitCount(i));
        }
    long double ans = pow((long double)k / maxClique, 2) *
                      (maxClique * (maxClique - 1) / 2);
    cout << std::setprecision(12) << ans << endl;
    return 0;
}