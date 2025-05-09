#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define N 1000005
//�������ڣ�˫�ˣ����������м�¼�±꣬ 
//���P1886 
//��ν�������У���ʱ�̱��ֵ���OR�ݼ�������ɰ��յ��������Զ���q�Ĳ��� 
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
		while(!q.empty() && a[q.back()] > a[i]) q.pop_back(); //���a[i](��һ�����Ԫ��)С��ǰ�����
		q.push_back(i);										  //��ǰ���������������С��
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
