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
			
			while( nowb <= m && b[nowb].l < a[i].l ){ //���ϰ�ǰ�����е���ȫ���ռ����� 
				q.push(b[nowb].r);	  //������ߵ��߼��ǣ������ǰ���ߵ�����С���ϰ����꣬�Ϳ��Է��� 
				nowb++;
				//cout<<"q.top=="<<q.top()<<"  ";
			}
			while(jump<=a[i].r-a[i].l+1){  //�����ǵ����ϰ�ǰ������ѡ����� ,���ܹ��ϰ��ˣ���ֱ���˳� 
				if(q.empty() && jump<=a[i].r-a[i].l+1){ //�������ѡ���˻����ܹ��ϰ� 
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
