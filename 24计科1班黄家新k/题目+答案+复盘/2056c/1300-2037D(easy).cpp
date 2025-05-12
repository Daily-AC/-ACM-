/*
 * @FilePath: \c++\CF2037D.cpp
 * @Author: WRT_Partisan
 * @Date: 2024-11-23 20:52:44
 */
#include <bits/stdc++.h>
using namespace std;
#define ll long long
typedef unsigned long long ull;
struct node{
	int l,r;
	
}a[1000000],b[1000000];

priority_queue<ll> q;

int main(){
	ll t;
	cin>>t;
	while(t--){
		while(!q.empty())
		{
			q.pop();
		}
		ll n,m,L;
		cin>>n>>m>>L;
		for(int i=1;i<=n;i++){
			cin>>a[i].l;
			cin>>a[i].r;
		}
		for(int i=1;i<=m;i++){
			cin>>b[i].l;
			cin>>b[i].r;
		}
		ll ans=0;
		ll nowb=1;
		ll jump=1;
		bool check=0;
		for(int i=1;i<=n;i++){
			
			while( nowb <= m && b[nowb].l < a[i].l ){ //把障碍前的所有道具全部收集起来 
				q.push(b[nowb].r);	  //放入道具的逻辑是，如果当前道具的坐标小于障碍坐标，就可以放入 
				nowb++;
				//cout<<"q.top=="<<q.top()<<"  ";
			}
			while(jump<=a[i].r-a[i].l+1){  //这里是到达障碍前，不断选择道具 ,当能过障碍了，就直接退出 
				if(q.empty() && jump<=a[i].r-a[i].l+1){ //如果道具选完了还不能过障碍 
					check=1;
					break;
				}
				else if(jump<=a[i].r-a[i].l+1){
					jump+=q.top();
					q.pop();
					ans++;
				}
//				cout<<"ans=="<<ans<<endl;
//				cout<<"jump="<<jump<<endl;
			}
			if(check==1){
				break;
			}
			
			
		}
		
		if(check==1){
			cout<<-1<<endl;
		}
		else{
			cout<<ans<<endl;
		}
		
		
	}
	return 0;
}
