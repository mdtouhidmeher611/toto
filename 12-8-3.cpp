#include<bits/stdc++.h>
using namespace std;

int main() {
    int test_case;
    cin >> test_case;
    while (test_case--) {
        long long a, b, x;
        cin >> a >> b >> x;
        long long p[40], q[40];
        int n = 0, m = 0;
        long long c = a;
        while (1) {
            p[n++] = c;
            if (c == 0) 
                break;
            c /= x;
        }
        c = b;
        while (1) {
            q[m++] = c;
            if (c == 0) 
                break;
            c /= x;
        }
        long long ans;
        if (a > b)
             ans = a - b;
        else 
            ans = b - a;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                long long d;
                if (p[i] > q[j]) 
                    d = p[i] - q[j];
                else 
                d = q[j] - p[i];
                ans = min(ans, 1LL * i + j + d);
            }
        }
        cout << ans << endl;
    }
    return 0;
}