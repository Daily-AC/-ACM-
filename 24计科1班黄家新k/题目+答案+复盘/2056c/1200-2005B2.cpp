//终于自己想出正确思路了
//记住，map里的二分函数lower_bound和正常lower_bound不一样，map的lower是大于等于参数
//没错，map的两个搜索函数都是大于参数的 
//题目：David在直线某个格子躲避 m 个老师追捕。
//      双方按最优策略移动。求被抓的最少行动次数（q 次询问）。 
/*
我的思路：
只需要看D的左右老师即可，其他老师都不用管，因为只有一条线 
所以只需要把每个老师都放入map里面，然后去找map里面最接近D的两个老师
这里用的是二分查找，可以直接找到D的左右两个老师
记得把左边没有老师和右边没有老师的情况分别列出来即可 

看了题解，思路是对的，但不知道哪里错了 
找到了，好像是最后计算步数的时候错了，D也要移动，而不是在原地，公式是 :
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
			//cout<<"第"<<i+1<<"次:"<<endl;
			auto Dbehind=M.lower_bound(D);//D的右边一个 
			
		  //begin()的地方就是第一个位置 
			if(Dbehind->first==D){
				cout<<0<<endl;
				continue;
			}
			auto Dfront=M.lower_bound(D);//
			if(Dfront!=M.begin())  Dfront--;//D的左边一个 
			else if(Dfront==M.begin()){//如果左边没有老师 
				cout<<Dbehind->first-1<<endl;
				continue;
			}
			if(Dbehind==M.end()){  //如果右边没有老师，直接输出 
				cout<<n-Dfront->first<<endl;
				continue;
			}
			//检查 
//			cout<<Dfront->first<<endl;
//			cout<<Dbehind->first<<endl;
			//如果左边，或者右边没有老师 ,只有一种可能，就是搜索后的值相等， 
			 
			
		ll minh=(Dbehind->first - Dfront->first) / 2;
			
			
			
			cout<<minh<<endl;
		}

    }

    return 0;
}





