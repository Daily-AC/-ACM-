#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int n, k, x;
    cin >> n >> k >> x;
    vector<int> a(n + 7, 0);
    for (int i = 1; i <= n; ++i) cin >> a[i], a[i] += a[i - 1];
    if (x > a[n] * k) {
        cout << "0\n";
        return;
    }
    if (x % a[n] == 0) {
        cout << (k - x / a[n]) * n + 1 << '\n';
        return;
    }
    for (int i = n; i >= 1; --i) if (a[n] - a[i - 1] >= x % a[n]) {
        cout << (k - x / a[n] - 1) * n + i << '\n';
        return;
    }
}

#define IOS ios::sync_with_stdio(false), cin.tie(0);
#define tests int t = 1; cin >> t; while (t--) solve();
#define test solve();

signed main() {
    IOS;
    tests;
}