#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;

    vector<int> res(n, 0);
    int v = 1;

    for (int i = k - 1; i < n; i += k) {
        res[i] = v++;
    }

    for (int i = 0; i < n; i++) {
        if (res[i] == 0) {
            res[i] = v++;
        }
    }

    for (int i = 0; i < n; i++) {
        cout << res[i] << (i == n - 1 ? "" : " ");
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}