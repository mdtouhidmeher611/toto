#include <iostream>

using namespace std;

void solve() {
    long long x, y;
    if (!(cin >> x >> y)) return;

    if ((x + y) % 3 != 0) {
        cout << "NO" << endl;
        return;
    }

    long long k = (x + y) / 3;

    if (k >= 0 && x >= 2 * k && x <= 4 * k) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}