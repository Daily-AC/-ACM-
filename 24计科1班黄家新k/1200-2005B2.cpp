//�����Լ������ȷ˼·��
//��ס��map��Ķ��ֺ���lower_bound������lower_bound��һ����map��lower�Ǵ��ڵ��ڲ���
//û��map�����������������Ǵ��ڲ����� 
//��Ŀ��David��ֱ��ĳ�����Ӷ�� m ����ʦ׷����
//      ˫�������Ų����ƶ�����ץ�������ж�������q ��ѯ�ʣ��� 
/*
�ҵ�˼·��
ֻ��Ҫ��D��������ʦ���ɣ�������ʦ�����ùܣ���Ϊֻ��һ���� 
����ֻ��Ҫ��ÿ����ʦ������map���棬Ȼ��ȥ��map������ӽ�D��������ʦ
�����õ��Ƕ��ֲ��ң�����ֱ���ҵ�D������������ʦ
�ǵð����û����ʦ���ұ�û����ʦ������ֱ��г������� 

������⣬˼·�ǶԵģ�����֪��������� 
�ҵ��ˣ������������㲽����ʱ����ˣ�DҲҪ�ƶ�����������ԭ�أ���ʽ�� :
							(Dbehind->first - Dfront->first) / 2
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
    	
    	ll n,m,q;
    	cin>>n>>m>>q;
        map<ll,ll> M;
	    M.clear();
		ll x;
		for(ll i=0;i<m;i++){
			cin>>x;
			M[x]++;
		}
		ll D;
		for(ll i=0;i<q;i++){
			cin>>D;
			//cout<<"��"<<i+1<<"��:"<<endl;
			auto Dbehind=M.lower_bound(D);//D���ұ�һ�� 
			
		  //begin()�ĵط����ǵ�һ��λ�� 
			if(Dbehind->first==D){
				cout<<0<<endl;
				continue;
			}
			auto Dfront=M.lower_bound(D);//
			if(Dfront!=M.begin())  Dfront--;//D�����һ�� 
			else if(Dfront==M.begin()){//������û����ʦ 
				cout<<Dbehind->first-1<<endl;
				continue;
			}
			if(Dbehind==M.end()){  //����ұ�û����ʦ��ֱ����� 
				cout<<n-Dfront->first<<endl;
				continue;
			}
			//��� 
//			cout<<Dfront->first<<endl;
//			cout<<Dbehind->first<<endl;
			//�����ߣ������ұ�û����ʦ ,ֻ��һ�ֿ��ܣ������������ֵ��ȣ� 
			 
			
		ll minh=(Dbehind->first - Dfront->first) / 2;
			
			
			
			cout<<minh<<endl;
		}

    }

    return 0;
}





