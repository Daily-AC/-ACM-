/*
	我的思路：
	  		也就是我最开始的思路：搞一个类似于栈的东西，然后往里塞东西，加起来，去原前缀和里面找qian[l]-qina[i-1]=0的地方
			  但是因为太麻烦和不熟悉，就没有去实现 ，反而直接暴力了，结果么一直错 
			  
	
*/ 
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<set>
#include<queue>
#include<vector>
#define N 400005//注意离散化数组范围 
#define ll long long
using namespace std;

int main()
{
	ll t;
	cin>>t;
	while(t--){
		ll n;
		cin>>n;
		vector<ll> a(n+1);
		set<ll> s;
		s.clear();
		s.insert(0);
		ll sum=0;
		ll ans=0;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			sum+=a[i];//这就是前缀和 
			if(s.count(sum)){
				sum = 0,ans ++,s.clear(),s.insert(0);//找到了一个子段，前缀和、set 均清空 
			}
			else{
				s.insert(sum);
			}
			
				
		}

		cout<<ans<<endl;	
	} 
	return 0;
}

