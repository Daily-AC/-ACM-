
//��Ŀ����n������ѡk����ӣ�ͳ�ƺ�Ϊ�������������
/*
    �����dfsѵ��
	�и����д�������ĺܺã���ţ�ƣ���ȫ���ҽ��������dfs
	����ȥ������
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

inline bool isprime(int x) { // �ж�һ�����Ƿ�������
	if (x == 1) return false; // ע���ⲽ�����Ǳ����
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
		return ;//ע��returnҪ��for�����棬��Ȼ�һ����е㲻���� 
	
}

int main() {
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; ++i)
		scanf("%d", &a[i]);
	dfs(0, 0, 1);
	printf("%d\n", ans);
	return 0;
}





