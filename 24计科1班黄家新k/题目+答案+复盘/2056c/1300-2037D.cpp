/*
	�ҵ�˼·��
		Ҫ����С��������L������Ҫ�ľ���LҪ��������ϰ�������ÿ�����ϰ�ǰ�ռ�jump��ֱ����������ϰ�
		 �õ��Ƕ�ά���� 


	���˼·�� 
		Ҫ�����ȶ��У���ջ
		 
		 
	�����ŵ㣺1���ṹ���ʾͬһ������������� 
		      2����ɢ����������+ȥ�أ���Ŀ���ǹ�������������bok 
			  ���� 1 2 2 4 5 7 1 2 7  -> 1 2 4 5 7 ? ? ? ?  �����е㶼�۽���һ�� 
			  3����ɢ����ӳ�䣬������ 
			  	����˵��һ�����������4 5 9 15 26 77 5958 
				�ܲ����ȣ�ͨ��ӳ�䣬ֱ�ӱ�Ϊ��1 2 3 4 5 6 7 
				ӳ�����������������Եģ���һ�ֹ�ϵ�����������ǰ�t��o����ӳ�䣬ӳ����bok�� 
				����ֱ�ӱ����� 
			  
			  3�����ȶ��� 
			  4��ÿ�ζ��ܷ�����һ��Ԫ�أ���һ��nowoΪ0�������1��ʼ����һ��Ԫ�ؾ���nowo+1 
*/ 
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<map>
#include<queue>
#include<vector>
#define N 400005//ע����ɢ�����鷶Χ 
using namespace std;
int T,n,m,L,cnt;
struct obs//obstacle �ϰ��� 
{
	int l,r,len;
}o[N];

struct tols//tools ��ǿ���� 
{
	int x,v;
}t[N];
int bok[N],bl[N];//��ɢ������ 
priority_queue<int>q;//Ĭ�ϴ���� 
int re()//��ֹ���ײ��ſ����д
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
			bok[++cnt]=o[i].l;//��ɢ����˵� 
		}
		for(int i=1;i<=m;i++)
		{
			t[i].x=re(),t[i].v=re();
			bok[++cnt]=t[i].x;//��ɢ������λ�� 
		}
		sort(bok+1,bok+cnt+1);
		int boks=unique(bok+1,bok+cnt+1)-bok-1;  //ȥ�� ��bokû����ɢ��ӳ�䣬����o��t�� 
		for(int i=1;i<=n;i++)							//��ʵt��o��ӳ������bok�Ļ����ϵ� 
			o[i].l=lower_bound(bok+1,bok+boks+1,o[i].l)-bok;
		for(int i=1;i<=m;i++)
			t[i].x=lower_bound(bok+1,bok+boks+1,t[i].x)-bok;//���ص���ɢ�� 
		int nowo=0,nowt=0,ans=0,nowv=1,flag=0;
		//��ǰ�ڼ����ϰ���ڼ������ߣ���ǰ�𰸣���ĵ��߸���������ǰ��Ծ�������Ƿ���;����Ծ����������ֱ����� -1 
		for(int i=1;i<=boks;i++)//������ɢ�����λ�� ��bok��ɢ���˵���ûӳ��	 
		{
			while(i==t[nowt+1].x && nowt<m)//�¸�λ���е��� 
			{
				nowt++;
				q.push(t[nowt].v);//�������ȶ��� 
			}
			if(i==o[nowo+1].l&&nowo<n)//�¸�λ�����ϰ� 
			{
				nowo++;
				int bas=o[nowo].len;
				while(q.size()!=0&&nowv<=bas)//�õ��� 
				{
					nowv+=q.top();
					q.pop(),ans++;
				}
				if(!q.size()&&nowv<=bas)//��������Ҳ���������ϰ� 
				{
					puts("-1");
					flag=1;
					break;
				}
			}
		}
		while(q.size())
			q.pop();//������ 
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
//		for(int i=1;i<=n;i++){ //����ȫ����ʼ��L�����ᣬÿ�ζ����ҵ���Ӧλ�÷��� 
//			cin>>x;
//			hurdle[x]=1;
//			cin>>x1;
//			hurdle[x1]=1;
//			maxhurdlelength=max(maxhurdlelength,x1-x+1);
//			hurdle[x]=x1-x+1; //�����ϰ�����㣬ֱ���ж����ڲ���ĳ��� 
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
//			//�˳���������ǰλ�ô���L���ߴ�������ϰ�
//			if(load>L){
//				cout<<-1<<endl;
//				break;
//			} 
//			
//			
//			//���jumpû������ϰ�����һֱ�� 
//			if(jump<=maxhurdlelength){
//				for(int i=0;i<improve[load].size();i++){  //�����ѵ����ÿ���ж��Ƿ���Ҫ������
//															//��ΪҪ�������Сֵ�������ö� 
//					if(jump<=maxhurdlelength){
//						jump+=improve[load][i];//�������������ѵ��ǣ���ǰ�����СҲ����ȡ 
//						if(improve[load][i]>0)	{	//����˵�����֮���й����������ͨ���ϰ�
//													//�ҵ�ǰjump�����ϰ����ǾͲ���ȡ�������С�� 
//													//��ȥ������ʵ�ְ� 
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
//								//���������hurdle �� 
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
//			else load+=1; //û�ߵ��ϰ���ֻ��һ��
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
