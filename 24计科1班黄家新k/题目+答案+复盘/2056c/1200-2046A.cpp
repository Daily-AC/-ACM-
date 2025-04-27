//题目：给一个两行n列的排列，要求从第一行的1，到第二行的n，且只能往下走一次，每个格子都有自己的值，输出路径的最大和
//思路： 在矩阵里，我们只能向下走一次（因为只有两行）。

//所以我们可以遍历数组，每一列都设为向下走的列，取答案最大值。

//同时，我们可以无限制交换列，所以除了被设为向下走的列两个值都取外，都可取二者的最小值。

#include <bits/stdc++.h>
using namespace std;
#define ll long long
signed main()
{
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
    int t;cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        vector<ll> a(n + 1);
        vector<ll> b(n + 1);
        for (int i = 1;i <= n;i++) cin >> a[i];
        for (int i = 1;i <= n;i++) cin >> b[i];
        if(n==1){
        	cout<<a[1]+b[1]<<endl;
        	continue;
		} 
        ll maxsum = INT_MIN;
        ll ans = 0;
    	for(int i=1;i<=n;i++){
    		for(int j=1;j<=n;j++){
    		  if(j==i)	continue;
			  ans+=max(a[j],b[j]);
			}
			ans+=a[i];
			ans+=b[i];
			maxsum=max(ans,maxsum);
			ans=0;
		}	

       	cout << maxsum << endl;
		
    }

    return 0;
}
