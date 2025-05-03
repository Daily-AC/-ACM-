//题目：n 盏灯初亮，每次改 i 的倍数的灯状态，求亮 k 盏时，最小灯泡数 n 
//此题需要前置知识： 引理：在 1,2,3,....,n中一共有√n个完全平方数。

//当然，也可以找规律，当你找到第16个数的时候，就会发现，它的分布是0110111101111110
//也就是刚好在第4,9,16的地方是0，其他地方全为1，到这了你还没想到就是笨了
//那肯定是只有完全平方的数为0，其他数都为1啊，所以要找的就是非完全平方数。3，6这种 
//根据上面那个引理，也就是求n- √n
//接下来就二分查找那个大于n- √n的第一个值就行，非常常规的一个二分思路
//也不需要你搞什么特别复杂的数学推理，直接查找即可 
#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
  	ll t;
  	cin>>t;
  	while(t--){
  		ll k;
  		cin>>k;
  		//要找的n其实就是设为mid，二分嘛，正常 
  		ll l=1;
  		ll r=2*k;
  		
  		while(r-l>1){
  			ll mid=(r+l)>>1;
  			if(mid-(int)sqrt(mid)<k) l=mid;
  			else r=mid;
		  }
  		cout<<r<<endl;
	  }
	  
	    

    return 0;
}
