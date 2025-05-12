/*
	我的思路：
		要以最小能量到达L，最重要的就是L要大于最大障碍，所以每次在障碍前收集jump，直到大于最大障碍
		 用的是二维数组 


	题解思路： 
		要用优先队列，和栈
		 
		 
	代码优点：1，结构体表示同一对象的两个数据 
		      2，离散化，（排序+去重），目的是构建出数轴数组bok 
			  比如 1 2 2 4 5 7 1 2 7  -> 1 2 4 5 7 ? ? ? ?  把所有点都聚焦在一起 
			  3，离散化的映射，很离谱 
			  	比如说，一个数组排序后：4 5 9 15 26 77 5958 
				很不均匀，通过映射，直接变为：1 2 3 4 5 6 7 
				映射是针对两个数组而言的，是一种关系，所以下面是把t和o做了映射，映射在bok上 
				建议直接背代码 
			  
			  3，优先队列 
			  4，每次都能访问下一个元素，设一个nowo为0，数组从1开始，下一个元素就是nowo+1 
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
using namespace std;
int T,n,m,L,cnt;
struct obs//obstacle 障碍物 
{
	int l,r,len;
}o[N];

struct tols//tools 增强道具 
{
	int x,v;
}t[N];
int bok[N],bl[N];//离散化数组 
priority_queue<int>q;//默认大根堆 
int re()//防止作弊不放快读快写
void wr(int x)
signed main()
{
	T=re();
	while(T--)
	{
		n=re(),m=re(),L=re();
		cnt=0;
		for(int i=1;i<=n;i++)
		{
			o[i].l=re(),o[i].r=re();
			o[i].len=o[i].r-o[i].l+1;
			bok[++cnt]=o[i].l;//离散化左端点 
		}
		for(int i=1;i<=m;i++)
		{
			t[i].x=re(),t[i].v=re();
			bok[++cnt]=t[i].x;//离散化道具位置 
		}
		sort(bok+1,bok+cnt+1);
		int boks=unique(bok+1,bok+cnt+1)-bok-1;  //去重 ，bok没有离散化映射，但是o和t有 
		for(int i=1;i<=n;i++)							//其实t和o的映射是在bok的基础上的 
			o[i].l=lower_bound(bok+1,bok+boks+1,o[i].l)-bok;
		for(int i=1;i<=m;i++)
			t[i].x=lower_bound(bok+1,bok+boks+1,t[i].x)-bok;//朴素的离散化 
		int nowo=0,nowt=0,ans=0,nowv=1,flag=0;
		//当前第几个障碍物，第几个道具，当前答案（捡的道具个数），当前跳跃能力，是否中途因跳跃能力不够而直接输出 -1 
		for(int i=1;i<=boks;i++)//遍历离散化后的位置 ，bok离散化了但是没映射	 
		{
			while(i==t[nowt+1].x && nowt<m)//下个位置有道具 
			{
				nowt++;
				q.push(t[nowt].v);//存入优先队列 
			}
			if(i==o[nowo+1].l&&nowo<n)//下个位置有障碍 
			{
				nowo++;
				int bas=o[nowo].len;
				while(q.size()!=0&&nowv<=bas)//拿道具 
				{
					nowv+=q.top();
					q.pop(),ans++;
				}
				if(!q.size()&&nowv<=bas)//道具拿满也不够跳过障碍 
				{
					puts("-1");
					flag=1;
					break;
				}
			}
		}
		while(q.size())
			q.pop();//多测清空 
		if(!flag)
			wr(ans),putchar('\n');
	}
	return 0;
}



//#include <bits/stdc++.h>
//#define ll long long
//using namespace std;
//int main()
//{
//	int t;
//	cin>>t;
//	while(t--){
//		int n,m;
//		ll L;
//		cin>>n>>m>>L;
//		vector< ll > hurdle(L+1);
//		vector< vector<ll> > improve(L+1);
//		ll maxhurdlelength=0;
//		ll x=0;
//		ll x1=0;
//		for(int i=1;i<=n;i++){ //数组全部初始化L的数轴，每次都是找到对应位置放入 
//			cin>>x;
//			hurdle[x]=1;
//			cin>>x1;
//			hurdle[x1]=1;
//			maxhurdlelength=max(maxhurdlelength,x1-x+1);
//			hurdle[x]=x1-x+1; //遇见障碍的起点，直接判断其内部存的长度 
//			
//		}
//		for(int i=1;i<=m;i++){
//			cin>>x;
//			cin>>x1;
//			improve[x].push_back(x1);
//		}
//		ll jump=1;
//		ll load=1;
//		ll ans=0;
//		while(1){
//			//退出条件：当前位置大于L或者大于最大障碍
//			if(load>L){
//				cout<<-1<<endl;
//				break;
//			} 
//			
//			
//			//如果jump没到最大障碍，就一直拿 
//			if(jump<=maxhurdlelength){
//				for(int i=0;i<improve[load].size();i++){  //最大的难点就是每次判断是否需要继续拿
//															//因为要求的是最小值，不能拿多 
//					if(jump<=maxhurdlelength){
//						jump+=improve[load][i];//不不不，最大的难点是，当前如果很小也不用取 
//						if(improve[load][i]>0)	{	//就是说，如果之后有够大的数让你通过障碍
//													//且当前jump够过障碍，那就不用取现在这个小的 
//													//我去，好难实现啊 
//						 ans++;
//						 cout<<"ans=="<<ans<<" load=="<<load<<endl;
//						}	
//					}
//				}
//			}
//			
//			if(jump>maxhurdlelength){
//				cout<<ans<<endl;
//				break;
//			}
//			
//								//如果遇到了hurdle ↓ 
//			if(hurdle[load+1]>=1 ){  
//					if(jump>hurdle[load]){
//						load+=hurdle[load]+1;
//					}
//					else{
//						cout<<-1<<endl;
//						break;
//					}
//				
//			}
//			else load+=1; //没走到障碍，只走一步
//			
//		}
//		jump=1;
//		ans=0;
//		
//		
//	}
//	
//	return 0;
//} 
