#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

const int N = 1e5 + 7;
int a[N];

void solve() {
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    sort(a + 1, a + n + 1);
    if (!k) {
        if (n % 2) cout << "1\n";
        else cout << a[n / 2 + 1] - a[n / 2] + 1 << '\n';
        return;
    }
    if (n % 2) {
        if (k % 2 == 0) --k;
        cout << a[(n + 1) / 2 + (k + 1) / 2] - a[(n + 1) / 2 - (k + 1) / 2] + 1 << '\n';
        return; 
    }
    if (k % 2) --k;
    cout << a[n / 2 + 1 + k / 2] - a[n / 2 - k / 2] + 1 << '\n';
}

#define IOS ios::sync_with_stdio(false), cin.tie(0);
#define tests int t = 1; cin >> t; while (t--) solve();
#define test solve();

int main() {
    IOS;
    tests;
}