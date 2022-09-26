// 6:45 - 6:50
#include <iostream>
#include <string>
using namespace std;

int main(void)
{
    long long q, k, dig, mult;
    cin >> q;
    while (q--)
    {
        cin >> k;
        k--;
        for (dig = mult = 1; k >= dig * 9 * mult; dig++, mult *= 10)
            k -= dig * 9 * mult;
        cout << to_string(mult + k / dig)[k % dig] << endl;
    }
}