#include <bits/stdc++.h>
using namespace std;

class DSU{
    vector<int>parent, rank;

    public:
        DSU(int n){
            parent.resize(n+1);
            rank.resize(n+1,0);
            for(int i=0;i<=n;i++){
                parent[i]=i;
            }
        }

        int findParent(int node){
            if(parent[node]==node)return node;
            return parent[node]=findParent(parent[node]);
        }

        void unionByRank(int u, int v){
            int pu=findParent(u);
            int pv=findParent(v);

            if(pu==pv)return;
            if(rank[pu]<rank[pv])
                parent[pu]=pv;
            else if(rank[pv]<rank[pu])
                parent[pv]=parent[pu];
            else{
                parent[pv]=pu;
                rank[pu]++;
            }
        }
};

int main() {
    DSU dsu(7);

    dsu.unionByRank(1, 2);
    dsu.unionByRank(2, 3);
    dsu.unionByRank(4, 5);
    dsu.unionByRank(6, 7);
    dsu.unionByRank(5, 6);

    if (dsu.findParent(3) == dsu.findParent(7))
        cout << "Same component\n";
    else
        cout << "Different components\n";

    return 0;
}
