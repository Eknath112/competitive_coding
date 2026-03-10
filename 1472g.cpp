#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t; 
    if(cin >> t) {
        while(t--) {
            int n; cin >> n;
            vector<int> a(n);
            for(int i=0; i<n; i++) cin >> a[i];
            int cur = 0;
            vector<bool> vis(n, false);
            for(int i=0; i<min(n, 31); i++) {
                int best = -1, mx = -1;
                for(int j=0; j<n; j++) {
                    if(!vis[j]) {
                        if((cur | a[j]) > mx) {
                            mx = cur | a[j];
                            best = j;
                        }
                    }
                }
                if(best != -1) {
                    vis[best] = true;
                    cout << a[best] << " ";
                    cur |= a[best];
                }
            }
            for(int i=0; i<n; i++) {
                if(!vis[i]) cout << a[i] << " ";
            }
            cout << "\n";
        }
    }
    return 0;
}
