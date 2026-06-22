#include <bits/stdc++.h>
using namespace std;

const int M = 200005;
int a[M];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        for (int i = 0; i < n; i++) 
            cin >> a[i];
        sort(a, a + n);
        int c = 0, l = 0, r = n - 1;
        while (l < r) {
            int s = a[l] + a[r];
            if (s == k) {
                c++;
                l++;
                r--;
            } else if (s < k) {
                l++;
            } else {
                r--;
            }
        }
        cout << c << "\n";
    }
    return 0;
}