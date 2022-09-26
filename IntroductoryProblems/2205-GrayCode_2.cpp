// 1:39 - 1:43
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<string> ans{"0"};
    for (int i = 1; i < n; i++)
        ans[0] += '0';
    for (int i = 0; i < n; i++)
        for (int j = ans.size() - 1; j >= 0; j--)
        {
            string str = ans[j];
            str[n - i - 1] = '1';
            ans.push_back(str);
        }
    for (const auto &str : ans)
        cout << str << endl;
}