#include <iostream>
#include <algorithm>
using namespace std;

struct Edge {
    int u, v, w;
};

bool cmp(Edge a, Edge b) {
    return a.w < b.w;
}

int p[100];

int find(int x) {
    if (p[x] == x)
        return x;

    return p[x] = find(p[x]);
}

void unite(int a, int b) {
    a = find(a);
    b = find(b);

    if (a != b)
        p[a] = b;
}

int main() {
    int n, m;
    cin >> n >> m;

    Edge e[1000];

    for (int i = 0; i < m; i++)
        cin >> e[i].u >> e[i].v >> e[i].w;

    sort(e, e + m, cmp);

    for (int i = 0; i < n; i++)
        p[i] = i;

    int cost = 0;

    cout << "Edges in MST:\n";

    for (int i = 0; i < m; i++) {
        int u = e[i].u;
        int v = e[i].v;
        int w = e[i].w;

        if (find(u) != find(v)) {
            unite(u, v);

            cost += w;

            cout << u << " - "
                 << v << " : "
                 << w << endl;
        }
    }

    cout << "Total Cost = "
         << cost << endl;

    return 0;
}