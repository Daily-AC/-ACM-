#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve() {
    string s;
    cin >> s;
    int cnt[10] = {0};
    for (auto c:s) cnt[c - '0']++;
    for (int i = 1; i <= 10; ++i) {
        for (int j = 10 - i; j <= 9; ++j) {
            if (cnt[j]) {
                --cnt[j];
                cout << j;
                break;
            }
        }
    }
    cout << '\n';
}

#define tests int t = 1; cin >> t; while (t--) solve();
#define test solve();
int main() {
    ios::sync_with_stdio(false), cin.tie(0);
    tests;
}