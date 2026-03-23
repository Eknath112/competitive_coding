#include <bits/stdc++.h>
using namespace std;

class DSU {
    vector<int> parent, size;

public:
    DSU(int n) {
        parent.resize(n + 1);
        size.resize(n + 1, 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i; 
        }
    }

    int findParent(int node) {
        if (parent[node] == node) return node;
        return parent[node] = findParent(parent[node]);
    }

    void unionBySize(int u, int v) {
        int pu = findParent(u);
        int pv = findParent(v);

        if (pu == pv) return; 

        if (size[pu] < size[pv]) {
            parent[pu] = pv;
            size[pv] += size[pu];
        } else {
            parent[pv] = pu;
            size[pu] += size[pv];
        }
    }
};

int main() {
    DSU dsu(7);

    dsu.unionBySize(1, 2);
    dsu.unionBySize(2, 3);
    dsu.unionBySize(4, 5);
    dsu.unionBySize(6, 7);
    dsu.unionBySize(5, 6);

    if (dsu.findParent(3) == dsu.findParent(7))
        cout << "Same component\n";
    else
        cout << "Different components\n";

    return 0;
}

