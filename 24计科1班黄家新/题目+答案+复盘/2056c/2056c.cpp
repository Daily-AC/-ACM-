//���ǹ��� 1,1,2,3,4,��,n?2,1����������Ļ����Ӵ�����Ϊ 3��
//���ȵ�һ�� 1 �����һ�� 1 �����ߣ��м����Ӹ������У������ķ����� n?2 �֣�
//Ȼ��ڶ��� 1 �����һ�� 1 �����ߣ��м�Ҳ�������Ӹ��������� n?3 �֣�һ������������
// g(a)=n?2+n?3=2n?5>n������ͨ����ʱ�临�Ӷ� O(n)��

#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
  int t;cin>>t;
  while(t--){
      int n;cin>>n;
      vector<int> a(n);
      for(int i=0;i<n;i++){
      	if(i==0 || i==1 ||i==n-1){
      		a[i]=1;
		  }
		 else a[i]=a[i-1]+1;
	  }
  		
  		for(int i=0;i<n;i++){
      	cout<<a[i]<<" ";
	  }
	  cout<<endl;
}
  return 0;
}
