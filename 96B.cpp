#include <iostream>

using namespace std;
typedef long long ll;

ll n, ans = 1e11;

void f(ll x, int a, int b) {
    if (x > 1e10) return;
    
    if (a == b && x >= n) {
        if (x < ans) ans = x;
    }

    f(x * 10 + 4, a + 1, b);
    f(x * 10 + 7, a, b + 1);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    f(0, 0, 0);

    cout << ans << endl;

    return 0;
}