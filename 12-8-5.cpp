#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int test_case;
    cin >> test_case;

    while (test_case--) {
        int n;
        cin >> n;
        int a[6005];
        for (int i = 0; i < n; i++) cin >> a[i];
        int answer = 0;
        for (int len = n / 2; len >= 1; len--) {
            int L[6005], R[6005];
            int cnt = 0;
            for (int l = 0; l + len - 1 < n; l++) {
                int r = l + len - 1;
                bool is_used[6005] = {0};
                int mn = 1e9, mx = -1e9;
                bool is_ok = true;
                for (int i = l; i <= r; i++) {
                    if (is_used[a[i]]) {
                        is_ok = false;
                        break;
                    }
                    is_used[a[i]] = true;
                    mn = min(mn, a[i]);
                    mx = max(mx, a[i]);
                }
                if (is_ok && mx - mn + 1 == len) {
                    L[cnt] = l;
                    R[cnt] = r;
                    cnt++;
                }
            }
            bool is_found = false;
            for (int i = 0; i < cnt && !is_found; i++) {
                for (int j = i + 1; j < cnt && !is_found; j++) {
                    if (!(R[i] < L[j] || R[j] < L[i])) continue;
                    bool is_used[6005] = {0};
                    int mn = 1e9, mx = -1e9;
                    bool is_ok = true;
                    for (int k = L[i]; k <= R[i]; k++) {
                        is_used[a[k]] = true;
                        mn = min(mn, a[k]);
                        mx = max(mx, a[k]);
                    }
                    for (int k = L[j]; k <= R[j]; k++) {
                        if (is_used[a[k]]) {
                            is_ok = false;
                            break;
                        }
                        is_used[a[k]] = true;
                        mn = min(mn, a[k]);
                        mx = max(mx, a[k]);
                    }
                    if (is_ok && mx - mn + 1 == 2 * len) {
                        answer = len;
                        is_found = true;
                    }
                }
            }
            if (is_found) break;
        }
        cout << answer << "\n";
    }

    return 0;
}