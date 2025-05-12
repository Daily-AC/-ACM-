//题目： 已知 l1≤x≤r1 , l2≤y≤r2 。

//求有多少对 (x,y) 满足 y/x=k^n,n≥0 。

/*
	我的思路：
		没想出来，公式化简错了
		
	正确思路：变量分离，把两个变量x和y分开，只找一个变量
				y/x=k^n  ->   x=y/(k^n)
		所以：   l2/k^n <= x <= r2/k^n 
		
		那么很简单，枚举 n ，求出上不等式与l1<=x<=r1的交集 
	别太信题解，我看题解想了一整天没想出来，自己根据思路，直接过了 
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
		
		
								//注意要向上取整 (a+b-1)/b
		while(m<=r2){ //就是说，m可以大于l2，因为x>=0是允许的。但是那个不等式 l2/m<=x<=r2/m，右边是不能为0的啊，所以m<r2 
			if(m*r1<l2 || l1*m>r2 || max(l1,(l2+m-1)/m) > min(r1,r2/m)){
				m*=k;     //这个是交集必须要满足的，不满足就跳出，可以画个数轴看看 
				continue; 
			} 
			
			ans+= min(r1,r2/m) - max(l1,(l2+m-1)/m) + 1;  //别忘了下标相减要+1 
//			cout<<"m=="<<m<<endl;
//			cout<<"ans=="<<ans<<endl;
			m*=k;
		}
		cout<<ans<<endl;
	}

    return 0;
}
