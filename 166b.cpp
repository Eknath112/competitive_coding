#include <bits/stdc++.h>
using namespace std;
struct Point {
    long long x, y;
};
long long cross_product(Point o, Point a, Point b) {
    return (a.x - o.x) * (b.y - o.y) - (a.y - o.y) * (b.x - o.x);
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    if(cin >> n) {
        vector<Point> A(n);
        for(int i=0; i<n; i++) cin >> A[i].x >> A[i].y;
        reverse(A.begin(), A.end());
        int m; cin >> m;
        bool ok = true;
        for(int i=0; i<m; i++) {
            Point p; cin >> p.x >> p.y;
            if(cross_product(A[0], A[1], p) >= 0 || cross_product(A[0], A[n-1], p) <= 0) {
                ok = false;
                continue;
            }
            int l = 1, r = n - 1;
            while(r - l > 1) {
                int mid = (l + r) / 2;
                if(cross_product(A[0], A[mid], p) < 0) {
                    l = mid;
                } else {
                    r = mid;
                }
            }
            if(cross_product(A[l], A[l+1], p) >= 0) {
                ok = false;
            }
        }
        cout << (ok ? "YES" : "NO") << "\n";
    }
    return 0;
}
