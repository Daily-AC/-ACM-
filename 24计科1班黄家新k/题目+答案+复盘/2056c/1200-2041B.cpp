//这题更是个重量级，又是一个规律题，完完全全的找规律然后，秒杀 
//题目： 

#include<bits/stdc++.h>	//我爱万能头 
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
		ans=(-1+sqrt(1+8*(w+b)))/2.0;	//求解 
		cout<<floor(ans)<<endl;		
	}
	return 0;	//完结撒花 
}
