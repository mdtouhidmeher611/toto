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
        vector<long long> arr(n);
        for (int i = 0; i < n; i++) cin >> arr[i];

        vector<long long> div6, div2, div3, others;

        for (auto x : arr) {
            if (x % 6 == 0) div6.push_back(x);
            else if (x % 2 == 0) div2.push_back(x);
            else if (x % 3 == 0) div3.push_back(x);
            else others.push_back(x);
        }

        // Concatenate in the optimal order
        vector<long long> result;
        result.insert(result.end(), div6.begin(), div6.end());
        result.insert(result.end(), div2.begin(), div2.end());
        result.insert(result.end(), div3.begin(), div3.end());
        result.insert(result.end(), others.begin(), others.end());

        for (int i = 0; i < n; i++) {
            cout << result[i] << (i + 1 == n ? '\n' : ' ');
        }
    }
    return 0;
}
