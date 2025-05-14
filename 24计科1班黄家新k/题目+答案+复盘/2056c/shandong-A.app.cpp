/*
	我的思路：
		首先，核心思路是，每次秒数+1，都换成每个打印机的内部计时器+1，然后一旦这些内部
		计时器达到了t，那么ans++，nowl++，nowt归零
		一旦nowl到达l，则进入冷却 
		说白了就是每个print独立计算其时间，到达t就归零，没到达就继续老老实实++ 

		写了两个小时超时了.......
		看来我连签到题都写不出来，难度感觉是1200-1300左右
		这么离谱？ 

	题解思路： 
		要用二分查找，因为每个秒，打印的数量是可以算的，所以直接二分最后的答案即可 
		 
		 
		 
	复盘：
	   这里首先推理时间复杂度，你就出问题了，太急了，没有好好思考
	   然后回到正确思路上，题目都暗示你了，时间是t*l+m，说明肯定要用到 ，继续推理
	   说明题目是要我们直接计算的 
*/ 
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<map>
#include<queue>
#include<vector>
#define N 400005//注意离散化数组范围 
#define ll long long
using namespace std;
struct node{
	ll t,l,m;
}a[101];

ll calc(node a,ll s){
	ll print=a.t*a.l;//打印所需时间 
	ll all=print+a.m;//一个完整周期 
	ll circle=s/all; //有几个周期 
	ll ans = circle*a.l;
	ll shen = s%all;//还剩下多久时间 
	if(shen>=print){ //如果剩下完整时间 
		ans+=a.l;
	}
	else{//如果时间不够，那就老老实实一个一个打印 
		ans+=shen/a.t;
	}
	return ans;
}

bool check(node a[],ll s,ll k,ll n){
	ll ans=0;
	for(int i=1;i<=n;i++){
		ans+=calc(a[i],s);
		if(ans>=k)	return true;
		
	}
	
	return false;
}


int main()
{
	ll t;
	cin>>t;
	while(t--){
		ll n,k;
		cin>>n>>k;
		for(int i=1;i<=n;i++){
			cin>>a[i].t>>a[i].l>>a[i].m;
		}
		
	ll l=1,r=2e18;
		while(l<r){
			ll mid=(l+r)/2;
			if(check(a,mid,k,n)  ){
				r=mid;
			}
			else{
				l=mid+1;
			}
		}
		cout<<l<<endl;
	}
	return 0;
}

