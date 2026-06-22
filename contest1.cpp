#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        ll n, a, b;
        cin >> n >> a >> b;

        ll r1 = n * a;

        ll g = n / 3;
        ll r = n % 3;
        
        ll r2 = g * b;
        if (r == 1) {
            r2 += min(a, b);
        } else if (r == 2) {
            r2 += min(2 * a, b);
        }

        cout << min(r1, r2) << "\n";
    }
    return 0;
}