
// ��Ŀ������
// ����һ����Сд��ĸ��ɵ��ַ����������������ַ���ʹ�á��öԡ���������󻯡�
// ���öԡ����壺
//   1. ��β�ַ���ͬ�Ķԣ�i<j��s[i] == s[j]����ֱ�����ںöԣ�
//   2. ��Ϊ�����ԡ�������k��i��k<j�������㣺
//      a. s[k] �� s[k+1]�������ַ����ȣ���
//      b. s[k] �� s[i] �� s[k+1] �� s[j]������һ�������ַ���������β�ַ�����
//  


/*�ҵ�˼·�� 
	����ͬ����ĸȫ��������󣬱��� abcaa�����bcaaa�����Թ��������ӣ������ǶԵ�	
	 
	����ĵط���û�н��жԱȣ�����˵abcabc����aabbcc�������Աȣ��ᷢ��abcabc�Ĵ𰸸���
	���Ե��´��󣬵�������pair��sort�ĺ������ؿ���ѧһ�£�Ҳ�������cmp 
*/
//#include <bits/stdc++.h>
//using namespace std;
//#define ll long long
//bool cmp(pair<char,ll>& a,pair<char,ll>& b){
//	return a.second<b.second;
//}
//
//int main()
//{
//    int t;cin >> t;
//    while (t--) {
//       ll n;
//	   cin>>n;
//	   string S;
//	   cin>>S;
//	   vector< pair<char,ll>> visited(n,pair<char,ll> (n,0) );
//	   map<char,ll> m;
//	   for(ll i=0;i<n;i++){
//			m[S[i]]++ ; //��ÿ����ĸ�ĳ��ִ������ȸ�map 
//	   } 
//       for(auto i: m){
//       		visited.push_back(i);
//	   } 
//        
// 		sort(visited.begin(),visited.end(),cmp);
// 		
// 		for(ll i=0;i<visited.size();i++){
// 			
// 			while(visited[i].second--){
// 				cout<<visited[i].first;
//			 }
//		 }
// 		cout<<endl;
// 		
//    }
//
//    return 0;
//}
/*
	������ȷ˼·�ǣ����������ڵ���ĸ����ͬ��û�����ҵ�˼·������ȫ�෴�����Բ�Ҫ̫������Ŀ��
	��ʱ����Ŀ�����ˡ� 
*/ 
// ���Ĳ��ԣ�
// ��β��ͬ�Ķ����踴���������������ڸ��ַ����ִ������������C(m,2)��������������󻯵Ĳ��֡�
// ��ˣ����Ž��ǽ����ִ��������ַ��������У��������ã���������������ͬ�ַ����������
// �����ַ���������������Χ����Ӱ�����Ŀ�ꡣ
#include<bits/stdc++.h>
#define ll long long
#define db double
#define inf 2e9
using namespace std;
int n,a[114514],ans,str[30],vis[30];
void solve()
{
	string s;
	cin>>n>>s;
	s=' '+s;
	for(int i=0;i<26;i++)
	{
		str[i]=0;
	}
	int ss=0;
	for(int i=1;i<=n;i++)
	{
		str[s[i]-'a']++;
		ss++;
	}
	vector<char>anss;
	while(ss)
	{
		for(int i=0;i<26;i++)
		{
			if(str[i]>0)
			{
				anss.push_back(i+'a');
				str[i]--;
				ss--;
			}
		}
	}
	for(auto u:anss)
	{
		cout<<u;
	}
	printf("\n");
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		solve();
	}
	return 0;
}

