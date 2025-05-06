
//题目：给几个半径为0的圆C，给一个起点A和终点B
//		圆以1的速度扩大，A以1的速度向着B前进，问：
//				A是否能在不碰到C的情况下到达B？ 


/*
我的思路：
	画几张图就能明白，其实就是看各个圆心到B的距离，和AB的长度，比大小
	如果圆心到B更短，说明A肯定没圆扩散的快 ，则输出NO 

	看了下答案，思路对了，但是要注意这里不用开根，开根就错了，直接求距离不用开根 
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
		}  //输入没问题 
    	
    	ll xa,ya;
    	
		cin>>xa>>ya;
		ll xb,yb;
		cin>>xb>>yb; //输入也没问题 
		//接下来计算距离 
		ll ab=(xa-xb)*(xa-xb)+(ya-yb)*(ya-yb);  //距离可能是小数 
		bool check=0;
		for(int i=0;i<n;i++){ //判断每个c和B的距离是否小于ab 
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





