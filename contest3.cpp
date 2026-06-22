#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int M = 200005;
ll c[M];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) 
            cin >> c[i];

        ll ans = 0;
        if (n == 1) {
            ans = c[0] >= 3 ? c[0] : 0;
        } 
        else if (n == 2) {
            if (c[0] >= 1 && c[1] >= 2) 
                ans = c[0] + c[1];
            else if (c[1] >= 3) ans = c[1];
        } 
        else {
            ll s = 0;
            for (int i = 0; i < n; i++) 
                s += c[i];
            ll mx = c[n - 1];
            ll sm = s - mx - c[n - 2];
            if (mx <= sm + c[n - 2]) {
                ans = s;
            } 
            else {
                ans = (sm + c[n - 2]) * 2 + c[n - 2];
            }
        }
        cout << ans << "\n";
    }
    return 0;
}