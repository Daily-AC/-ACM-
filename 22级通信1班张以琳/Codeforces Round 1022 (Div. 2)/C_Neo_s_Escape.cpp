#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve() {
    int n, x, pr = -1;
    cin >> n;
    vector<int> v;
    v.push_back(0);
    for (int i = 1; i <= n; ++i) {
        cin >> x;
        if (pr != x) v.push_back(x);
        pr = x;
    }
    v.push_back(0);
    int ans = 0;
    for (int i = 1; i < v.size() - 1; ++i) if (v[i] > v[i - 1] && v[i] > v[i + 1]) ++ans;
    cout << ans << '\n';

}

#define IOS ios::sync_with_stdio(false), cin.tie(0);
#define tests int t = 1; cin >> t; while (t--) solve();
#define test solve();

int main() {
    IOS;
    tests;
}