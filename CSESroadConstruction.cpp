#include <bits/stdc++.h>
using namespace std;

struct DSU {
    vector<int> parent, size;
    DSU(int n) {
        parent.resize(n+1);
        size.assign(n+1, 1);
        iota(parent.begin(), parent.end(), 0);
    }
    int find(int x) {
        if (parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }
    bool unite(int a, int b, int &components, int &max_size) {
        a = find(a);
        b = find(b);
        if (a == b) return false;
        if (size[a] < size[b]) swap(a, b);
        parent[b] = a;
        size[a] += size[b];
        max_size = max(max_size, size[a]);
        components--;
        return true;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m;
    cin >> n >> m;
    DSU dsu(n);
    int components = n, max_size = 1;
    
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        dsu.unite(a, b, components, max_size);
        cout << components << " " << max_size << "\n";
    }
}
