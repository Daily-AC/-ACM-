//考虑构造 1,1,2,3,4,…,n?2,1。这样，最长的回文子串长度为 3。
//首先第一个 1 和最后一个 1 放两边，中间随便加个数都行，这样的方案有 n?2 种；
//然后第二个 1 和最后一个 1 放两边，中间也可以随便加个，方案有 n?3 种，一共加起来就是
// g(a)=n?2+n?3=2n?5>n，可以通过。时间复杂度 O(n)。

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
