//��Ŀ�� �ж϶����� a ÿ��Ԫ���������һ�Σ�b [j]-a [i]�����ܷ�ɷǵݼ����С�
/*
	�ҵ�˼·��
		��������a��b��ÿ�ζ���a����С��ֻҪ����ai<=ai+1���ɣ�ֱ����i=m��
		���������ˣ����ai��ֵ����С��ǰһ��ai-1����ֱ�ӷ���NO���� 


����1���ȴ�С����
		������ÿһ������Ҫ��ǰһ����ȥ�ȴ�С��Ҳ���ǲ���a[i]��Ȼ��ȥ��a[i-1]�ȴ�С
		��д�ɺͺ�һ���ȴ�С�ˣ����ǲ��е� 
	  2��û������Ͷ��֣�
		��ȷ�ⷨ��Ҫ�� b ������ö��ֲ��ҿ����ҵ��Ϸ�����Сֵ��
	 

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
