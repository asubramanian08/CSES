// 3:30 -
#include <iostream>
using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    int ans = 0;
    for (int i = 0; i < n; i++)
        ans = (ans << 1) + 1;
    cout << ans << endl;
}