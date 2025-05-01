#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve() {
    i64 n;
    cin >> n;
    i64 ans = (n - 1 + (n - 1) % 2) * ((n + 1) / 2) / 2 + 1;
    cout << ans << '\n';
}

#define IOS ios::sync_with_stdio(false), cin.tie(0);
#define tests int t = 1; cin >> t; while (t--) solve();
#define test solve();

int main() {
    IOS;
    tests;
}