// 1. Maintain an array f where f[d] stores the maximum length of a beautiful subsequence ending in digit d (f[0] is empty).
// 2. Odd digits (1, 3) can append to any existing valid subsequence without forming a multiple of 4.
// 3. Digit 2 can only append to an empty sequence or another 2 (since 12 and 32 form multiples of 4).
// 4. Digit 4 is ignored completely since any single 4 is already a multiple of 4.


#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int n = s.length();

        int f[5] = {0, 0, 0, 0, 0};

        for (int i = 0; i < n; i++) {
            int d = s[i] - '0';
            int g[5];
            for (int j = 0; j <= 4; j++) 
                g[j] = f[j];

            if (d == 1 || d == 3) {
                for (int j = 0; j <= 4; j++) {
                    g[d] = max(g[d], f[j] + 1);
                }
            } 
            else if (d == 2) {
                g[2] = max(g[2], f[0] + 1);
                g[2] = max(g[2], f[2] + 1);
            }

            for (int j = 0; j <= 4; j++) f[j] = g[j];
        }

        int mx = 0;
        for (int j = 0; j <= 4; j++) mx = max(mx, f[j]);

        cout << n - mx << "\n";
    }
    return 0;
}