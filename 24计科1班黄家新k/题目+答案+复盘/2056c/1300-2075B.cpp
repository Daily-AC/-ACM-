#include <bits/stdc++.h>
#define int long long
using namespace std;

int t, n, k, a[5010], ans = 0;

signed main()
{
	cin >> t;
	while (t--)
	{
		ans = 0;
		cin >> n >> k;
		for (int i = 1 ; i <= n ; i++)
		{
			cin >> a[i];
		}
		if (k != 1)
		{
			sort(a + 1, a + n + 1);
			for (int i = n ; i >= n - k ; i--)
			{
				ans += a[i];
			}
			cout << ans << endl;
		}
		else
		{
			int maxx = 0;
			for (int i = 2 ; i <= n - 1 ; i++)
			{
				maxx = max(maxx, a[i]);
			}
			cout << max(maxx + max(a[1], a[n]), a[1] + a[n]) << endl;
		} 
	}
	return 0;
} 
