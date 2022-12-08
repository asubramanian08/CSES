// 7:30 - ? + 9:49 - 10:00
#include <iostream>
using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, x, arr[21];
    cin >> n >> x;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    // sort(arr, arr + n);
    pair<int, int> DP[1 << 20] = {{1, x}};
    for (int i = 1; i < (1 << n); i++)
    {
        DP[i] = {21, 0};
        for (int j = 0; j < n; j++)
            if (i & (1 << j))
            {
                int altRound = DP[i ^ (1 << j)].first;
                int altSpace = DP[i ^ (1 << j)].second - arr[j];
                if (altSpace < 0)
                    altRound++, altSpace = x - arr[j];
                if (altRound < DP[i].first ||
                    (altRound == DP[i].first &&
                     altSpace > DP[i].second))
                    DP[i] = {altRound, altSpace};
            }
    }
    cout << DP[(1 << n) - 1].first << endl;
}