#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 7), b(n + 7), h(n + 7, 0);
    for (int i = 1; i <= n; ++i) cin >> a[i], h[a[i]] = i;
    for (int i = 1; i <= n; ++i) cin >> b[i];
    vector<vector<int>> g;
    vector<int> p;
    vector<bool> vis(n + 7, 0);
    auto dfs = [&](auto& dfs, int idx) -> void {
        p.push_back(idx);
        vis[idx] = 1;
        if (!vis[h[idx]]) dfs(dfs, h[idx]);
    };
    for (int i = 1; i <= n; ++i) {
        if (vis[i]) continue;
        p.clear();
        dfs(dfs, i);
        g.push_back(p);
    }
    vector<int> f(n + 7, 0);
    for (int i = 0; i < g.size(); ++i) for (auto x:g[i]) f[x] = i;
    unordered_set<int> st;
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        if (st.find(f[b[i]]) == st.end()) st.insert(f[b[i]]), ans += g[f[b[i]]].size();
        cout << ans << " \n"[i == n];
    }
}

#define IOS ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#define tests int t = 1; cin >> t; while (t--) solve();
#define test solve();

int main() {
    IOS;
    tests;
}