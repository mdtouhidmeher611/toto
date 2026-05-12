#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[300005];


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    ll s = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        s += a[i];
    }
    sort(a, a + n, greater<ll>());
    int m;
    cin >> m;
    while (m--) {
        int q;
        cin >> q;
        cout << s - a[q - 1] << "\n";
    }

    return 0;
}