
//��Ŀ��ÿ��ѡ����Ԫ�صľ���ֵ������ans������ɾ�󣬸���ɾ�ң���ans�����ֵ�� 
/*
�ҵ�˼·��
	�����������ֱ�����Ȼ�����ȡ���ֵ��
	��һ����ѡ����������ұ߸�����˫ָ��ȡ
	�ڶ�����ȫȡ�������������󣬾����õ����и���
	��������ȫȡ�������������� 
�ܽӽ���ȷ����ˣ�Ҳ�Ƿ�������� ��ǰ��ȡ����������ȡ�������߼� ��
���ǻ���û���ҵ����յĴ��� 

���յĴ����ǣ�
 		ö�����зָ��i��i����߱���ȡ�������ұ߱���ȡ������ 
		 ���������ҵ����п��ܣ����ҵı�����������������ȥ�� 

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
		//��ǰ׺�ͺͺ�׺��
		vector<ll> qian(n+1);
		 vector<ll> hou(n+1);
		for(int i=1;i<=n;i++){
			if(a[i]>0){
				qian[i]=qian[i-1]+a[i];
				hou[i]=hou[i-1];   //��׺�ͣ������ʱ�򲻱䣬�����̳���һ�� 
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





