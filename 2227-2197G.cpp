#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        long long a[200010];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        
        bool valid[200010] = {false};
        for (int i = 1; i < n - 1; i++) {
            valid[i] = (a[i-1] + a[i+1] > a[i]);
        }
        
        long long ans = n;
        int i = 1;
        while (i < n - 1) {
            if (!valid[i]) {
                i++;
                continue;
            }
            int j = i;
            while (j < n - 1 && valid[j]) {
                j++;
            }
            int len = j - i;
            ans += len;  
            i = j;
        }
        
        cout << ans << '\n';
    }
    
    return 0;
}