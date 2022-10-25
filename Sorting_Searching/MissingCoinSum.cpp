// 8:44 - 8:52
#include <iostream>
#include <algorithm>
using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, arr[200010];
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    sort(arr, arr + n);
    long long first = 1;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > first)
            break;
        first += arr[i];
    }
    cout << first << endl;
    return 0;
}