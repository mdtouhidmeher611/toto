#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int test;
    cin >> test;

    while (test--) {
        int n;
        cin >> n;

        vector<int> a(n), b(n);

        int mis = 0;
        int mismatch = 0;

        for (int i = 0; i < n; i++)
            cin >> a[i];

        for (int i = 0; i < n; i++) {
            cin >> b[i];
            if (a[i] != b[i]) {
                mis++;
                if (a[i] == 1) mismatch++;
            }
        }

        if (mis == 0) {
            cout << 0 << '\n';
        } 
        else if (mis % 2 == 1) {
            cout << -1 << '\n';
        } 
        else if (mismatch % 2 == 1) {
            cout << 1 << '\n';
        } 
        else {
            cout << 2 << '\n';
        }
    }

    return 0;
}