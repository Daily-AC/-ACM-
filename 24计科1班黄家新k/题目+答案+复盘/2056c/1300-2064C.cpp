
//题目：每次选数组元素的绝对值，加入ans，正数删左，负数删右，求ans的最大值。 
/*
我的思路：
	我是想着三种暴力，然后最后取最大值，
	第一个：选左边正数和右边负数，双指针取
	第二个，全取负数，从右往左，就能拿到所有负数
	第三个，全取正数，从左往右 
很接近正确题解了，也是发现了这个 “前面取正数，后面取负数的逻辑 ”
但是还是没有找到最终的大门 

最终的大门是：
 		枚举所有分割点i，i的左边必须取正数，右边必须取负数。 
		 这样就能找到所有可能，把我的暴力二和三都囊括进去了 

*/
#include <iostream>
#include<vector>
#include<algorithm>
#include<numeric>
#include<string>
#include<unordered_map>
#include<map>
#define ll long long
#include<cmath>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--){
    	ll n;
    	cin>>n;
    	vector<ll> a(n+1);
    	for(int i=1;i<=n;i++){
    		cin>>a[i];
    	}
		//找前缀和和后缀和
		vector<ll> qian(n+1);
		 vector<ll> hou(n+1);
		for(int i=1;i<=n;i++){
			if(a[i]>0){
				qian[i]=qian[i-1]+a[i];
				hou[i]=hou[i-1];   //后缀和，在这个时候不变，继续继承上一个 
			}
			else{
				hou[i]=hou[i-1]+abs(a[i]);
				qian[i]=qian[i-1];
			}
		}
		ll ans=0;
		for(int i=1;i<=n;i++){
			ans=max(ans,qian[i]+hou[n]-hou[i-1]);
		}
		cout<<ans<<endl;
    	
    	
	}

    return 0;
}





