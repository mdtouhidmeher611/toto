#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<bool> f(n + 2, false);

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;

        if (x >= 0 && x <= n)
            f[x] = true;
    }

    int mex = 0;
    while (f[mex])
        mex++;

    cout << "MEX = " << mex << endl;

    return 0;
}