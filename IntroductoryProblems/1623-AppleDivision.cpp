// 3:18 - 4:17 (Implemented for n<=40)
#include <iostream>
#include <set>
using namespace std;
#define MAX_N 40

int main(void)
{
    // IO setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // read
    int n, arr[MAX_N];
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    // calculate all possible sums for the first half
    int div = n / 2;
    set<long long> sums;
    for (int mask = 0; mask < (1 << div); mask++)
    {
        long long sum = 0;
        for (int i = 0; i < div; i++)
            if (mask & (1 << i))
                sum += arr[i];
        sums.insert(sum);
    }

    // set up
    long long secondSum = 0;
    for (int i = div; i < n; i++)
        secondSum += arr[i];
    long long firstSum = *sums.rbegin();

    // find the minimum difference
    int rem = n - div;
    long long ans = 1e18;
    for (int mask = 0; mask < (1 << rem); mask++)
    {
        long long sum = 0;
        for (int i = 0; i < rem; i++)
            if (mask & (1 << i))
                sum += arr[i + div];
        long long diff = (firstSum + sum) - (secondSum - sum);
        long long lookingFor = (diff + 1) / 2;
        auto it = sums.lower_bound(lookingFor);
        if (it != sums.end())
            ans = min(ans, abs(diff - 2 * *it));
        if (it != sums.begin())
            ans = min(ans, abs(diff - 2 * *prev(it)));
    }

    // print and return
    cout << ans << endl;
    return 0;
}