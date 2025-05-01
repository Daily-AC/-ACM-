#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve() {
    i64 n, x;
    cin >> n >> x;
    auto r = [](int n) -> i64 {
        if (n % 2) {
            if (n == 1) return -1;
            else return n + 3;
        }
        return n;
    };
    if (!x) {
        cout << r(n) << '\n';
        return;
    }
    if (n == 1) {
        cout << x << '\n';
        return;
    }
    auto f = [&](int xx) -> i64 {
        i64 ans = 0;
        while (xx) {
            ans += xx % 2;
            xx /= 2;
        }
        return ans;
    };

    if (f(x) >= n) cout << x << '\n';
    else {
        int cnt = n - f(x);
        if (cnt % 2 == 0) cout << cnt + x << '\n';
        else if (cnt == n - 1) {
            if (x % 2 == 0) cout << x + cnt + 1 << '\n';
            else cout << x + cnt + 3 << '\n';
        }
        else cout << x + cnt + 1 << '\n';
    }
}

#define IOS ios::sync_with_stdio(false), cin.tie(0);
#define tests int t = 1; cin >> t; while (t--) solve();
#define test solve();

int main() {
    IOS;
    tests;
}