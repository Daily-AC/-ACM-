//��Ŀ�� ��֪ l1��x��r1 , l2��y��r2 ��

//���ж��ٶ� (x,y) ���� y/x=k^n,n��0 ��

/*
	�ҵ�˼·��
		û���������ʽ�������
		
	��ȷ˼·���������룬����������x��y�ֿ���ֻ��һ������
				y/x=k^n  ->   x=y/(k^n)
		���ԣ�   l2/k^n <= x <= r2/k^n 
		
		��ô�ܼ򵥣�ö�� n ������ϲ���ʽ��l1<=x<=r1�Ľ��� 
	��̫����⣬�ҿ��������һ����û��������Լ�����˼·��ֱ�ӹ��� 
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
	while(T--) {
		ll k,l1,r1,l2,r2;
		cin>>k>>l1>>r1>>l2>>r2;
		ll m=1; 								
		ll ans=0;
//		cout<<"m*r1="<<m*r1<<"  l2="<<l2<<endl;
//		cout<<"r2="<<r2<<"   l1*m="<<l1*m<<endl;
//		cout<<"max(l1,(l2+m-1)/m)="<<max(l1,(l2+m-1)/m)<<endl;
//		cout<<"min(r1,r2/m)="<<min(r1,r2/m)<<endl;
		if(k==1){
			cout<<min(r1,r2/m) - max(l1,(l2+m-1)/m) + 1<<endl;
			continue;
			
		}
		
		
								//ע��Ҫ����ȡ�� (a+b-1)/b
		while(m<=r2){ //����˵��m���Դ���l2����Ϊx>=0������ġ������Ǹ�����ʽ l2/m<=x<=r2/m���ұ��ǲ���Ϊ0�İ�������m<r2 
			if(m*r1<l2 || l1*m>r2 || max(l1,(l2+m-1)/m) > min(r1,r2/m)){
				m*=k;     //����ǽ�������Ҫ����ģ�����������������Ի������ῴ�� 
				continue; 
			} 
			
			ans+= min(r1,r2/m) - max(l1,(l2+m-1)/m) + 1;  //�������±����Ҫ+1 
//			cout<<"m=="<<m<<endl;
//			cout<<"ans=="<<ans<<endl;
			m*=k;
		}
		cout<<ans<<endl;
	}

    return 0;
}
