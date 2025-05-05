
// 题目概括：
// 给定一个由小写字母组成的字符串，重新排列其字符，使得「好对」的数量最大化。
// 「好对」定义：
//   1. 首尾字符相同的对（i<j，s[i] == s[j]），直接属于好对；
//   2. 或为「愉快对」：存在k（i≤k<j），满足：
//      a. s[k] ≠ s[k+1]（相邻字符不等）；
//      b. s[k] ≠ s[i] 或 s[k+1] ≠ s[j]（至少一个相邻字符不等于首尾字符）。
//  


/*我的思路： 
	把相同的字母全部放在最后，比如 abcaa，变成bcaaa，有试过几个例子，发现是对的	
	 
	错误的地方：没有进行对比，比如说abcabc，和aabbcc，两个对比，会发现abcabc的答案更多
	所以导致错误，但是这里pair和sort的函数重载可以学一下，也就是这个cmp 
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
//			m[S[i]]++ ; //把每个字母的出现次数，先给map 
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
	所以正确思路是：尽量让相邻的字母不相同，没错，跟我的思路正好完全相反，所以不要太相信题目了
	有时候，题目会误导人。 
*/ 
// 核心策略：
// 首尾相同的对无需复杂条件，数量等于各字符出现次数的组合数（C(m,2)），是最容易最大化的部分。
// 因此，最优解是将出现次数最多的字符集中排列（连续放置），尽可能增加相同字符的组合数，
// 其他字符可随意排列在周围，不影响核心目标。
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

