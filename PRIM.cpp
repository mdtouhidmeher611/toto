#include <iostream>
#include <climits>
using namespace std;

int main() {
    int n;
    cin >> n;

    int g[100][100];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> g[i][j];

    bool vis[100] = {false};

    vis[0] = true;

    int edges = 0;
    int cost = 0;

    cout << "Edges in MST:\n";

    while (edges < n - 1) {
        int mn = INT_MAX;
        int u = -1, v = -1;

        for (int i = 0; i < n; i++) {
            if (vis[i]) {
                for (int j = 0; j < n; j++) {
                    if (!vis[j] && g[i][j] != 0 &&
                        g[i][j] < mn) {
                        mn = g[i][j];
                        u = i;
                        v = j;
                    }
                }
            }
        }

        vis[v] = true;
        cost += mn;
        edges++;

        cout << u << " - " << v
             << " : " << mn << endl;
    }

    cout << "Total Cost = " << cost << endl;

    return 0;
}