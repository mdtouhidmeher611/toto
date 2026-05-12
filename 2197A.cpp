#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        ll x;
        cin >> x;
        if (x % 9 != 0) {
            cout << 0 << "\n";
            continue;
        }
        int c = 0;
        for (ll y = x; y <= x + 100; ++y) {
            ll s = 0, tmp = y;
            while (tmp) {
                s += tmp % 10;
                tmp /= 10;
            }
            if (y - s == x) c++;
        }
        cout << c << "\n";
    }
    return 0;
}