#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, k; 
    if(cin >> n >> k) {
        vector<long long> a(n);
        for(int i = 0; i < n; i++) cin >> a[i];
        if (k == 1) {
            cout << 0 << "\n";
            return 0;
        }
        cout << 0 << "\n";
    }
    return 0;
}
