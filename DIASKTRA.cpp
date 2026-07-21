#include <iostream>
#include <climits>
using namespace std;

int mnDist(int d[], bool vis[], int n) {
    int mn = INT_MAX;
    int idx = -1;

    for (int i = 0; i < n; i++) {
        if (!vis[i] && d[i] < mn) {
            mn = d[i];
            idx = i;
        }
    }

    return idx;
}

void dijkstra(int g[100][100], int n, int src) {
    int d[100];
    bool vis[100];

    for (int i = 0; i < n; i++) {
        d[i] = INT_MAX;
        vis[i] = false;
    }

    d[src] = 0;

    for (int i = 0; i < n - 1; i++) {
        int u = mnDist(d, vis, n);

        if (u == -1)
            break;

        vis[u] = true;

        for (int v = 0; v < n; v++) {
            if (!vis[v] &&
                g[u][v] != 0 &&
                d[u] != INT_MAX &&
                d[u] + g[u][v] < d[v]) {

                d[v] = d[u] + g[u][v];
            }
        }
    }

    cout << "\nShortest distances from vertex "
         << src << ":\n";

    for (int i = 0; i < n; i++) {
        cout << src << " -> " << i
             << " = " << d[i] << endl;
    }
}

int main() {
    int n;
    cin >> n;

    int g[100][100];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> g[i][j];
        }
    }

    int src;
    cin >> src;

    dijkstra(g, n, src);

    return 0;
}