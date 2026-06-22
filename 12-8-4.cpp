#include <bits/stdc++.h>
using namespace std;

void do_the_job() {
    int n, k;
    cin >> n >> k;
    map<int, int> f;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        f[x]++;
    }
    vector<pair<int, int>> v;
    for (auto const& p : f) {
        v.push_back(p);
    }
    int m = v.size();
    vector<int> dp(m, 0); 
    bool win = false;
    int c = 0;
    int r = m - 1;
    for (int i = m - 1; i >= 0; i--) {
        while (v[r].first > v[i].first + k) {
            if (dp[r] == 0) {
                c--;
            }
            r--;
        }
        bool ok = (c > 0);
        if (v[i].second % 2 == 0) {
            dp[i] = ok ? 1 : 0;
        } 
        else {
            dp[i] = ok ? 0 : 1;
        }
        int remain = v[i].second - 1;
        bool current = false;
        if (remain > 0) {
            if (remain % 2 == 0) {
                current = ok;
            } 
            else {
                current = !ok;
            }
        } 
        else {
            current = ok;
        }

        if (current) {
            win = true;
        }

        if (dp[i] == 0) {
            c++;
        }
    }
    if (win) {
        cout << "YES\n";
    } 
    else {
        cout << "NO\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        do_the_job();
    }
    return 0;
}