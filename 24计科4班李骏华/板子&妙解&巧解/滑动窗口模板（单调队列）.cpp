#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define N 1000005
//滑动窗口，双端（单调）队列记录下标， 
//洛谷P1886 
//所谓单调队列，及时刻保持递增OR递减，本题可按照单调来理解对队列q的操作 
int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
	}
	deque<int>q; 
	for(int i=0;i<n;i++)
	{
		while(!q.empty() && a[q.back()] > a[i]) q.pop_back(); //如果a[i](下一个入队元素)小于前面的数
		q.push_back(i);										  //则前面的数不可能是最小的
		if(i+1>=m)
		{
			while(!q.empty() && q.front() <= i-m) q.pop_front();
			cout << a[q.front()] << " ";
		}
	} 
	cout << endl;
	while(!q.empty()) q.pop_back();
	for(int i=0;i<n;i++)
	{
		while(!q.empty() && a[q.back()] < a[i]) q.pop_back();
		q.push_back(i);
		if(i+1>=m)
		{
			while(!q.empty() && q.front() <=i-m) q.pop_front();
			cout << a[q.front()]<< " ";
		}
	}
    return 0;
}
