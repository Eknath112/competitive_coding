#include<bits/stdc++.h>

using namespace std;

class DSU{
    vector<int>parent,rank;
public:
    DSU(int n){
        parent.resize(n+1);
        rank.resize(n+1,0);
        for(int i=0;i<=n;i++)parent[i]=i;
    }

    int findParent(int node) {
        if(parent[node]==node) return node;
        return parent[node]=findParent(parent[node]);
    }

    void unionByRank(int u,int v) {
        int pu=findParent(u);
        int pv=findParent(v);
        if(pu==pv) return;
        if(rank[pu]<rank[pv]) parent[pu]=pv;
        else if(rank[pv]<rank[pu]) parent[pv]=pu;
        else {
            parent[pv]=pu;
            rank[pu]++;
        }
    }
};

struct Edge {
    int u,v,w;
    Edge(int _u,int _v,int _w){ u=_u; v=_v; w=_w; }
};

int main() {
    int n=6,m=7; 
    vector<Edge> edges;
    edges.push_back(Edge(1,2,5));
    edges.push_back(Edge(1,3,3));
    edges.push_back(Edge(2,3,4));
    edges.push_back(Edge(2,4,6));
    edges.push_back(Edge(3,4,2));
    edges.push_back(Edge(3,5,7));
    edges.push_back(Edge(4,5,8));

    sort(edges.begin(), edges.end(), [](Edge a, Edge b){
        return a.w < b.w;
    });

    DSU dsu(n);
    int mstWeight=0;
    vector<pair<int,int>> mstEdges;

    for(auto &edge: edges){
        if(dsu.findParent(edge.u)!=dsu.findParent(edge.v)){
            mstWeight += edge.w;
            mstEdges.push_back({edge.u,edge.v});
            dsu.unionByRank(edge.u,edge.v);
        }
    }

    cout<<"MST Weight = "<<mstWeight<<"\n";
    cout<<"Edges in MST:\n";
    for(auto &e: mstEdges){
        cout<<e.first<<" - "<<e.second<<"\n";
    }

    return 0;
}
