/*
	�ҵ�˼·��
		���ȣ�����˼·�ǣ�ÿ������+1��������ÿ����ӡ�����ڲ���ʱ��+1��Ȼ��һ����Щ�ڲ�
		��ʱ���ﵽ��t����ôans++��nowl++��nowt����
		һ��nowl����l���������ȴ 
		˵���˾���ÿ��print����������ʱ�䣬����t�͹��㣬û����ͼ�������ʵʵ++ 

		д������Сʱ��ʱ��.......
		��������ǩ���ⶼд���������Ѷȸо���1200-1300����
		��ô���ף� 

	���˼·�� 
		Ҫ�ö��ֲ��ң���Ϊÿ���룬��ӡ�������ǿ�����ģ�����ֱ�Ӷ������Ĵ𰸼��� 
		 
		 
		 
	���̣�
	   ������������ʱ�临�Ӷȣ���ͳ������ˣ�̫���ˣ�û�кú�˼��
	   Ȼ��ص���ȷ˼·�ϣ���Ŀ����ʾ���ˣ�ʱ����t*l+m��˵���϶�Ҫ�õ� ����������
	   ˵����Ŀ��Ҫ����ֱ�Ӽ���� 
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
#define ll long long
using namespace std;
struct node{
	ll t,l,m;
}a[101];

ll calc(node a,ll s){
	ll print=a.t*a.l;//��ӡ����ʱ�� 
	ll all=print+a.m;//һ���������� 
	ll circle=s/all; //�м������� 
	ll ans = circle*a.l;
	ll shen = s%all;//��ʣ�¶��ʱ�� 
	if(shen>=print){ //���ʣ������ʱ�� 
		ans+=a.l;
	}
	else{//���ʱ�䲻�����Ǿ�����ʵʵһ��һ����ӡ 
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

