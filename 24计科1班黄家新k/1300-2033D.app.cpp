/*
	�ҵ�˼·��
	  		Ҳ�������ʼ��˼·����һ��������ջ�Ķ�����Ȼ����������������������ȥԭǰ׺��������qian[l]-qina[i-1]=0�ĵط�
			  ������Ϊ̫�鷳�Ͳ���Ϥ����û��ȥʵ�� ������ֱ�ӱ����ˣ����ôһֱ�� 
			  
	
*/ 
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<set>
#include<queue>
#include<vector>
#define N 400005//ע����ɢ�����鷶Χ 
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
			sum+=a[i];//�����ǰ׺�� 
			if(s.count(sum)){
				sum = 0,ans ++,s.clear(),s.insert(0);//�ҵ���һ���ӶΣ�ǰ׺�͡�set ����� 
			}
			else{
				s.insert(sum);
			}
			
				
		}

		cout<<ans<<endl;	
	} 
	return 0;
}

