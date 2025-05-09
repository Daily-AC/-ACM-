
//题目：从n个数中选k个相加，统计和为素数的组合数。
/*
    常规的dfs训练
	有个题解写的真的真的很好，很牛逼，完全给我讲懂了这个dfs
	可以去看看：
	https://www.luogu.com.cn/problem/solution/P1036 
	



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

inline bool isprime(int x) { // 判断一个数是否是素数
	if (x == 1) return false; // 注意这步特判是必需的
	for (int i = 2; i * i <= x; ++i)
		if (x % i == 0)
			return false;
	return true;
}
const int N = 25;
int a[N], ans, n, k;

void dfs(int now, int sum, int sid) {
	if(now==k){
		if(isprime(sum)) ++ans;
		return ;
	}
	
	for(int i=sid;i<=n-k+now+1;++i){
		dfs(now+1, sum + a[i],i+1);
	}   
		return ;//注意return要在for的外面，虽然我还是有点不熟练 
	
}

int main() {
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; ++i)
		scanf("%d", &a[i]);
	dfs(0, 0, 1);
	printf("%d\n", ans);
	return 0;
}





