// 7:17 - ? + 9:19 - 9:44
#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k;
    cin >> n >> k;
    long long *arr = new long long[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    multiset<long long> low, high;
    for (int i = 0; i < k; i++)
        low.insert(arr[i]);
    for (int i = 0; i < k / 2; i++)
    {
        high.insert(*low.rbegin());
        low.erase(prev(low.end()));
    }
    long long lSum = 0, hSum = 0, med = *low.rbegin();
    for (long long x : low)
        lSum += x;
    for (long long x : high)
        hSum += x;
    cout << hSum - lSum + (k % 2 ? med : 0);
    for (int i = k; i < n; i++)
    {
        if (arr[i] > *low.rbegin())
        {
            high.insert(arr[i]);
            hSum += arr[i];
        }
        else
        {
            low.insert(arr[i]);
            lSum += arr[i];
        }
        if (auto it = low.find(arr[i - k]); it != low.end())
        {
            low.erase(it);
            lSum -= arr[i - k];
        }
        else
        {
            high.erase(high.find(arr[i - k]));
            hSum -= arr[i - k];
        }
        while (high.size() > low.size())
        {
            lSum += *high.begin();
            low.insert(*high.begin());
            hSum -= *high.begin();
            high.erase(high.begin());
        }
        while (low.size() - 1 > high.size())
        {
            hSum += *low.rbegin();
            high.insert(*low.rbegin());
            lSum -= *low.rbegin();
            low.erase(prev(low.end()));
        }
        cout << ' ' << hSum - lSum + (k % 2 ? *low.rbegin() : 0);
    }
    cout << endl;
    return 0;
}