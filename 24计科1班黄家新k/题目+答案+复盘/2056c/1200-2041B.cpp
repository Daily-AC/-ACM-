//������Ǹ�������������һ�������⣬����ȫȫ���ҹ���Ȼ����ɱ 
//��Ŀ�� 

#include<bits/stdc++.h>	//�Ұ�����ͷ 
using namespace std;
#define int long long
int t;
int w,b;
double ans;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>t;
	while(t--){
		cin>>w>>b;
		ans=(-1+sqrt(1+8*(w+b)))/2.0;	//��� 
		cout<<floor(ans)<<endl;		
	}
	return 0;	//������� 
}
