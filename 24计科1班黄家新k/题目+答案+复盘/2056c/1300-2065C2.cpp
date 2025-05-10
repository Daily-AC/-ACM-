//题目： 判断对数组 a 每个元素至多操作一次（b [j]-a [i]）后能否成非递减序列。
/*
	我的思路：
		遍历所有a和b，每次都让a尽量小，只要满足ai<=ai+1即可，直到最i=m。
		如果到最后了，这个ai的值还是小于前一个ai-1，那直接返回NO就行 


错误：1，比大小错误：
		代码里每一个数都要和前一个数去比大小，也就是操作a[i]，然后去和a[i-1]比大小
		你写成和后一个比大小了，这是不行的 
	  2，没有排序和二分：
		正确解法需要对 b 排序后用二分查找快速找到合法的最小值。
	 

*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0); 
    int T;
    cin >> T;
    while(T--){
        ll n,m;
        cin>>n>>m;
        
        vector<ll> a(n+1);
        vector<ll> b(m+1);
        a[0]=LLONG_MIN;
        b[0]=-1;
        for(int i=1;i<=n;i++){
        	cin>>a[i];
		}
		for(int i=1;i<=m;i++){
			cin>>b[i];
		}
		sort(b.begin()+1,b.begin()+m+1);
		bool flag=1;
		for(int i=1;i<=n;i++){	
			ll p=upper_bound(b.begin(),b.begin()+m+1,a[i-1]+a[i])-b.begin()+1;
			if(p!=0&&b[p-1]==a[i-1]+a[i]) p--;
			if(b[p]-a[i]>=a[i-1]) a[i]=min(a[i],b[p]-a[i]);
			if(a[i]<a[i-1]) a[i]=max(a[i],b[p]-a[i]);
			if(a[i]<a[i-1]) flag=0;
		}
		cout<<(flag?"YES":"NO")<<endl;
        
    }

    return 0;
}    
