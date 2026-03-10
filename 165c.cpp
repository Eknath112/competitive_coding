#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int k; string s;
    if(cin >> k >> s) {
        map<int, int> count;
        count[0] = 1;
        long long ans = 0;
        int sum = 0;
        for(char c : s) {
            sum += (c - '0');
            if(sum >= k) ans += count[sum - k];
            count[sum]++;
        }
        cout << ans << "\n";
    }
    return 0;
}
