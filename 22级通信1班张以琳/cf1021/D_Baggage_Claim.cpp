#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve() {
    const i64 p = 1e9 + 7;
    int n, m, k;
    cin >> n >> m >> k;
    ++k;
    vector<vector<int>> e(n * m + 7);
    vector<int> a(k + 7), b(k + 7);
    vector<bool> is(n * m + 7, 0);
    for (int i = 1; i <= k; ++i) cin >> a[i] >> b[i];
    bool no = 0;
    for (int i = 2; i <= k; ++i) {
        int dx = abs(a[i] - a[i - 1]), dy = abs(b[i] - b[i - 1]);
        if (dx + dy != 2) {
            cout << "0\n";
            return;
        }
        int u, v;
        auto idx = [&](int x, int y) -> int {return (x - 1) * m + y;};
        if (dx == 2) u = v = idx((a[i] + a[i - 1]) / 2, b[i]);
        else if (dy == 2) u = v = idx(a[i], (b[i] + b[i - 1]) / 2);
        else u = idx(a[i], b[i - 1]), v = idx(a[i - 1], b[i]);
        
        if (u != v) e[u].push_back(v), e[v].push_back(u);
        else if (!is[u]) e[u].push_back(v), is[u] = 1;
        else no = 1;
    }

    if (no) {
        cout << "0\n";
        return;
    }

    vector<bool> vis(n * m + 7, 0);
    set<int> pst;
    set<pair<int, int>> est;
    auto dfs = [&](auto& dfs, int x) -> void {
        vis[x] = 1;
        pst.insert(x);
        for (auto u:e[x]) {
            if (est.find({u, x}) == est.end()) est.insert({x, u});
            if (!vis[u]) dfs(dfs, u);
        }
    };

    i64 ans = 1;
    for (int i = 1; i <= n * m; ++i) {
        if (!e[i].size() || vis[i]) continue;
        pst.clear(); est.clear();
        dfs(dfs, i);
        int sum = pst.size(), cnt = est.size();
        if (sum < cnt) {
            cout << "0\n";
            return;
        }
        if (sum == cnt) {
            bool ok = 0;
            for (int x:pst) if (is[x]) {
                ok = 1;
                break;
            }
            if (!ok) ans = ans * 2 % p;
        }
        else ans = ans * sum % p;
    }
    cout << ans << '\n';
}

#define IOS ios::sync_with_stdio(false), cin.tie(0);
#define tests int t = 1; cin >> t; while (t--) solve();
#define test solve();

int main() {
    IOS;
    tests;
}
