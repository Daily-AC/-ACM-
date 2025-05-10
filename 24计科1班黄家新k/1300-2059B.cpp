//题目：https://www.luogu.com.cn/problem/CF2059B
/*
	我的思路：，没想出来
	
	 
题解：
	如果 k=n，那么每一个子数组的长度都是 1，且位置固定，直接模拟即可。 
	如果 k！=n，那么第二段开头的位置就有多个，（2～n-k+2）。
		结论：得让第二段的第一个数不等于 1 或第二段的第二个数不等于 2 
		比如说，1 1 1 1 ....后面不论是什么，我都可以选为1和111，然后取偶数的数组，111，此时答案就是1
			或者是1 2 2 2,我也可以取1和222，第二段的第一个数不是1，那么答案也是1 
		所以这个结论很重要，也很牛逼，我是真没想出来 

思考过程：研究第二段即可，你也不用看什么偶数段啊，什么后面的奇数段，第二段直接决定答案了
 	  	  所以就疯狂打表，看看第二段到底是怎么样个规律 
 	  	  最后把规律表示出来就行了，我是真没想出来第二段决定答案这个结论 
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long
signed main()
{
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
    int t;cin >> t;
    while (t--) {
        ll n,k; 
        cin >> n >> k;
        vector<ll> a(n+1);
        for(int i=1;i<=n;i++){
        	cin>>a[i];
		}
		if(n==k){
			int b=1;
			for(int i=2;;i+=2,++b){
				if(a[i]!=b){	
					cout<<b<<endl;
					break;
				}
			}
		}
		else{
			bool b=0;
			for(int i=2;i<=n-k+2;i++){
				if(a[i]!=1){
					b=1;
					cout<<1<<endl;
					break;
				}
			}	
			if(b==0)  cout<<2<<endl;
			
		}
    }

    return 0;
}
