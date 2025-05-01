#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve() {
    int n, k;
    cin >> n >> k;
    int cnt = 0;
    auto check = [&](int len) -> bool {
        int llen = len % k, idx = len / k * k + 1;
        if (!llen) llen = k, idx -= k;
        for (int i = 1; i <= llen; ++i) {
            cout << "? " << i << endl; ++cnt;
            int x, xx;
            cin >> x;
            cout << "? " << idx + i - 1  << endl; ++cnt;
            cin >> xx;
            if (x != xx) return 0;
        }
        return 1;
    };
    int l = k, r = n - k, mid;
    while (l < r) {
        mid = l + r + 1 >> 1;
        if (check(mid)) l = mid;
        else r = mid - 1;
    }
    int num = 0;
    for (int i = max(l - k, k); i >= k && i <= r && cnt < 230; ++i) if (check(i)) ++num;
    if (num > 1) cout << "! -1" << endl;
    else cout << "! " << l << ' ' << n - l << endl;
}

#define IOS ios::sync_with_stdio(false), cin.tie(0);
#define tests int t = 1; cin >> t; while (t--) solve();
#define test solve();

int main() {
    IOS;
    tests;
}