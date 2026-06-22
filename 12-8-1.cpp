#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int h[5];
        for (int i = 0; i < n; i++) {
            cin >> h[i];
        }
        sort(h, h + n);
        cout << h[n - 1] - h[0] + 1 << endl;
    }
    return 0;
}