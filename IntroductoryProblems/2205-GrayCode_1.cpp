// 1:19 - 1:32
#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> ans = {0, 1};
    for (int i = 1; i < n; i++)
    {
        int len = ans.size();
        for (int j = len - 1; j >= 0; j--)
            ans.push_back(ans[j] + (1 << i));
    }
    for (int i = 0; i < ans.size(); i++)
    {
        int x = ans[i];
        for (int j = n - 1; j >= 0; j--)
            cout << ((x >> j) & 1);
        cout << endl;
    }
}