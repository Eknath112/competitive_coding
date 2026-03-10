#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k;
    if (!(cin >> n >> k)) return 0;
    vector<long long> b(n);
    for (int i = 0; i < n; i++) cin >> b[i];
    vector<long long> add(n + 1, 0);
    long long ans = 0;
    long long cur_sum = 0, cur_cnt = 0;
    for (int i = n - 1; i >= 0; i--) {
        cur_sum -= cur_cnt;
        cur_cnt -= add[i + 1];
        long long val = b[i] - cur_sum;
        if (val > 0) {
            long long len = min((long long)i + 1, (long long)k);
            long long times = (val + len - 1) / len;
            ans += times;
            cur_sum += times * len;
            cur_cnt += times;
            if (i - len + 1 >= 0) {
                add[i - len + 1] += times;
            }
        }
    }
    cout << ans << "\n";
    return 0;
}
