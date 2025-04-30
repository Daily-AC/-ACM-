#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

const int N = 1e5 + 7;
int a[N];

void solve() {
    int n;
    cin >> n;
    map<int, int> mp;
    set<int> st;
    for (int i = 1; i <= n; ++i) cin >> a[i], mp[a[i]]++, st.insert(a[i]);
    int pr = -1;
    for (auto x:st) {
        if (mp[x] >= 4) {
            cout << "Yes\n";
            return;
        }
        if (mp[x] >= 2) {
            if (pr == -1) pr = x;
            else if (x == pr + 1) {
                cout << "Yes\n";
                return;
            }
            else pr = x;
        }
        else if (x == pr + 1) pr = x;
        else pr = -1;
    }
    cout << "No\n";
}

#define IOS ios::sync_with_stdio(false), cin.tie(0);
#define tests int t = 1; cin >> t; while (t--) solve();
#define test solve();

int main() {
    IOS;
    tests;
}
