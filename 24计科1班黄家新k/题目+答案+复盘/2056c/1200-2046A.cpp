//��Ŀ����һ������n�е����У�Ҫ��ӵ�һ�е�1�����ڶ��е�n����ֻ��������һ�Σ�ÿ�����Ӷ����Լ���ֵ�����·��������
//˼·�� �ھ��������ֻ��������һ�Σ���Ϊֻ�����У���

//�������ǿ��Ա������飬ÿһ�ж���Ϊ�����ߵ��У�ȡ�����ֵ��

//ͬʱ�����ǿ��������ƽ����У����Գ��˱���Ϊ�����ߵ�������ֵ��ȡ�⣬����ȡ���ߵ���Сֵ��

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
