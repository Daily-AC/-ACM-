
//��Ŀ���������뾶Ϊ0��ԲC����һ�����A���յ�B
//		Բ��1���ٶ�����A��1���ٶ�����Bǰ�����ʣ�
//				A�Ƿ����ڲ�����C������µ���B�� 


/*
�ҵ�˼·��
	������ͼ�������ף���ʵ���ǿ�����Բ�ĵ�B�ľ��룬��AB�ĳ��ȣ��ȴ�С
	���Բ�ĵ�B���̣�˵��A�϶�ûԲ��ɢ�Ŀ� �������NO 

	�����´𰸣�˼·���ˣ�����Ҫע�����ﲻ�ÿ����������ʹ��ˣ�ֱ������벻�ÿ��� 
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
    ll t;
    cin >> t;
    while (t--) {
    	ll n;
    	cin>>n;
    	vector<vector<ll> > c(n,vector<ll> (2));
    	for(int i=0;i<n;i++){
    		cin>>c[i][0]>>c[i][1];
		}  //����û���� 
    	
    	ll xa,ya;
    	
		cin>>xa>>ya;
		ll xb,yb;
		cin>>xb>>yb; //����Ҳû���� 
		//������������� 
		ll ab=(xa-xb)*(xa-xb)+(ya-yb)*(ya-yb);  //���������С�� 
		bool check=0;
		for(int i=0;i<n;i++){ //�ж�ÿ��c��B�ľ����Ƿ�С��ab 
			ll xc,yc;
			xc=c[i][0];
			yc=c[i][1];
    		ll cb=(xc-xb)*(xc-xb)+(yc-yb)*(yc-yb);
    		if(cb<=ab){
    			cout<<"NO"<<endl;
    			check=1;
    			break;
			}
		}  
		if(check==0){
			cout<<"YES"<<endl;
		}
		
		
    }

    return 0;
}





